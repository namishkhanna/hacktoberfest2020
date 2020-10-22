#import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

#download salary datset from kaggle
dataset=pd.read_csv('salary_new.csv')
dataset.dropna(inplace=True)
x=dataset.iloc[:,1:2].values
y=dataset.iloc[:,2:]

#feature scalling
from sklearn.preprocessing import StandardScaler
sc_x=StandardScaler()
sc_y=StandardScaler()
x=sc_x.fit_transform(x)
y=sc_y.fit_transform(y)

#fitting svr to dataset
from sklearn.svm import SVR
regressor=SVR(kernel='rbf')
regressor.fit(x,y)

#predicting a new result
y_pred=regressor.predict([[6.5]])
y_pred=sc_y.inverse_transform(y_pred)

#visualising the svr results
plt.scatter(x,y,color='red')
plt.plot(x,regressor.predict(x),color='blue')
plt.title('Truth or Bluff(SVR)')
plt.xlabel('Positiion Level')
plt.ylabel('Salary')
plt.show()
