n=int(input('Enter range:'))
n1=2
while n1<=n:
    a=True
    for i in range(2,n1//2+1):
        if n1%i==0:
            a=False
            break
    if a==True:
        print(n1,end=' ')
    n1=n1+1
