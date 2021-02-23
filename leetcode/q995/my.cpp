#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> diff(n+1, 0);
        int ans = 0, flpCont = 0;
        for(int i=0; i<n; ++i) {
            flpCont += diff[i];
            if((A[i] + flpCont) % 2==0) {
                if(i+K>n)
                    return -1;
                flpCont++;
                ans++;
                diff[i+K]--;
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
