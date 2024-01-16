
class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> indexMap;

public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (indexMap.find(val) != indexMap.end()) {
            return false; // Element already exists in the set
        }

        nums.push_back(val);
        indexMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (indexMap.find(val) == indexMap.end()) {
            return false; // Element not found in the set
        }

        int lastElement = nums.back();
        int idxToRemove = indexMap[val];

        nums[idxToRemove] = lastElement;
        indexMap[lastElement] = idxToRemove;

        nums.pop_back();
        indexMap.erase(val);

        return true;
    }

    int getRandom() {
        int randomIdx = rand() % nums.size();
        return nums[randomIdx];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */