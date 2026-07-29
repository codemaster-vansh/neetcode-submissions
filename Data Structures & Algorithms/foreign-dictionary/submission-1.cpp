class Solution {
public:
    //Using topological sort

    //We utilise Kahns Algorithm to pop edges one by one and append them
    //We make a dependency graph and subsequent adjacency list using lexicographical string matching
    
    // directed edges passed here
    vector<char> topoSortKahn (const vector<vector<char>>& edges, const unordered_set<char>& all_chars) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        vector<char> result;
        queue<char> q;

        for (char c : all_chars) {
            indegree[c] = 0;
        }

        for (const vector<char>& edge : edges) {
            char u = edge[0];
            char v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for (const auto& p : indegree) {
            if (p.second == 0) q.push(p.first);
        }

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            result.push_back(node);

            for (char n : adj[node]) {
                indegree[n]--;
                if (indegree[n] == 0) q.push(n);
            }
        }

        if (result.size() != indegree.size()) {
            return {};
        }

        return result;
    }

    int string_diff(string& s1, string& s2) {
        int minLen = min(s1.size(), s2.size());

        for (int i = 0;i < minLen;i++) {
            if (s1[i] != s2[i]) {
                return i;
            }
        }

        if (s1.size() > s2.size()) return -2;

        return -1;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_set<char> all_chars;
        for (const string& word : words) {
            for (char c : word) {
                all_chars.insert(c);
            }
        }

        int len = words.size();
        vector<vector<char>> edges;
        for (int i = 0;i < len - 1;i++) {
            int minLen1 = string_diff(words[i], words[i + 1]);
            if (minLen1 == -2) return "";
            if (minLen1 != -1) {
                char c1 = words[i][minLen1];
                char c2 = words[i + 1][minLen1];
                edges.push_back({c1, c2});
            }
        }

        vector<char> result = topoSortKahn(edges, all_chars);

        if (result.empty() && !all_chars.empty()) {
            return "";
        }

        return string(result.begin(), result.end());
    }
};
