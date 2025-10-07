class MyHashSet {
private:
    bool **set;

public:
    MyHashSet()
    {
        set = new bool*[1000](nullptr);
    }
    
    int hash1(int key)
    {
        return key % 1000;
    }

    int hash2(int key)
    {
        return key / 1000;
    }

    void add(int key)
    {
        int bucket = hash1(key);
        if (set[bucket] == nullptr) {
            if (bucket == 0) {
                set[bucket] = new bool [1001](false);
            } else {
                set[bucket] = new bool [1000](false);
            }
        }

        int itemIndex = hash2(key);
        set[bucket][itemIndex] = true;
    }
    
    void remove(int key) 
    {
        int bucket = hash1(key);
        if (set[bucket] == nullptr) {
            return;
        }

        int itemIndex = hash2(key);
        set[bucket][itemIndex] = false;
    }
    
    bool contains(int key)
    {
        int bucket = hash1(key);
        if (set[bucket] == nullptr) {
            return false;
        }

        int itemIndex = hash2(key);
        return set[bucket][itemIndex];  
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
