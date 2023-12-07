import math
import csv
import pandas as pd



def run(int):
    match int:
        case 1:
            run = pd.read_csv("Run1.csv", header=None)
        case 2:
            run = pd.read_csv("Run2.csv", header=None)
        case 3:
            run = pd.read_csv("Run3.csv", header=None)
        case 4:
            run = pd.read_csv("Run4.csv", header=None)
        case 5:
            run = pd.read_csv("Run5.csv", header=None)
    return (run.rename(columns={0:'Time',1:'Pos'})
               .assign(isPeak=False,
                       isPit=False,
                       isExt=False,
                       isDupe=False,
                       Period=0,
                       CalPos=0)
            )

wave = run(4)
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
    jsext = wave[wave.Period >0]
    MeanPos = jsext.mean()
    Calcoe = MeanPos['Pos']
    #print(davey.append(Caos=davey['Pos']-Calcoe))
    davey['CalPos'] = davey['Pos'] - Calcoe    
    #ip = 0            
    #for i in wave.index[wave['isExt']]:
    #    ind = wave.index[wave['isExt']]
    #    ind.reindex
    #    davey.at[i,'Period'] = 2 * (davey.at[i,'Time'] - ip)
    #    ip += 1

    return davey

wave=peri(wave)

print(wave)










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

