#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

int n;
int a[3000005], ans[3000005];
stack<int> stk;

int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=n; i>0; i--) {
        while(!stk.empty() && a[stk.top()]<=a[i])
            stk.pop();
        ans[i] = stk.empty()? 0: stk.top();
        stk.push(i);
    }
    for(int i=1; i<=n; i++)
        printf("%d ", ans[i]);
	return 0;
}
