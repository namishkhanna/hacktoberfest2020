import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split #split data into two sets (training | testing)
from sklearn.metrics import accuracy_score #for check the accracy

music_data = pd.read_csv('music.csv')
X = music_data.drop(columns=['genre']) # drop genre column
y = music_data['genre']
X_train , X_test, y_train, y_test = train_test_split(X,y,test_size = 0.2)


model = DecisionTreeClassifier()
model.fit(X_train,y_train)
predictions = model.predict(X_test)


score = accuracy_score(y_test,predictions)
score
