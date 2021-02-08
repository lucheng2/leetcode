#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char Left[3][7], Right[3][7], result[3][7];

bool isFake(char c, bool isLight);

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        for(int i=0; i<3; ++i) {
            scanf("%s %s %s", Left[i], Right[i], result[i]);
        }
        for(char c='A'; c<='L'; ++c) {
            if(isFake(c, true)) {
                printf("%c is the counterfeit coin and it is light.\n", c);
                break;
            }
            else if(isFake(c, false)) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }
    }
	return 0;
}

bool isFake(char c, bool isLight) {
    for(int i=0; i<3; ++i) {
        char *pLeft, *pRight;
        if(isLight) {
            pLeft = Left[i];
            pRight = Right[i];
        }
        else {
            pLeft = Right[i];
            pRight = Left[i];
        }
        switch (result[i][0])
        {
            case 'u':
                if(strchr(pRight, c) == NULL) {
                    return false;
                }
                break;
            case 'e':
                if(strchr(pLeft, c) || strchr(pRight, c)) {
                    return false;
                }
                break;
            case 'd':
                if(strchr(pLeft, c) ==NULL) {
                    return false;
                }
                break;
        }
    }
    return true;

}


