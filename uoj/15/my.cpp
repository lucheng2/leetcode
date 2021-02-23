#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int tab[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}
};
int ta[210];
int tb[210];
int main() {
    int N, Na, Nb;
    scanf("%d%d%d", &N, &Na, &Nb);
    for(int i=0; i<Na; ++i)
        scanf("%d", &ta[i]);
    
    for(int j=0; j<Nb; ++j)
        scanf("%d", &tb[j]);
    int countA =0, countB = 0;	
    for(int i=0; i<N; ++i) {
        countA += tab[ta[i%Na]][tb[i%Nb]];
        countB += tab[tb[i%Nb]][ta[i%Na]];
    }
    printf("%d %d", countA, countB);
	return 0;
}
