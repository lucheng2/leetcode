#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = INT_MIN;
        for(auto a: candies)
            if (mx< a)
                mx = a;
        vector<bool> res(candies.size(), false);
        for(int i=0; i<candies.size(); i++) {
            if(candies[i] + extraCandies>= mx)
                res[i] = true;
        }
        return res;
    }
};

int main() {
	
	return 0;
}
