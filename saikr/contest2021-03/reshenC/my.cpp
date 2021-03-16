#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;
int N, M;
vector<vector<int>> dimon;
vector<int> V;

bool myLess(const vector<int> &a, const vector<int> &b) {
    return a[1] > b[1];
}

int main() {
    scanf("%d%d", &N, &M);
    dimon.resize(N, vector<int>(2, 0));
    V.resize(M);
    for(int i=0; i<N; ++i) {
        scanf("%d%d", &dimon[i][0], &dimon[i][1]);
    }
    for(int j=0; j<M; ++j) {
        scanf("%d", &V[j]);
    }
    sort(dimon.begin(), dimon.end(), myLess);
    multiset<int> ms;
    for(int i=0; i<M; ++i) {
        ms.insert(V[i]);
    }
    int j=0;
    long long ans = 0;
    while(j<N && !ms.empty()) {
        multiset<int>::iterator it = ms.lower_bound(dimon[j][0]);
        if(it != ms.end()) {
            ms.erase(it);
            ans += dimon[j][1];
        }
        j++;
    }
    printf("%lld", ans);
    return 0;
}
