#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>

using namespace std;

class MyHashSet {
public:
    vector<list<int>> hashSet;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }

    /** Initialize your data structure here. */
    MyHashSet(): hashSet(base) {

    }
    
    void add(int key) {
        int h = hash(key);
        for(auto it=hashSet[h].begin(); it!=hashSet[h].end(); ++it) {
            if(*it == key) {
                return;
            }
        }
        hashSet[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it=hashSet[h].begin(); it!=hashSet[h].end(); ++it) {
            if(*it == key) {
                hashSet[h].erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for(auto it=hashSet[h].begin(); it!=hashSet[h].end(); ++it) {
            if(*it == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
	
	return 0;
}
