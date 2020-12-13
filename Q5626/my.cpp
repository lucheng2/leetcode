#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
		char max = '0';
		int len = n.size();
		for(int i=0; i<len; i++) {
			if(max< n[i]) {
				max = n[i];
			}
		}
		return max - '0';
    }
};

int main() {
	Solution s;
	string t = "27346209830709182346";
	int r = s.minPartitions(t);
	printf("%d\n", r);

}
