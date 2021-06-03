#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<numeric>

using namespace std;
int N;
int data[80005];
long long ans;
stack<int> stk;

int main() {
    scanf("%d", &N);
    if(N<2) {
        printf("0");
        return 0;
    }
    for(int i=1; i<=N; ++i) {
        scanf("%d", &data[i]);
    }
    for(int i=N; i>0; i--) {
        while(!stk.empty() && data[stk.top()] < data[i])
            stk.pop();
        ans += stk.empty()? N-i: stk.top() - i - 1;
        stk.push(i);
    }
    cout<<ans<<endl;
	return 0;
}
