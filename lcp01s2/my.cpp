#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return !(guess[0]^answer[0]) + !(guess[1] ^ answer[1]) + !(guess[2]^answer[2]);
    }
};

int main() {
	
	return 0;
}
