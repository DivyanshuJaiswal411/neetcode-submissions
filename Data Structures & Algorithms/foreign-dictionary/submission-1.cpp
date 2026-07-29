class Solution {
public:
    bool makeGraph(vector<string>& words, vector<unordered_set<int>>& adj,
                   vector<int>& indegree) {

        // Mark all characters that appear
        for (auto &word : words) {
            for (char c : word) {
                if (indegree[c - 'a'] == -1)
                    indegree[c - 'a'] = 0;
            }
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++) {
            string &word1 = words[i];
            string &word2 = words[i + 1];

            int len1 = word1.size();
            int len2 = word2.size();

            // Invalid prefix case
            if (len1 > len2 && word1.substr(0, len2) == word2)
                return false;

            for (int j = 0; j < min(len1, len2); j++) {
                if (word1[j] != word2[j]) {

                    int u = word1[j] - 'a';
                    int v = word2[j] - 'a';

                    // Avoid duplicate edges
                    if (adj[u].find(v) == adj[u].end()) {
                        adj[u].insert(v);
                        indegree[v]++;
                    }

                    break;
                }
            }
        }

        return true;
    }

    string foreignDictionary(vector<string>& words) {

        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, -1);

        if (!makeGraph(words, adj, indegree))
            return "";

        queue<int> q;

        int totalChars = 0;

        for (int i = 0; i < 26; i++) {
            if (indegree[i] != -1) {
                totalChars++;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        string ans = "";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // Cycle exists
        if (ans.size() != totalChars)
            return "";

        return ans;
    }
};