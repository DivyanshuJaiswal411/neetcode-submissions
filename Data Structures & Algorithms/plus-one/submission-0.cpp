class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        int idx=n-1;
        while(idx>=0){
            if(carry==0) break;
            digits[idx]+=1;
            carry=digits[idx]/10;
            digits[idx]%=10;
            idx--;
        }
        if(carry) digits.insert(digits.begin(),carry);
        return digits;
    }
};
