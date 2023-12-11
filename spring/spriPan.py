import pandas as pd
import sys

filename = sys.argv[1]
selection = sys.argv[2]
run = pd.read_csv(filename, header=None)

revl = run[run.Period >]

print(run[

print(run)
