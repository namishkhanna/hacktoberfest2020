def interpolationSearch(array, n, x): 
	low = 0
	high = (n - 1) 

	while low <= high and x >= array[low] and x <= array[high]: 
		if low == high: 
			if array[low] == x: 
				return lo; 
			return -1; 
		
		pos = low + int(((float(high - low) /
			( array[high] - array[low])) * ( x - array[low]))) 

		if array[pos] == x: 
			return pos 

		if array[pos] < x: 
			low = pos + 1; 

		else: 
			high = pos - 1; 

	return -1

array = []
while 1:
    try:
        x = input("Enter a number for the sorted list (To exit write something tha is not a number): ")
    except:
        break
    array.append(x)

y = input("Enter the number you want to find: ")
index = interpolationSearch(array, len(array), y) 

if index != -1: 
	print "Element found at index",index 
else: 
	print "Element not found"