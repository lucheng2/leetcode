#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n, 0);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(boxes[j] == '1')
                    ans[i] += abs(j-i);
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
