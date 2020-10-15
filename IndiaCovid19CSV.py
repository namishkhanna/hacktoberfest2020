import pandas as pd
df = pd.read_csv("https://api.covid19india.org/csv/latest/state_wise.csv")
print(df.loc[:,'State':'Active'])
df = df.loc[:,'State':'Active']
df = df[df.State != 'State Unassigned']
print(df)
df.to_csv("covid19.csv")		


