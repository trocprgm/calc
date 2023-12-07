import pandas as pd
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




mass = 0
delx1 = 1
delx2 = 0
deff1 = 0
deff2 = 0
k = abs( absdif(deff1,deff2) / absdif(delx1,delx2))

def out(int):
    wave=peri(run)
    jsext = wave[wave.Period >0]
    MeanSel = jsext.mean()
    match int:
        case 1:
            print(wave)
        case 2:
            print(jsext[['Time','Pos','isDupe', 'Period','CalPos']])
        case 3:
            print(MeanSel[['Time','Pos','Period']])

out(int(selection))
