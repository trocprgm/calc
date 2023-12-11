import math
import csv
import numpy as np


def run(int):
    match int:
        case 1:
            return np.loadtxt("Run1.csv", delimiter=',')
        case 2:
            return np.loadtxt("Run2.csv", delimiter=',')
        case 3:
            return np.loadtxt("Run3.csv", delimiter=',')
        case 4:
            return np.loadtxt("Run4.csv", delimiter=',')
        case 5:
            return np.loadtxt("Run5.csv", delimiter=',')


def peri(davey):
    peakTimes = []
    for i in range(len(davey)):
        if (i + 1) < len(davey):
            if davey[i][1] >= davey[i-1][1] and davey[i][1] > davey[i+1][1]:
                peakTimes.append([i,davey[i][0]] )
    return peakTimes

def periods(peakTimes):
    periods = []
    for i in range(len(peakTimes)):
        if i > 0:
            periods.append([peakTimes[i][0],peakTimes[i][1],round((peakTimes[i][1]-peakTimes[i-1][1]),6)])
    return periods

def perfper(davey):
    peakTimes = []
    for i in range(len(davey)):
        if (i + 2) < len(davey) and i > 0:
            if davey[i][1] > davey[i-1][1] and davey[i][1] > davey[i+1][1]:
                peakTimes.append([i,davey[i][0]] )
            if davey[i][1] == davey[i+1][1] and davey[i][1] > davey[i-1][1] and davey[i][1] > davey[i+2][1]:
                peakTimes.append([ (i +0.5), ((davey[i][0]) + davey[i+1][0])/2]) 
    
    return peakTimes
                

def perfperdf(davey):
    peakTimes = []
    for i in range(len(davey)):
        if (i + 2) < len(davey) and i > 0:
            if davey[i][1] > davey[i-1][1] and davey[i][1] > davey[i+1][1]:
                peakTimes.append([i,davey[i][0]] )
            if davey[i][1] == davey[i+1][1] and davey[i][1] > davey[i-1][1] and davey[i][1] > davey[i+2][1]:
                peakTimes.append([ (i +0.5), ((davey[i][0]) + davey[i+1][0])/2]) 
    
    return peakTimes

def poscor(dave):
    times = peri(dave)
    corv = 0
    for i in range(len(times)):
        if i > 0:
            negind =round( times[i][0] - (( times[i][0] - times[i-1][0] )/2))
            midpo = (( dave[times[i][0]][1] + dave[negind][1] )/ 2)
            corv += midpo
    corv = round(corv /(len(times)-1),5)
    corec = []
    for i in range(len(dave)):
        corec.append([ (dave[i][0]),round( (dave[i][1]- corv ),5)   ])
    return corv

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

#runtot = 0
#for i in periods(perfper(run(1))): runtot += i[2]
#runtot = (runtot)/(len(periods(peri(run(1)))))
#print(round(runtot,6))
#print(tperiod(0.5,24.5) )
#runtot = 0
#for i in periods(peri(run(1))): runtot += i[2]
#runtot = runtot/len(periods(peri(run(1))))
#print(runtot)
#
#for i in (periods(peri(run(1)))): print(i)
#print(np.average((periods(peri(run(1)))), axis=1))
