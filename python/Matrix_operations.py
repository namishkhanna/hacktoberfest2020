#Python program for matrix operations- addition and multiplication

matrix = []

No_of_rows = int(input("Enter the number of rows: "))
No_of_Columns = int(input("Enter the number of Columns: "))

for i in range(No_of_rows):
    matrix.append([])
    for j in range(No_of_Columns):
        value = int(input("Enter the element: "))
        matrix[i].append(value)

print("The 2D matrix is: ", matrix)

print("MATRIX 1")
for i in range(No_of_rows):
    for j in range(No_of_Columns):
        print(matrix[i][j], end=" ") #new line
    print()

matrix2 = []

No_of_rows = int(input("Enter the number of rows: "))
No_of_Columns = int(input("Enter the number of Columns: "))

for i in range(No_of_rows):
    matrix2.append([])
    for j in range(No_of_Columns):
        value = int(input("Enter the element: "))
        matrix2[i].append(value)

print("The 2D matrix is: ", matrix2)

print("MATRIX 2")
for i in range(No_of_rows):
    for j in range(No_of_Columns):
        print(matrix2[i][j], end=" ") #new line
    print()

#To Add M1 and M2 matrices
result = [[0,0,0], [0,0,0], [0,0,0]]
for i in range(len(matrix)):
    for k in range(len(matrix2)):
        result[i][k] = matrix[i][k] + matrix2[i][k]

#To Print the matrix
print("The sum of Matrix M1 and M2 = ", result)
print("RESULTANT ADDITION")
for i in range(No_of_rows):
    for j in range(No_of_Columns):
        print(result[i][j], end=" ") #new line
    print()


#To Multiply M1 and M2 matrices
for i in range(len(matrix)):
    for k in range(len(matrix2)):
        result[i][k] = matrix[i][k] * matrix2[i][k]

#To Print the matrix
print("The multiplication of Matrix M1 and M2 = ", result)
print("RESULTANT MULTIPLICATION")
for i in range(No_of_rows):
    for j in range(No_of_Columns):
        print(result[i][j], end=" ") #new line
    print()
