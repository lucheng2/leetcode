#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;
int n,q;
int data[40005];
int l,r,k;
int cnt;
vector<vector<unordered_map<int, int>>> st;

inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

int main() {
    n = read(), q = read();
    for(int i=1; i<=n; i++) {
        data[i] = read();
    }
    int logn = 31 - __builtin_clz(n);
    st.resize(n+1);
    for(int i=1; i<=n; i++) {
        st[i].resize(logn+1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=logn; j++) {
            if(j>0) {
                for(auto it: st[i-1][j]) {
                    st[i][j][it.first] = it.second;
                }
                if(i+(1<<j) <= n)
                    st[i][j][data[i + (1<<j)]] ++;
                if(i>0)
                    st[i][j][data[i-1]] --;
            }
            else{
                st[i][j][data[i]] ++;
            }
        }
    }
    for(int i=0; i<q; i++) {
        l = read(), r= read(), k= read();
        cnt = 0;
        unordered_map<int, int> hm;
        int len = r-l+1;
        int start = l;
        while(len>0) {
            int lg = 31 - __builtin_clz(len);
            for(auto it =st[start][lg].begin(); it!=st[start][lg].end(); it++) {
                if(hm.find(it->first)==hm.end())
                    hm[it->first] = it->second;
                else
                    hm[it->first] += it->second;
            }

            len -= 1<<lg;
            start += (1<<lg);
        }
        for(auto it: hm) {
            if(it.second == k)
                cnt ++;
        }
        printf("%d\n", cnt);
    }
	
	return 0;
}
