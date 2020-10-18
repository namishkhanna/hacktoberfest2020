x=int(input("enter a number: "))
s=0
while(x):
    a=x%10
    s+=a
    x//=10
print(s)
