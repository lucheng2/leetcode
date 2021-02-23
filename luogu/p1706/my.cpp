#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>

using namespace std;

int visited[10];
int arr[10];
int n;

void dfs(int step) {
    if(step > n) {
        for(int i=1; i<=n; ++i)
            cout<<setw(5)<<arr[i];
        cout << endl;
        return;
    }
    for(int i=1; i<=n; ++i) {
        if(visited[i]==0) {
            visited[i] = 1;
            arr[step] = i;
            dfs(step + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
	return 0;
}
