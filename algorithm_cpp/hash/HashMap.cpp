#include <vector>
#include <string>
#include <utility>
#include <map>
#include <iostream>

using namespace std;

/* Key_type is only valid for string */
template<typename Key_type, typename Value_type>
class Hashmap {
public:
    Hashmap(Value_type _init_value) : init_value(_init_value), hash_array(capacity, init_value) { }

    pair<bool, int> find(Key_type &key, Value_type &val) {
        int pos = HashHit(key, val);
        if (hash_array[pos] == init_value)
            return pair<bool, int>(false, -1);
        return pair<bool, int>(true, pos);
    }

    // insert for new value
    void insert(Key_type key, Value_type val) {
        int pos = HashHit(key, val);
        hash_array[pos] = val;
    }

private:
    static const int capacity = 100005;
    static const int mod = 10007;
    Value_type init_value;
    vector<Value_type> hash_array;

    // prehash function
    int BKDRHash(Key_type &key) {
        unsigned int seed = 131;
        unsigned int hash = 0;
        for (auto &c : key)
            hash = hash * seed + c;
        return hash & 0x7FFFFFFF;  // return the index of hash_array
    }

    // hash function and process hash hit
    int HashHit(Key_type &key, Value_type &val) {
        int pos = BKDRHash(key) % mod;  // the real hash function
        while (hash_array[pos] != val && hash_array[pos] != init_value)
            pos = (pos + 10) % mod;
        return pos;
    }

};

int main() {
    map<string, int> mymap = {{"chensu", 1},{"chenye", 2},{"chenni", 3}};
    Hashmap<string, int> hashmap(-1);
    for (auto it = mymap.begin() ; it != mymap.end() ; ++it)
        hashmap.insert(it->first, it->second);
    string key = "chenye";
    int val = 2;
    pair<bool, int> ret(hashmap.find(key, val));
    cout << (ret.first == true ? "true" : "false") << ", " << ret.second << endl;
    return 0;
}
