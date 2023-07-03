#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

int a[200005], d[200005], b[200005];
int idx = 0;

struct node {
    int x;
    vector<int> y;
    bool isroot=true;
    int child=0;
    node(int x) :x(x) {}
};
unordered_map<int, node> hm;
unordered_map<int, pair<int, int>> f;

int trans(int p) {
    if(hm[p].y.size() > 0) {
        for(int i=0; i<hm[p].y.size(); i++) {
            hm[p].child += trans(hm[p].y[i]);
        }
    }
    f[p] = make_pair(idx++, hm[p].child);;
    return hm[p].child;
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int m = s + ((t - s) >> 1);
  build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
  d[p] = d[p * 2] + d[(p * 2) + 1];
}

void update(int l, int r, int c, int s, int t, int p) {
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, b[p] += c;
    return;
  } 
  int m = s + ((t - s) >> 1);
  if (b[p] && s != t) {
    // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
    b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
    b[p] = 0;                                // 清空当前节点的标记
  }
  if (l <= m) update(l, r, c, s, m, p * 2);
  if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
  d[p] = d[p * 2] + d[p * 2 + 1];
}

int getMax(int l, int r, int s, int t, int p) {
  if (l <= s && t <= r) return d[p];
  int m = s + ((t - s) >> 1);
  if (b[p]) {
    // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m),
        b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
    b[p] = 0;                                    // 清空当前节点的标记
  }
  int mx = 0;
  if (l <= m) mx = getMax(l, r, s, m, p * 2);
  if (r > m) mx = max(getMax(l, r, m + 1, t, p * 2 + 1), mx);
  return mx;
}

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        hm[i] = node(i);
    }
    int x, y;
    for(int i=1; i<n; i++) {
        cin>>x>>y;
        hm[x].y.push_back(y);
        hm[y].isroot = false;
    }
    int root = 0;
    for(int i=1; i<=n; i++) {
        if(hm[i].isroot) {
            root=i;
            break;
        }
    }
    trans(root);
    build(1, n, 1);

    int q;
    cin>>q;
    int opt, k;
    while(q--) {
        cin>>opt;
        if(opt==1) {
            cin>>x>>k;

        }
        else {
            cin>>x;
        }

    }
	
	return 0;
}
