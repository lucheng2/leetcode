#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ML 1002
#include<climits>

using namespace std;
int rightMinTime(int k);
int leftMinTime(int k);

int t;
int N, X, Y, MAX;
int lmem[ML], rmem[ML];
vector<vector<int>> data (ML, vector<int>(3,-1));

struct myCompare {
    bool operator() (const vector<int> & a1, const vector<int> & a2) const {
        return a1[2]>a2[2];
    }
};

int findBordBelow(int k, int pos) {
    for(int i=k+1; i<=N; ++i) {
        //这里容易出错, 要考虑jerry会被摔死的情况
        if(data[i][0]<=pos && data[i][1]>=pos && data[i][2]<data[k][2]) {
           if (data[k][2] - data[i][2] <= MAX)  
                return i;
           else
               return -1;
        }
    }
    return -1;
}

int Lx(int k) {
    return data[k][0];
}

int Rx(int k) {
    return data[k][1];
}

int Hx(int k) {
    return data[k][2];
}

int leftMinTime(int k) {
    if(lmem[k]!=-1) {
        return lmem[k];
    }
    int lmt;
    int m = findBordBelow(k, Lx(k));
    if( m == -1) {
        if(Hx(k)>MAX) {
            lmt = 200000000;
        } else {
            lmt = Hx(k);
        }
    } else {
        lmt = (Hx(k)-Hx(m)) + min(leftMinTime(m) + Lx(k) - Lx(m), rightMinTime(m) + Rx(m) - Lx(k));
    }
    lmem[k] = lmt;
    return lmt;
}

int rightMinTime(int k) {
    if(rmem[k]!=-1)
        return rmem[k];
    int rmt;
    int m=findBordBelow(k, Rx(k));
    if(m==-1) {
        if(Hx(k)>MAX)
            rmt = 200000000;
        else
            rmt = Hx(k);
    }
    else {
        rmt = (Hx(k) - Hx(m))
            + min(leftMinTime(m) + Rx(k) -Lx(m), rightMinTime(m) + Rx(m) -Rx(k));
    }
    rmem[k] = rmt;
    return rmt;
}

int main() {
    scanf("%d", &t);
    while(t>0) {
        --t;
        scanf("%d%d%d%d", &N, &X, &Y, &MAX);
        memset(lmem, -1, sizeof(lmem));
        memset(rmem, -1, sizeof(rmem));
        data[0] = {X, X, Y};
        for(int i=1; i<=N; ++i) {
            scanf("%d%d%d", &data[i][0], &data[i][1], &data[i][2]);
            if(data[i][0]>data[i][1])
                swap(data[i][0], data[i][1]);
        }
        sort(data.begin() + 1, data.begin() + N +1, myCompare());
        int ans = rightMinTime(0);
        printf("%d\n", ans);
    }
	return 0;
}
