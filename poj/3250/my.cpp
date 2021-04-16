#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<numeric>

using namespace std;
int N;
int main() {
	
    scanf("%d", &N);
    if(N<2) {
        printf("0");
        return 0;
    }
    vector<int> data(N);
    vector<int> ans;
    for(int i=0; i<N; ++i) {
        scanf("%d", &data[i]);
    }
    stack<int> priority_stack;

    for(int i=N-1; i>=0; i--) {
        int tmp = 0;
        int j = 0;
        while(!priority_stack.empty() && priority_stack.top() < data[i]) {
            tmp += 1 + ans[ans.size() - 1 - j];
            j += ans[ans.size() - 1 - j];
            j++;
            priority_stack.pop();
        }    
        ans.push_back(tmp);
        priority_stack.push(data[i]);
    }
    int sum = accumulate(ans.begin(), ans.end(), 0);
    printf("%d", sum);
	return 0;
}
