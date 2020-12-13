#include<iostream>
#include<vector>

using namespace std;

//回溯+备忘录
class Solution {
public:
	int sum[1000] = 0;
	int mem[1000][1000] = {0};

    int stoneGameVII(vector<int>& stones) {
		int len = stones.size();
		sum[0] = stones[0];
		for (int i=1; i<len; i++) {
			sum[i] = stones[i] + sum[i-1];
		}

		for (int i=0; i<len; i++) {
			for (int =i; j<len; j++) {
				mem[i][j] = sum[j] - sum[i];
			}
		}

		// give up
    }

	int score(vector<int> &stones, int i, int j) {

	}
};

int main() {

}
