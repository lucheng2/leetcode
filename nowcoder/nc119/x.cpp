#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        quick_sort_3way(input.begin(), k, input.size());
        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(input[i]);
        return ans;
    }

    void quick_sort_3way(vector<int>::iterator it, int kth, int len) {
        if(len < 2)
            return;
        int qviot = it[rand() % len];
        int i=0, j=0, k=len;
        while(i < k) {
            if(it[i] < qviot)
                swap(it[i++], it[j++]);
            else if(it[i] > qviot)
                swap(it[i], it[--k]);
            else
                i++;
        }
        if(j > kth)
            quick_sort_3way(it, kth, j);
        else if(k < kth)
            quick_sort_3way(it + k, kth - k, len - k);
        else
            return;
    }
};

