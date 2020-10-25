import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
#import matplotlib.pyplot as plt

#download dataset from kaggle
df = pd.read_csv('wine.csv')


X = df[['quality']]
y = df[['fixed acidity','volatile acidity','citric acid','residual sugar','chlorides','free sulfur dioxide','total sulfur dioxide','density','pH','sulphates','alcohol']]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2,random_state=0)

model = PolynomialFeatures(degree= 4)
y_ = model.fit_transform(y_train)
y_test_ = model.fit_transform(y_test)

lg = LinearRegression()
lg.fit(y_,X_train)
predicted_data = lg.predict(y_test_)
predicted_data = np.round_(predicted_data)
print (mean_squared_error(X_test,predicted_data))
