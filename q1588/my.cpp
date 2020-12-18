#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
	int sum[101] = {0};
    int sumOddLengthSubarrays(vector<int>& arr) {
		int len = arr.size();
		sum[1] = arr[0];
		for(int i=2; i<=len; i++) {
			sum[i] = sum[i-1] + arr[i-1];
		}
		if (len<=2) {
    		return sum[len];
		}
		int res = sum[len];
		for (int i=3; i<=len; i+=2) {
			for (int j=0; j+i<=len; j++) {
				res += sum[j+i] - sum[j];
			}
		}
		return res;
    }
};

int main() {
	Solution s;
	vector<int> arr = {1, 4, 2, 5, 3};
	int res = s.sumOddLengthSubarrays(arr);
	printf("%d ", res);
	return 0;
}
