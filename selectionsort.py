#implementation of selection sort
#Algorithm using Python List
def selection_sort(data):
	n=len(data)
	for i in range(n-1):
		smallindex=i
		for j in range(i+1,n):
			if data[j]<data[smallindex]:
				smallindex=j
		if smallindex!=i:
			temp=data[i]
			data[i]=data[smallindex]
			data[smallindex]=temp
		
#calling selection sort
mark = input('Enter the list of numbers: ').split()
mark = [int(x) for x in alist]
print("Data Before Sort")
print(mark)
selection_sort(mark)
print("Data After Sort")
print(mark)