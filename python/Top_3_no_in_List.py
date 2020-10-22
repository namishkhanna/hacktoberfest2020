a = int(input("Enter Total Entries:"))
b=[]
for i in range(a):
    b.append(int(input("Enter No:")))

print("Top 3 Numbers is :",sorted(b, reverse=True)[:3])
