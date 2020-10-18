
a = int(input("please enter a natural number: "))
i = 1
n = 0
while i <= a:                                      
    if a%i==0:
        n+=1
        
    i=i+1
if n==2:
    print("prime")
else:
    print("composite")
