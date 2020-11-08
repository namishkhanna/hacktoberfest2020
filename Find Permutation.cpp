vector<int> Solution::findPerm(const string A, int B) {
    vector<int> res;
    for(int i=0;i<B;i++){
        res.push_back(i+1);
    }
    int r=1;
    int c=A.size();
    while(r==1){
        r=-1;
        for(int i=0;i<c;i++){
            if(A[i]=='D'&&res[i+1]>res[i]){
                swap(res[i],res[i+1]);
                r=1;
            
            }
        }
    }
    return res;
}
