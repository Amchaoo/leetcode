#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (locationMap.find(val) != locationMap.end()) {
            return false;
        }

        locationMap[val] = valueContainer.size();
        valueContainer.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (locationMap.find(val) == locationMap.end()) {
            return false;
        }

        int last = valueContainer.back();
        valueContainer[locationMap[val]] = last;
        locationMap[last] = locationMap[val];
        valueContainer.pop_back();
        locationMap.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int keyIndex = randomInt(valueContainer.size());
        return *(valueContainer.begin() + keyIndex);
    }
private:
    vector<int> valueContainer;
    unordered_map<int,int> locationMap;
    int randomInt(int upMax) {
        return rand() % upMax;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */