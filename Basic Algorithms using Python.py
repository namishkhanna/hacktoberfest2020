# Binary Search

def binarySearch(num,arr):
    beg = 0
    end = len(arr)-1
    while(beg<=end):
        mid = (beg+end)//2
        if(arr[mid]==num):
            return mid 
        elif(arr[mid]>num):
            end = mid - 1
        else:
            beg = mid + 1
    return -1
    
#Binary Search Using Recursion

def binarySearch(num,arr,beg,end):
    if(beg>end):
        print("NOT FOUND")
        return
    mid = (beg + end)//2
    if(arr[mid]==num):
        print("FOUND AT ",mid)
    elif(arr[mid]>num):
        binarySearch(num,arr,beg,mid-1)
    else:
        binarySearch(num,arr,mid+1,end)


# Bubble Sort

def bubbleSort(arr):
    for i in range(0,len(arr)-1):
        for j in range(0,len(arr)-i-1):
            if(arr[j+1]<arr[j]):
                (arr[j],arr[j+1])=(arr[j+1],arr[j])

arr=[5,1,4,2,8,9]
bubbleSort(arr)
print(arr)


#insetion sort

def insertionSort(arr):
    for i in range(1,len(arr)):
        pos = i
        while(pos>0 and arr[pos-1]>arr[pos]):
            (arr[pos-1],arr[pos])=(arr[pos],arr[pos-1])
            pos=pos-1
arr=[5,1,4,2,8,9]
insertionSort(arr)
print(arr)


# Selection Sort

def selectionSort(arr):
    for i in range(len(arr)):
        minpos = i
        for j in range(i,len(arr)):
            if(arr[j]<arr[minpos]):
                minpos=j
        (arr[i],arr[minpos])=(arr[minpos],arr[i])

arr=[5,1,4,2,8,9]
selectionSort(arr)
print(arr)


#Quick Sort Choosing Pivot as the Last Element

def partition(arr,low,high):
    i = low - 1
    pivot = arr[high]
    for j in range(low,high):
        if(arr[j]<=pivot):
            i=i+1
            (arr[i],arr[j])=(arr[j],arr[i])
    (arr[i+1],arr[high])=(arr[high],arr[i+1])
    return i+1
def quickSort(arr,low,high):
    if(low<high):
        part = partition(arr,low,high)
        quickSort(arr,low,part-1)
        quickSort(arr,part+1,high)
arr=[2,1,3,4,4,0,9]
quickSort(arr,0,len(arr)-1)
print(arr)



# QuickSort 

def quickSort(arr,low,high):
    if(low<high):
        i=low
        j=low+1
        while(j<=high):
            if(arr[j]<=arr[low]):
                i=i+1
                (arr[j],arr[i])=(arr[i],arr[j])
            j=j+1
        (arr[i],arr[low])=(arr[low],arr[i])
        part = i
        quickSort(arr,low,part-1)
        quickSort(arr,part+1,high)
arr=[2,1,3,4,4,0,9,-2,-1]
quickSort(arr,0,len(arr)-1)
print(arr)


#Quick Sort Choosing Pivot as the Last Element

def partition(arr,low,high):
    i=low
    j=low+1
    while(j<=high):
        if(arr[j]<=arr[low]):
            i=i+1
            (arr[j],arr[i])=(arr[i],arr[j])
        j=j+1
    (arr[i],arr[low])=(arr[low],arr[i])
    return i   
def quickSort(arr,low,high):
    if(low<high):
        part = partition(arr,low,high)
        quickSort(arr,low,part-1)
        quickSort(arr,part+1,high)
arr=[2,1,3,4,4,0,9]
quickSort(arr,0,len(arr)-1)
print(arr)


#Merge Sort

def merge(arr,beg,mid,end):
    i=beg
    j=mid+1
    temp = []
    while(i<=mid and j<=end):
        if(arr[i]>=arr[j]):
            temp.append(arr[j])
            j=j+1
        if(arr[j]>arr[i]):
            temp.append(arr[i])
            i=i+1
    if(i>mid):
        while(j<=end):
            temp.append(arr[j])
            j=j+1
    if(j>end):
        while(i<=mid):
            temp.append(arr[i])
            i=i+1
    k=0
    for i in range(beg,end+1):
        arr[i] = temp[k]
        k=k+1
def mergesort(arr,beg,end): 
    if(beg<end):
        mid = (beg+end)//2
        mergesort(arr,beg,mid)
        mergesort(arr,mid+1,end)
        merge(arr,beg,mid,end)
        
arr=[2,1,3,4,4,0,9]
mergesort(arr,0,len(arr)-1)
print(arr)


# BFS

def bfs(arr,start):
    visited = []
    parent=[]
    q=[]
    for i in range(len(arr)):
        visited.append(start)
        visited[start]=1 
        parent.append(-1)
    q.append(start)
    while(len(q)!=0):
        j = q.pop(0)
        print(j," -->")
        for k in range(len(arr[j])):
            if(visited[arr[j][k]]==0):
                visited[arr[j][k]]=1
                parent[arr[j][k]]=j
                q.append(arr[j][k])


# DFS

n=int(input("Enter Number of Nodes :"))
arr=[]
for i in range(n):
    l=[int(x) for x in input().split()]
    arr.append(l)
visited = [0]*n
parent = [-1]*n
def dfs(start):
    visited[start] = 1
    print(start)
    for i in range(len(arr[start])):
        if(visited[arr[start][i]]==0):
            parent[arr[start][i]] = start
            dfs(arr[start][i])
dfs(0)

