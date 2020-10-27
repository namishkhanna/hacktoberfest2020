def traverse_array_start_to_end(arr,beg,end):
    if(end<beg):
        return 0
    else:
        create(arr,beg,end-1)
        print(arr[end])
        
def traverse_array_end_to_start(arr,beg,end):
    if(end<beg):
        return 0
    else:
        print(arr[end])
        create(arr,beg,end-1)
        
def check_even_odd_in_loop(arr,beg,end):
    if(end<beg):
        return 0
    else:
        create(arr,beg,end-1)
        if(arr[end]%2==0):
            print("Index ",end," is even ",arr[end])
        else:
            print("Index ",end," is odd ",arr[end])
            
def array_sum(arr,beg,end):
    if(end<beg):
        return 0
    else:
        return array_sum(arr,beg,end-1) + arr[end]


def sum_sub_array(arr,beg,end,ans):
    if(end==beg):
        ans.append(arr[beg])
        return
    else:
        sum_sub_array(arr,beg,end-1,ans)
        ans.append(array_sum(arr,beg,end))
        
        
def tower_of_henoi(n,start,end,via):
    if(n==1):
        print("Move Disk ",n," From ",start," To ",end)
    else:
        tower_of_henoi(n-1,start,via,end)
        print("Move Disk ",n," From ",start," To ",end)
        tower_of_henoi(n-1,via,end,start)
tower_of_henoi(20,"A","C","B")
