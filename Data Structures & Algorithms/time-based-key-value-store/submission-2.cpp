class TimeMap {
private:
    std::unordered_map<string, std::vector<std::pair<string, int>>> hash;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        const std::vector<std::pair<string, int>>& kvs = hash[key];
        int l = 0, r = kvs.size() - 1;
        if (kvs.size() == 0) {
            return "";
        }
        if (kvs.size() == 1) {
            if (kvs[0].second <= timestamp) return kvs[0].first;
            else return "";
        }
        string output = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (kvs[mid].second == timestamp) {
                return kvs[mid].first;
            }
            if (kvs[mid].second < timestamp) {
                output = kvs[mid].first;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return output;
    }
};
