import pandas as pd
# data = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\diabetes.csv")
data = pd.read_csv(r"E:\github repository\Lab-Notes\mllab\Datasets\ML Lab Sauce\Datasets\cardata.csv")
print(data)

from pandas import DataFrame

cars = {'Brand': ['Honda Civic', 'Toyota Crolla', 'Ford Focus', 'Audi A4'],
        'Price': [32000, 35000, 37000, 45000]
        }
df = DataFrame(cars, columns=['Brand', 'Price'])
df.to_excel(r"E:\github repository\Lab-Notes\mllab\task1\exp.xlsx", index=None, header=True)
