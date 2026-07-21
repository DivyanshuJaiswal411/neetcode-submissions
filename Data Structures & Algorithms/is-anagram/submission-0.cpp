class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s1(26,0);
        vector<int> s2(26,0);
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            s1[s[i]-'a']++;
            s2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
};
