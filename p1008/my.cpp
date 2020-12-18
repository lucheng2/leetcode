#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int a[3] = {0};
    string gt = "123456789";
    for (int n=100; n<400; n++) {
        string res = to_string(n) + to_string(n*2) + to_string(n*3);
        sort(res.begin(), res.end());
        if (res==gt) {
            printf("%d %d %d\n", n, 2*n,3*n);
        }
    }    
	return 0;
}
