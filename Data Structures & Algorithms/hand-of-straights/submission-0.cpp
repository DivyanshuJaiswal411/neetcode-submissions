class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> mpp;
        for(int it:hand) mpp[it]++;
        if(n%groupSize!=0) return false;
        int needed=n/groupSize;
        int curr=0;
        while(curr!=needed){
            int curgroup=0;
            int currele=-1;
            for(auto it:mpp){
                if(it.second){
                    currele=it.first;
                    mpp[currele]--;
                    break;
                }
            }
            for(int i=1;i<groupSize;i++){
                if(mpp[currele+i]){
                    mpp[currele+i]--;
                }
                else{
                    return false;
                }
            }
            curr++;
        }
        return true;
    }
};
