class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        int n = words.size();

        // Graph of 26 letters
        vector<vector<int>> adj(26);

        // Track which letters actually appear
        vector<bool> present(26, false);

        for (auto word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            bool found = false;

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);

                    found = true;
                    break;
                }
            }

            // Invalid case:
            // "abc" comes before "ab"
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Calculate indegree
        vector<int> indegree(26, 0);

        for (int i = 0; i < 26; i++) {
            for (auto neigh : adj[i]) {
                indegree[neigh]++;
            }
        }

        // Put characters with indegree 0 into queue
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        // Topological sort
        string ans;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto neigh : adj[node]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // If we couldn't include every character,
        // there is a cycle
        int totalLetters = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalLetters++;
            }
        }

        if (ans.size() != totalLetters) {
            return "";
        }

        return ans;
    }
};