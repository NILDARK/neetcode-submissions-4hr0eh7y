class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        vContainer[key].emplace_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (vContainer.count(key) == 0)
            return "";

        auto res = upper_bound(vContainer[key].begin(), vContainer[key].end(),
                               make_pair(timestamp, string("")), comp);

        if (res == vContainer[key].begin())
            return "";

        --res;
        return (*res).second;
    }

private:
    static bool comp(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;
    }

    unordered_map<string, vector<pair<int, string>>> vContainer;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */