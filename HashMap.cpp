class MyHashMap {
private:
    int **HashMap;

public:
    MyHashMap()
    {
       HashMap = new int *[1000]; 
       fill(HashMap, HashMap + 1000, nullptr);
    }

    int hash1(int key)
    {
        return key % 1000;
    }

    int hash2(int key)
    {
        return key / 1000;
    }

    void put(int key, int value)
    {
        int bucket = hash1(key);
        if (HashMap[bucket] == nullptr) {
            if (bucket == 0) {
                HashMap[bucket] = new int [1001];
                fill(HashMap[bucket], HashMap[bucket] + 1001, -1);
            } else {
                HashMap[bucket] = new int [1000];
                fill(HashMap[bucket], HashMap[bucket] + 1000, -1);
            }
        }

        int itemIndex = hash2(key);
        HashMap[bucket][itemIndex] = value; 
    }
    
    int get(int key)
    {
        int bucket = hash1(key);
        if (HashMap[bucket] != nullptr) {
            int itemIndex = hash2(key);
            return HashMap[bucket][itemIndex];
        }

        return -1;
    }
    
    void remove(int key)
    {
        if (get(key) != -1) {
            put(key, -1);
        } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */class MyHashMap {
private:
    int **HashMap;

public:
    MyHashMap()
    {
       HashMap = new int *[1000]; 
       fill(HashMap, HashMap + 1000, nullptr);
    }

    int hash1(int key)
    {
        return key % 1000;
    }

    int hash2(int key)
    {
        return key / 1000;
    }

    void put(int key, int value)
    {
        int bucket = hash1(key);
        if (HashMap[bucket] == nullptr) {
            if (bucket == 0) {
                HashMap[bucket] = new int [1001];
                fill(HashMap[bucket], HashMap[bucket] + 1001, -1);
            } else {
                HashMap[bucket] = new int [1000];
                fill(HashMap[bucket], HashMap[bucket] + 1000, -1);
            }
        }

        int itemIndex = hash2(key);
        HashMap[bucket][itemIndex] = value; 
    }
    
    int get(int key)
    {
        int bucket = hash1(key);
        if (HashMap[bucket] != nullptr) {
            int itemIndex = hash2(key);
            return HashMap[bucket][itemIndex];
        }

        return -1;
    }
    
    void remove(int key)
    {
        if (get(key) != -1) {
            put(key, -1);
        } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
