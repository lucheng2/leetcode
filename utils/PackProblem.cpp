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

// O(VN)解法
void completePack(int *F, int Ci, int Wi) {
    for(int v=Ci; v<=V; ++v) {
        F[v] = max(F[v], F[v-Ci] + Wi);
    }
}

//O(N*log[V/Ci])解法
void completePackOptimized(int *F, int Ci, int Wi) {
    int Mi = V / Ci;
    int k = 1;
    while(k < Mi) {
        zeroOnePack(F, k*Ci, k*Wi);
        Mi = Mi - k;
        k = k<<1;
    }
    zeroOnePack(F, Mi*Ci, Mi*Wi);
}


void multiplePack(int *F, int Ci, int Wi, int Mi) {
    if(Ci*Mi>=V) {
        completePack(F, Ci, Wi);
        return;
    }
    int k=1;
    while(k<Mi) {
        zeroOnePack(F, k*Ci, k*Wi);
        Mi = Mi -k;
        k = k<<1;
    }
    zeroOnePack(F, Mi*Ci, Mi*Wi);
}

int main() {
    scanf("%d%d", &N, &V);
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

