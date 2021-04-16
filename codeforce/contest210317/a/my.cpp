#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int t, n;
vector<int> a;
vector<int> b;
vector<int> c;

int main() {
    scanf("%d", &t);
    for(int k=0; k<t; ++k) {
        scanf("%d", &n);
        a.clear();
        a.resize(n);
        b.clear();
        c.clear();
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        b.push_back(a[0]);
        for(int i=1; i<n; i++) {
            if(a[i] == b[b.size() -1]) {
                c.push_back(a[i]);
            }
            else{
                b.push_back(a[i]);
            }
        }
        for(int i=0; i<c.size(); ++i) {
            b.push_back(c[i]);
        }
        for(int i=0; i<n; ++i) {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
	return 0;
}
