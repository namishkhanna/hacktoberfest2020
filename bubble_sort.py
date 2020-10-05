def bubble_sort(list1):    
    for i in range(0,len(list1)-1):  
        for j in range(len(list1)-1):  
            if(list1[j]>list1[j+1]):  
                temp = list1[j]  
                list1[j] = list1[j+1]  
                list1[j+1] = temp  
    return list1  
  
list1 = [324, 454, 56, 45, 98, 23]  
print("The unsorted list is: ", list1)  
print("The sorted list is: ", bubble_sort(list1)) 
