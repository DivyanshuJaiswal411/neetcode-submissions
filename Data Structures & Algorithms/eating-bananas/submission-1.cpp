class Solution {
public:
    bool check(long long mid,vector<int>& piles, int h,int n){
        int currtime=0;
        for(int i=0;i<n;i++){
            if(piles[i]<=mid){
                currtime++;
            }
            else{
                currtime+=(piles[i]+mid-1)/mid;
            }
            if(currtime>h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long l=0;
        long long r=0;
        for(int it:piles) r+=it;
        while(r-l>1){
            long long mid=l+(r-l)/2;
            if(check(mid,piles,h,n)) r=mid;
            else l=mid;
        }
        return (int)r;
    }
};
