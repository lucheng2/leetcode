#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

bool isnp[100000005];
vector<int> prm;

void getP(int n) {
    for(int i=2; i<=n; i++) {
        if(!isnp[i])
            prm.push_back(i);
        for(auto p: prm) {
            if(p*i > n)
                break;
            isnp[i*p] = true;
            if(i%p==0)
                break;
        }
    }
}

int main() {
    int n, q, k;
    cin>>n>>q;
    getP(n);
    for(int i=0; i<q; i++) {
        scanf("%d", &k);
        printf("%d\n", prm[k-1]);
    }
	return 0;
}
