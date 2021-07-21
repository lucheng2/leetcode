#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    int findKth(vector<int>::iterator nums, int kth, int n) {
        const int pivot = nums[rand() % n];
        int i=0, j=0, k=n;
        while(i<k) {
            if(nums[i] > pivot) 
                swap(nums[i++], nums[j++]);
            else if(nums[i] < pivot)
                swap(nums[i], nums[--k]);
            else
                i++;
        }
        if(j >= kth)
            return findKth(nums, kth, j);
        if(kth > k) 
            return findKth(nums+k, kth-k, n-k);
        return pivot;
    }

    int findKthLargest(vector<int>& nums, int kth) {
        return findKth(nums.begin(), kth, nums.size());
    }
};

