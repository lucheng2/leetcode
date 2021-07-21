#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int x, k;
    cin>>x>>k;
    int res = ~x;
    int i=0, j=0;
    for(; i<32; i++) {
        if(k>>i) {
            while(! (res>>j))
                j++;
            j++;
        } else{
            while(! (res>>j))
                j++;
            res = 

        }
    }
	return 0;
}
