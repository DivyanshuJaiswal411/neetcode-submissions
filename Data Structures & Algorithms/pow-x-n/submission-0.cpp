class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long exp=abs((long long)n);
        while(exp){
            if(exp&1) ans*=x;
            x*=x;
            exp>>=1;
        }
        if(n>=0) return ans;
        return 1.0/ans; 
    }
};
