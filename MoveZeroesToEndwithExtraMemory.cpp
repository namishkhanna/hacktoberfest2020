#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int arr[N],count=0,res[N],k=0;
    for(int i=0;i<N;i++){
        cout<<"Enter element :";
        cin>>arr[i];
        if(arr[i]==0){
            count++;
        }
        else{
            res[k]=arr[i];
            k++;
        }
    }
    for(int i=0;i<count;i++){
        res[k]=0;
        k++;
    }
    cout<<"Final Array: "<<endl;
    for(int i=0;i<N;i++){
        arr[i]=res[i];
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
