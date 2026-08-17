class TimeMap {
    unordered_map<string, map<int, string>> hMap;
public:
    TimeMap() : hMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto& map1 = hMap[key];
        auto it = map1.upper_bound(timestamp);
        if (it == map1.begin()) {
            return "";
        }

        it--;
        return it -> second;
    }
};
