/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){
            if(a.start==b.start) return a.end<b.end;
            return a.start<b.start;
        });
        vector<int> begin(n),end(n);
        for(int i=0;i<n;i++){
            begin[i]=intervals[i].start;
            end[i]=intervals[i].end;
        }
        sort(begin.begin(),begin.end());
        sort(end.begin(),end.end());
        int s=0,e=0;
        int maxi=0;
        int rooms=0;
        while(s<n){
            if(begin[s]<end[e]){
                rooms++;
                s++;
            }
            else{
                rooms--;
                e++;
            }
            maxi=max(maxi,rooms);
        }
        return maxi;
    }
};
