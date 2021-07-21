#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct node {
    int key;
    int value;
    node * pre;
    node * next;
    node(int k, int v): key(k), value(v) {
    }
};

class Solution {
private:
    int k;
    node* head;
    node* tail;
    unordered_map<int, node*> hm;

public:
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        if(k < 1 || operators.size() == 0)
            return {};
        this->k = k;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->pre = head;
        vector<int> ans;
        for(auto opt: operators) {
            if(opt[0] == 1) {
                set(opt[1], opt[2]);
            }
            else {
                int value = get(opt[1]);
                ans.push_back(value);
            }
        }
        return ans;
    }

    void set(int key, int value) {
        if(hm.count(key)) {
            hm[key]->value = value;
            moveToHead(hm[key]);
        }
        else {
            node * n = new node(key, value);
            hm[key] = n;
            if(k>0) {
                k --;
            }
            else {
                removeLast();
            }
            insertFirst(n);
        }
    }

    int get(int key) {
        int ans = -1;
        if(hm.count(key)) {
            ans = hm[key]->value;
            moveToHead(hm[key]);
        }
        return ans;
    }

    void moveToHead(node * n) {
        if(head->next == n)
            return;
        n->next->pre = n->pre;
        n->pre->next = n->next;
        insertFirst(n);
    }

    void removeLast() {
        hm.erase(tail->pre->key);
        tail->pre->pre->next = tail;
        tail->pre = tail->pre->pre;
    }

    void insertFirst(node* n) {
        n->next = head->next;
        n->pre = head;
        head->next->pre = n;
        head->next = n;
    }
};
