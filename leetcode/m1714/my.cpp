#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    void quick_sort(vector<int>::iterator arr, int kth, int len) {
        const int pivot = arr[rand()%len];
        int i=0, j=0, k=len;
        while(i < k) {
            if(arr[i] < pivot)
                swap(arr[i++], arr[j++]);
            else if(arr[i] > pivot)
                swap(arr[i], arr[--k]);
            else 
                i++;
        }
        if(j >= kth) 
            quick_sort(arr, kth, j);
        else if(k < kth)
            quick_sort(arr + k, kth - k,  len - k);
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k <= 0)
            return {};
        quick_sort(arr.begin(), k, arr.size());
        vector<int> ans(arr.begin(), arr.begin()+k);
        return ans;
    }
};

