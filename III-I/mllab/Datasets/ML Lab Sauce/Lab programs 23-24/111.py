import pandas as pd
data=pd.read_csv('C:/Users/sunil/cardata.csv'),names=['buying','maint','persons','lug_boot','safety','class']) 
print(data)
from pandas import DataFrame
Cars = {'Brand': ['Honda ','Toyota ','Ford Focus',], 'Price': [335000,37000,45000]
}
df = DataFrame(Cars, columns= ['Brand', 'Price'])
export_excel = df.to_excel ('C:/Users/sunil/export_dataframe.xlsx', index = None, header=True)


