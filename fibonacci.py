a=0
b=1
n=int(input("enter the number of terms: "))
for i in range(n):
    print(a)
    c=a
    a=b
    b=b+c
