z=int(input("enter the number upto which you want to find if a number is prime or not: "))
a=1
y=0
while a<=z:
    i=1
    n=0
    while i <= a:
        if a%i==0:
            n=n+1        
        
        i=i+1
    if n==2:
        y=y+1
        print(a,"is prime")
    else:
        print(a,"is composite")
    a=a+1
print("the total number of prime numbers under",z,"are",y)







