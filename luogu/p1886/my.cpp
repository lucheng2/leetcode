#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>

using namespace std;
int n, k;
int a[1000005];
int ma[1000005], mi[1000005];
deque<int> dq;

void getMax() {
    dq.clear();
    for(int i=1; i<k; i++) {
        while(!dq.empty() && a[dq.front()]<=a[i])
            dq.pop_front();
        dq.push_front(i);
    }
    for(int i=k; i<=n; i++) {
        while(!dq.empty() && a[dq.front()]<=a[i])
            dq.pop_front();
        dq.push_front(i);
        while(i-dq.back()+1 > k) {
            dq.pop_back();
        }
        ma[i] = a[dq.back()];
    }
}

void getMin() {
    dq.clear();
    for(int i=1; i<k; i++) {
        while(!dq.empty() &&a[dq.front()] >= a[i])
            dq.pop_front();
        dq.push_front(i);
    }
    for(int i=k; i<=n; i++) {
        while(!dq.empty() && a[dq.front()]>= a[i])
            dq.pop_front();
        dq.push_front(i);
        while(i-dq.back()+1>k)
            dq.pop_back();
        mi[i] = a[dq.back()];
    }
}

int main() {
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    getMax();
    getMin();
    for(int i=k; i<=n; i++)
        printf("%d ", mi[i]);
    cout<<endl;
    for(int i=k; i<=n; i++)
        printf("%d ", ma[i]);
    cout<<endl;
	
	return 0;
}
