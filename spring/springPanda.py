import pandas as pd
import numpy as np
import sys

filename = sys.argv[1]
selection = sys.argv[2]
run = pd.read_csv(filename, header=None)
run = (run.rename(columns={0:'Time',1:'Pos'})
         .assign(isPeak=False,
                 isPit=False,
                 isExt=False,
                 isDupe=False,
                 Period=0,
                 CalPos=0)
      )


pd.set_option('display.max_rows', None,
              'display.precision', 6)

def peri(davey):
    lasExt = 0
    for i in range(len(davey)):
        if (i + 1) < len(davey) and i > 0:
            if davey.at[i,'Pos'] >=  davey.at[(i-1),'Pos'] and davey.at[i,'Pos']  > davey.at[(i+1),'Pos'] :
                davey.at[i,'isPeak'] = True
                davey.at[i,'isExt'] = True
                if lasExt != 0:
                    davey.at[i,'Period'] = 2*(davey.at[i,'Time'] - lasExt)
                    lasExt = davey.at[i,'Time']
                else:
                    lasExt = davey.at[i,'Time']
                    
            if davey.at[i,'Pos'] <=  davey.at[(i-1),'Pos'] and davey.at[i,'Pos']  < davey.at[(i+1),'Pos'] :
                davey.at[i,'isPit'] = True
                davey.at[i,'isExt'] = True
                if lasExt != 0:
                    davey.at[i,'Period'] = 2*( davey.at[i,'Time'] - lasExt)
                    lasExt = davey.at[i,'Time']
                else:
                    lasExt = davey.at[i,'Time']
            if davey.at[i,'Pos'] ==  davey.at[(i-1),'Pos'] or davey.at[i,'Pos'] == davey.at[(i+1),'Pos'] :
                davey.at[i,'isDupe'] = True
    jsext = davey[davey.Period >0]
    MeanPos = jsext.mean()
    Calcoe = MeanPos['Pos']
    davey['CalPos'] = davey['Pos'] - Calcoe    
    return davey

#print("Mean Period: " + str(round(Calcoe,4)))
def absdif(num1, num2):
    return abs(abs(num1) - abs(num2))

def tperiod(mass,k):
    return round((2 * math.pi * math.sqrt(mass /k )),6)

def out(int):
    wave=peri(run)
    jsext = wave[wave.Period >0]
    if (len(jsext)%2) == 1:
        jsext = jsext.drop(jsext.index[0], axis=0,inplace=False )
    MeanSel = jsext.mean()
    match int:
        case 1:
            wave[['Time','Pos','Period', 'CalPos']].to_csv('compr.csv',index=False)
            
            print(wave)
        case 2:
            #jsext = jsext[['Time','Pos']]
            #print(jsext[['Time','Pos','isDupe', 'Period','CalPos']])
            jsext[['Time','Pos','isDupe','Period','CalPos']].to_csv('abrev.csv',index=False)
            print(jsext)
        case 3:
            print("average Period: " + str( round(MeanSel['Period'], 3)) )
        case 4:
            Ampy = (abs(jsext.iat[0,7])+ abs(jsext.iat[1,7]) )/2
            print("Amplitude(m): " + str( round(Ampy,3)) )
        case 5:
            print("Position Calibration Coef(m): " + str( round(MeanSel['Pos'], 3)) )
        case 6:
            jjsext = jsext[jsext.CalPos > 0]
            Ampy = (abs(jsext.iat[0,7])+ abs(jsext.iat[1,7]) )/2
            x = jjsext['Time'].to_numpy()
            y = jjsext['CalPos'].to_numpy()
            fit = np.polyfit(x, (Ampy *np.log(y)), 1)
            print(str(fit[0])+ 'x')
            print(np.e)
            print(fit[1])

out(int(selection))
