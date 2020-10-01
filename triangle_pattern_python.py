#2 in 1 triangle pattern

#1. in this we print a simple triangle
n = int(input('Enter the number of row: '))
for i in range(0,n):    #rows
    for j in range(0, n-i): #for space
        print(end=" ")

    for j in range(0,i+1):  #number of star to be print in rows
        print('*', end=" ")
    print()

#2. Pyramid pattern after 180 degree rotation
#It is same as above except

n = int(input('Enter the number of row: '))
for i in range(0,n):    
    for j in range(0, n-i): 
        print(end=" ")

    for j in range(0,i+1):  
        print('*', end="") #change is here just remove from end (i.e end="")
    print()
