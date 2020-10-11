#Python Implementation of bubble Sort Algorithm

#ascending Order Sort
def bubble(data):
	n=len(data)
	for i in range(n-1):
		for j in range(i+1,n):
			if data[i]>data[j]:
				temp=data[j]
				data[j]=data[i]
				data[i]=temp

temperature = input('Enter the list of numbers: ').split()
temperature = [int(x) for x in alist]
print("Data Before Sort")
print(temperature)

bubble(temperature)
print("Data After Sort")
print(temperature)