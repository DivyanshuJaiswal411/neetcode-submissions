class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxi1=0,maxi2=0,maxi3=0;
        for(auto it:triplets){
            int curr1=max(maxi1,it[0]);
            int curr2=max(maxi2,it[1]);
            int curr3=max(maxi3,it[2]);
            if(curr1<=target[0] && curr2<=target[1] && curr3<=target[2]){
                maxi1=curr1;
                maxi2=curr2;
                maxi3=curr3;
            }
        }
        return (maxi1==target[0] && maxi2==target[1] && maxi3==target[2]);
    }
};
