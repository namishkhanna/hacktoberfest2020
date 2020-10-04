# A simple program to print a octagon
# Here we will assumed user input as spaces
# between each asterisk

# This is a user defined function
# That has one parameter
# It will take user input as an argument
def octagon(n):
  k = 2 * n - 2
  x = 2 * n
  y = n + (x + 1)
  z = x + 1

# It is our first loop (for)
# For beginning part
  for i in range(n,x + 1):
  
    for j in range(0,k):
      print(end =" ")
      
    k = k - 1
    
    for j in range(0,i + 1):
      print("* ",end="")
      
    print("\r")
    
# It is our second loop (while)
# For middle part
  while z < (y - 1):
    
    k = n - 2
    
    for j in range(0,k):
      print(end = " ")
      
    for j in range(0,i + 1):
      print("* ",end = "")
      
    z = z + 1
    print("\r")
    
# It is our third loop (for)
# For bottom part
  for i in range(x,n - 1,-1):
    
    for j in range(k,0,-1):
      print(end=" ")
    k = k + 1
    
    for j in range(0,i + 1):
      print("* ",end = "")
    
    print("\r")
    
print("It is a program for printing a octagon")
print("\nWe assume your input as space")
print("between each asterisk\n")
print("Please enter a Input that is greater")
print("than 1\n")

while True:
  try:
    a = int(input("Enter a Integer : "))
    print("\n")
  
    if a < 2:
      print("Enter a Integer greater than 1")
    else:
      octagon(a)
      print("\n")
  except:
    print("\nIt's not a valid Integer !")
