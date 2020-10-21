def binary_search_fun (arr, start, end, flag):
    
# check condition
    if end >= start:
        
        mid = start + (end- start)//2
        
      # If element is present at the middle of the inputted list
        if arr[mid] == flag:
            return mid 
        
      # If element is smaller than mid
        elif arr[mid] > flag:
            return binary_search_fun(arr, start, mid-1, flag)
        
      # Else the element greator than mid
        else:
            return binary_search_fun(arr, mid+1, end, flag)
        
     # Element is not found in the inputted list
    else:
        return -1

# User input a list,in order to search a flag element    
arr = list()
size=int(input("\nInput the size of list"))
for i in range(0,size):
    ele=int(input("Input element no. %d"%(i+1)))
    arr.append(ele)
print("The inputted list is = {}".format(arr))

# User input the element to be searched for
flag=int(input("Enter the element to be searched for :")) 

# function call
result=binary_search_fun(arr,0,size-1,flag)

if result != -1:
   print ("Element is present at index:{}".format(result+1))
else:
   print ("Element is not present in the inputted list")