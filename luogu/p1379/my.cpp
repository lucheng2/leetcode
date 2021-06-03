#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#define ll long long

using namespace std;

const int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int fx, fy;

struct matrix {
    int a[5][5];
    bool operator < (matrix x) const {
        for(int i=1; i<=3; i++) {
            for(int j=1; j<=3; j++) {
                if(a[i][j] != x.a[i][j])
                    return a[i][j] < x.a[i][j];
            }
        }
        return false;
    }
} f, st;

int h(matrix a) {
    int ret = 0;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            if(a.a[i][j] != st.a[i][j]) {
                ret ++;
            }
        }
    }
    return ret;
};

struct node {
    matrix a;
    int t=0;
    //f(x) + h(x)
    bool operator < (node x) const {
        return h(a) + t > h(x.a) + x.t;
    }
    node(matrix x, int t): a(x), t(t) {
    }
    
} x(st, 0);

priority_queue<node> q;
set<matrix> s;

char c;
int main() {
    st.a[1][1] = 1, st.a[1][2] = 2, st.a[1][3] = 3;
    st.a[2][1] = 8, st.a[2][2] = 0, st.a[2][3] = 4;
    st.a[3][1] = 7, st.a[3][2] = 6, st.a[3][3] = 5;
    
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            scanf("%c", &c);
            f.a[i][j] = c - '0';
        }
    }
    node start(f, 0);
    q.push(start);
    while(!q.empty()) {
        x = q.top();
        q.pop();
        if(!h(x.a)) {
            printf("%d\n", x.t);
            return 0;
        }
        for(int i=1; i<=3; i++) 
            for(int j=1; j<=3; j++)
                if(!x.a.a[i][j]) {
                    fx = i;
                    fy = j;
                }
        for(int i=0; i<4; i++) {
            int xx = fx+dx[i], yy = fy+dy[i];
            if(1<=xx&&xx<=3 && 1<=yy&&yy<=3) {
                swap(x.a.a[fx][fy], x.a.a[xx][yy]);
                if(!s.count(x.a)) {
                    s.insert(x.a);
                    node tmp(x.a, x.t+1);
                    q.push(tmp);
                }
                // 还原
                swap(x.a.a[fx][fy], x.a.a[xx][yy]);
            }
        }
    }
	
	return 0;
}
