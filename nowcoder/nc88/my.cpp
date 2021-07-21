#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        quick_sort(a.begin(), K-1, 0, n-1);
        return a[K-1];
    }

    void quick_sort(vector<int>::iterator it, int k, int low, int high) {
        if(high-low<1)
            return;
        int qviot = it[low];
        int i = low, j = high;
        while(low < high) {
            while(low < high && it[high] <= qviot)
                high -- ;
            it[low] = it[high];
            while(low < high && it[low] > qviot)
                low ++;
            it[high] = it[low];
        }
        it[low] = qviot;
        if(low > k)
            quick_sort(it, k, i, low - 1);
        if(low < k)
            quick_sort(it, k, low + 1, j);
        return;
    }
};
