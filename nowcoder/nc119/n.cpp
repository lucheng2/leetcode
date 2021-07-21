#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        quick_sort(input.begin(), k, 0, input.size()-1);
        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(input[i]);
        return ans;
    }

    void quick_sort(vector<int>::iterator it, int k, int left, int right) {
        if(left>=right)
            return;
        int qviot = it[left];
        int ll = left, rr = right;
        while(left<right) {
            while(left<right && it[right] >= qviot)
                right --;
            it[left] = it[right];
            while(left<right && it[left] < qviot)
                left ++;
            it[right] = it[left];
        }
        it[left] = qviot;
        if(left < k) 
            quick_sort(it, k, left+1, rr);
        else if(left > k)
            quick_sort(it, k, ll, left - 1);
        else
            return;
    }
};

