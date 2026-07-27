class Solution {
public:
    int helper(int left,int right,int n,string s){
        int cnt=0;
        while(left>=0 && right<n && s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n=s.size();
        int total=0;
        for(int i=0;i<n;i++){
            int odd=helper(i,i,n,s);
            total+=odd;
            if(i!=n-1){
                int even=helper(i,i+1,n,s);
                total+=even;
            }
        }
        return total;
    }
};
