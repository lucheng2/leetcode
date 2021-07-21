#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        quick_sort_3ways(a.begin(), K - 1, n);
        return a[K-1];
    }

    void quick_sort_3ways(vector<int>::iterator it, int kth, int len) {
        if(len<=1)
            return;
        const int qviot = it[rand() % len];
        // i:操作的索引, j:第一个等于基准的索引，k:第一个小于基准的索引
        int i=0, j=0, k=len;
        while(i < k) {
            if(it[i] > qviot)
                swap(it[i++], it[j++]);
            else if(it[i] < qviot)
                swap(it[i], it[--k]);
            else
                i++;
        }
        // 由于kth是索引位置，要保证有序，应该取等号
        if(j >= kth) 
            quick_sort_3ways(it, kth, j);
        else if(k < kth)
            quick_sort_3ways(it + k, kth - k, len-k);
        else
            return;
    }
};
