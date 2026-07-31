struct TrieNode {
    TrieNode* children[26];
    bool isLeaf;
    
    TrieNode() {
        isLeaf = false;
        for (int i = 0;i < 26;i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& key) {
        TrieNode* curr = root;
        
        for (char c : key) {
            int idx = c - 'a';
            if (curr -> children[idx] == nullptr) {
                TrieNode* newNode = new TrieNode();
                curr -> children[idx] = newNode;
            }
            curr = curr -> children[idx];
        }
        
        curr -> isLeaf = true;
    }

    string getLCP() {
        TrieNode* curr = root;
        string lcp = "";

        while (curr != nullptr) {
            if (curr -> isLeaf) break;

            int childcount = 0;
            int nextCharIdx = -1;
            for (int i = 0;i < 26;i++) {
                if (curr -> children[i] != nullptr) {
                    childcount++;
                    nextCharIdx = i;
                }
            }

            if (childcount != 1) {
                break;
            }

            lcp += (char)('a' + nextCharIdx);
            curr = curr -> children[nextCharIdx];
        }

        return lcp;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie check;
        for (const string& s : strs) {
            check.insert(s);
        }

        return check.getLCP();
    }
};