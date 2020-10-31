#include<bits/stdc++.h>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
// O(n)
void buildtree(int* arr,int* tree,int start, int end, int treenode){

    int mid=(start+end)/2;
    if(start==end){
        tree[treenode]=arr[start];
        return;
    }

    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);

    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);

}

// O(logn)
void updatetree(int* arr,int* tree,int start, int end,int treenode,int idx, int val){

    if(start==end){
        arr[idx]=val;
        tree[treenode]=val;
        return;
    }

    int mid=(start+end)/2;
    if(mid<idx){
        updatetree(arr,tree,mid+1,end,2*treenode+1,idx,val);
    }
    else{
        updatetree(arr,tree,start,mid,2*treenode,idx,val);
    }
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);

}

int query(int* tree,int start,int end,int treenode,int left, int right){

    // Completely outside given range
    if(start>right || end<left) return 100000;

    // Completely inside given range
    if(start>=left && end<=right) return tree[treenode];

    // Partially inside and outside

    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*treenode,left,right);
    int ans2=query(tree,mid+1,end,2*treenode+1,left,right);
    return min(ans1,ans2);

}

int main(){
    fast_io
    int n,t;
    cin >> n >> t;
    int arr[n];
    for(int i=0;i<n; i++) cin >> arr[i];
    int *tree=new int[4*n];
    buildtree(arr,tree,0,n-1,1);

    // for(int i=1;i<=9; i++){
    //     cout << tree[i] << endl;
    // }

   // updatetree(arr,tree,0,5,1,2,10);

    while(t--){
        char c;
        int a,b;
        cin >> c >> a >> b;
        a--,b--;
        if(c=='q'){
            cout << query(tree,0,n-1,1,a,b) << endl;
         
        }
        else{
            updatetree(arr,tree,0,n-1,1,a,b);
            
        }
    }
   // cout << query(tree,0,4,1,0,4) << endl;

}
