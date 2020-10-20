//computerwala

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits == null || digits.size() == 0){
            int[] temp = {1};
            return temp;
             
    }
    
    int carry = 1;
    int i;
    for(i=digits.size()-1; i>0;i--) {
        if(digits[i]=9){
            digits[i]=0;
        }
        else{
            carry+ = digits[i];
            digits[i] = carry;
            break;
        }
        if(i<0){
            int[] result = new int[digits.size()+1];
            result[0] = 1;
            return result;
            
        } else{
            return digits;
        }
    }
};
