import sqlite3   #Module for connecting to the database (.db) file

'''
Database connection is achieved in 3 steps:
1. Connect to the database.
2. Make a cursor object to execute SQL commands using python
3. Query about data and commit changes if any using the .commit() function.
'''
mydb = sqlite3.connect("xyz.db")

cursor = mydb.cursor()

cursor.execute("""CREATE TABLE IF NOT EXISTS DATA(QUESTION TEXT,RESULT TEXT)""")

cursor.execute("""INSERT INTO DATA VALUES( "Enter your question" , "Enter your result" )""")

mydb.commit()           #This is very important otherwise your data will not be saved

try:
    self.cursor.execute(f'SELECT *FROM DATA WHERE QUESTION = "#Enter your parameter here" ')
except:
    print("Enter required parameter")

data = cursor.fetchall()
print(data)
