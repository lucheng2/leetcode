#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        int j=0, tmp;
        for(int i=0; i<array.size(); i++) {
            tmp = array[i];
            if(tmp & 1) {
                int k=i - 1;
                while(k >= j) {
                    array[k+1] = array[k];
                    k--;
                }
                array[k+1] = tmp;
                j++;
            }
        }
        return array;
    }
};
