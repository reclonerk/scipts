import pandas as pd
import numpy as np

url = 'data.csv'
df = pd.read_csv(url)
print(df)

df = df.sample(n = 16)
df.to_csv('result.csv', index = False)

