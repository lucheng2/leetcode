#include<iostream>

using namespace std;

class Solution {
public:
	int count=0;
    int numberOfMatches(int n) {
		traceBack(n);
		return count;
    }

	void traceBack(int n) {
		if (n==1) {
			return;
		}
		if(n%2==0) {
			count += n/2;
			traceBack(n/2);
		} else {
			count+= n/2;
			traceBack(n/2 + 1);
		}
	}
};

int main() {
	Solution s;
	int r = s.numberOfMatches(7);
	printf("%d", r);
}
