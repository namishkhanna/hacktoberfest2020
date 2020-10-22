#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &nums, int low, int high){
    int pivot = nums[high];
    int pIndex = low;
    for(int i = low; i <= high; i++){
        if(nums[i] <= pivot){
            swap(nums[i], nums[pIndex]);
            if(i != high)
                pIndex++;
        }
    }
    return pIndex;
}

void quickSort(vector<int> &nums, int low, int high){
    if(low >= high)
        return;
    int pivot = findPivot(nums, low, high);
    quickSort(nums, low, pivot - 1);
    quickSort(nums, pivot + 1, high);
}


int main(){
    vector<int> nums = {5, -1, 0, 5, 8, 6};
    quickSort(nums, 0, nums.size() - 1);
    for(int i: nums)
        cout<<i<<" ";
    return 0;
}