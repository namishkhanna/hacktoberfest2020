print("Enter number of Rows: ")
n = int(input())
for i in range(0, n): 
    for j in range(0, i+1): 
        print("*",end="") 
    print("\r") 
