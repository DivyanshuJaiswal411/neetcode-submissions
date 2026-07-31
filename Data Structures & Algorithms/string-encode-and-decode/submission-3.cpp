class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(string it:strs){
            encoded_string+=to_string(it.size())+'#'+it;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> initial;
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            i=j+1;
            initial.push_back(s.substr(i,length));
            i+=length;
        }
        return initial;
    }
};
