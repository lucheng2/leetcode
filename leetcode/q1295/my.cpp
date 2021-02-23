#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto num: nums) {
            if(!(to_string(num).size() & 1))
                res++;
        }
        return res;
    }
};

int main() {
	
	return 0;
}
