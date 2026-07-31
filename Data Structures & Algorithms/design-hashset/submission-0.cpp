class MyHashSet {
    static const int BUCKETS = 1000;
    vector<list<int>> table;

    inline int hash(int key) {
        return key % BUCKETS; 
    }
public:
    MyHashSet() {
        table.resize(BUCKETS);
    }
    
    void add(int key) {
        int idx = hash(key);
        for (int val : table[idx]) {
            if (val == key) return;
        }
        table[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        table[idx].remove(key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        for (int val : table[idx]) {
            if (val == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */