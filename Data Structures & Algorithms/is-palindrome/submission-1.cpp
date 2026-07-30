class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left=0;
        int right=n-1;
        while(left<right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
