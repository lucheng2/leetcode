#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<climits>
#include<queue>

using namespace std;

int n;
vector<vector<long long>> table;
vector<long long> real;


long long sum(int j, int r) {
    long long s = 0;
    for(int i=0; i<=r; i++) {
        s += (long long)(r - i + 1) * table[j][i];
    }
    return s;
}

int main() {
    int q;
    cin>>n>>q;
    table = vector<vector<long long>>(11, vector<long long>(n+2));
    real = vector<long long>(n+2);
    int opt, a, l, r, k;
    for(int i=0; i<q; i++) {
        cin>>opt;
        if(opt==1) {
            cin>>a>>l>>r>>k;
            int j=0;
            while((1<<j)<=a) {
                if(a & (1<<j)) {
                    table[j][l] += k;
                    table[j][r+1] -= k;
                }
                j++;
            }
        }
        else {
            cin>>a>>l>>r;
            int j=0;
            long long ans = 0;
            while((1<<j)<=a) {
                if(a & (1<<j)) {
                    ans += sum(j, r);
                    ans -= sum(j, l-1);
                }
                j++;
            }
            cout<<ans<<endl;
        }
    }
	return 0;
}
