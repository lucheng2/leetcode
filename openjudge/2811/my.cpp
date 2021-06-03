#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>

using namespace std;

vector<bitset<6>> oriLight, light, result;
int n=5, m=6;
char input[6];
int in;

int main() {
    oriLight.resize(5);
    result.resize(5);
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>=0; j--) {
            scanf("%d", &in);
            input[j] = in==1?'1': '0';
        }
        oriLight[i] = bitset<6>(string(input));
    }
    for(int i=0; i<(1<<m); i++) {
        light = vector<bitset<6>>(oriLight);
        bitset<6> switchs(i);
        for(int j=0; j<n; j++) {
            result[j] = switchs;
            for(int k=0; k<m; k++) {
                if(switchs[k]) {
                    if(k>0)
                        light[j].flip(k-1);
                    light[j].flip(k);
                    if(k<m-1)
                        light[j].flip(k+1);
                }
            }
            if(j<n-1)
                light[j+1] ^= switchs;
            switchs = light[j];
        }
        if(light[n-1].none()){
            for(auto res: result) {
                for(int i=0; i<m; i++) {
                    printf("%d ", res[i]?1:0);
                }
                printf("\n");
            }
            return 0;
        }
        
    }
	return 0;
}
