#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

class MyHashMap {
public:
    static const int base = 727;
    vector<list<pair<int,int>>> hashmap;

    int hash(int key) {
        return key % base;
    }

    /** Initialize your data structure here. */
    MyHashMap():hashmap(base) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        for(auto it = hashmap[h].begin(); it!=hashmap[h].end(); ++it) {
            if(it->first == key) {
                it->second = value;
                return;
            }
        }
        hashmap[h].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h= hash(key);
        for(auto it=hashmap[h].begin(); it!=hashmap[h].end(); ++it) {
            if(it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        for(auto it=hashmap[h].begin(); it!=hashmap[h].end(); ++it) {
            if(it->first == key) {
                hashmap[h].erase(it);
                return;
            }
        }

    }
};

int main() {
	
	return 0;
}
