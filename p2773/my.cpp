#include<iostream>
#include<cstring>
#define MAXV 1002

using namespace std;

//有N件物品和一个容量为V的背包。放入第i件物品耗费的费用是Ci，得到的价值是Wi。求解将哪些物品装入背包可使价值总和最大.

int F[MAXV];
int N, V;
int C[MAXV], W[MAXV];

void zeroOnePack(int *F, int Ci, int Wi) {
    for(int v=V; v>=Ci; --v) {
        F[v] = max(F[v], F[v-Ci] + Wi);
    }
}

int main() {
    scanf("%d%d", &V, &N);
    for(int i=1; i<=N; ++i) {
        scanf("%d%d", &C[i], &W[i]);
    }
    memset(F, 0, sizeof(F));
    for(int i=1; i<=N; ++i) {
        zeroOnePack(F, C[i], W[i]);
    }
    printf("%d\n", F[V]);
    return 0;
}

