#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<memory>

using namespace std;

int getBit(char c, int i) {
    return (c>>i) & 1;
}

void setBit(char &c, int i, int v) {
    if(v)
        c |= (1<<i);
    else
        c &= ~(1<<i);
}

void flipBit(char &c, int i) {
    c ^= (1<<i);
}

void outputResult(int t, char * press)  {
    printf("PUZZLE #%d\n", t);
    for(int i=0; i<5; i++) {
        for(int j=0; j<6; j++ ) {
            printf("%d ", getBit(press[i], j));
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char originlights[6], lights[6], press[6], switchs;
    for(int m=0; m<n; ++m) {
        memset(originlights, 0, sizeof(originlights));
        for(int i=0; i<5; ++i) {
            for(int j=0; j<6; j++) {
                int v;
                scanf("%d", &v);
                setBit(originlights[i], j, v);
            }
        }
        for(int k=0; k<64; ++k) {
            switchs = k;
            memcpy(lights, originlights, sizeof(originlights));
            for(int i=0; i<5; ++i) {
                press[i] = switchs;
                for(int j=0; j<6; ++j) {
                    if(getBit(switchs, j)) {
                        flipBit(lights[i], j);
                        if(j>0) {
                            flipBit(lights[i], j-1);
                        }
                        if(j<5) {
                            flipBit(lights[i], j+1);
                        }
                    }
                } 
                if(i<4) {
                    lights[i+1] ^= switchs;
                }
                switchs = lights[i];
            }
            if(lights[4] == 0) {
                outputResult(m+1, press);
                break;
            }
        }
    }
	return 0;
}
