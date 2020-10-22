def selection_sort(lst):

    for index in range(len(lst)):

        min_index = index
        for j in range( index +1, len(lst)):
            if lst[min_index] > lst[j]:
                min_index = j


        lst[index], lst[min_index] = lst[min_index], lst[index]


l = [119,12,321,645,130,121,421,127]

print("Unsorted list ", l)

selection_sort(l)

print("Sorted list : ",l)
