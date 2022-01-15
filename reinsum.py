import numpy as np

print(np.sin(0))

def theFunction(x):
    return np.sin(x)

slices = 1000
a = 0
b = np.pi
dx = (b - a)/slices
print("A val is {}, B val is {}, slices count is {}, dx is {}".format(a, b, slices, dx))
#"runningLine" is a theoretical line created by adding every height of the function that we are taking
runningLine = 0

#here is the implementation of "runningLine"
for slice in range(slices + 1):
    runningLine += (theFunction(slice*dx))

#running line 
print(runningLine)

#we find out definite integral by multiplying the running line by dx
print(runningLine * dx)
