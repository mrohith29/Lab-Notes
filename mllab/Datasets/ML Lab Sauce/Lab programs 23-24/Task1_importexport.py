import pandas as pd 
data =pd.read_csv('C:\\Users\\HP\\Desktop\\ML DATA 2022-23\\Datasets\\cardata.csv', names=['buying','maint','doors','persons','lug_boot','safety','class']) 
print(data)

#Exporting Data
from pandas import DataFrame
Cars = {'Brand': ['Honda Civic','Toyota Corolla','Ford Focus','Audi A4'], 
        'Price': [32000,35000,37000,45000],
        'color':['Red','Green','Blue','White']
        }
df = DataFrame(Cars,columns=['Brand','Price'])
export_csv = df.to_csv('C:\\Users\\HP\\Desktop\\ML DATA 2022-23\\export_dataframe.csv', index=None, header=True)
  #Don't forget to add '.xlsx' at the end of the path
