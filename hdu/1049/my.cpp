#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, u, d;
int hight;

bool climb() {
    hight += u;
    if(hight >= n)
       return true;
    else 
      return false; 
}
void slip() {
    hight -= d;
}

int main() {
    while(1) {
        scanf("%d%d%d", &n, &u, &d);
        if(n == 0)
            break;
        int time = 0;
        hight = 0;
        while(1) {
            time ++;
            if(climb()) {
                printf("%d\n", time);
                break;
            }
            time ++;
            slip();
        }
    }
	return 0;
}
