#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int N;
vector<pair<long long, long long>> data;

int main() {
    cin>>N;
    data.resize(N);
    long long d, p;
    for(int i=0; i<N; i++) {
        cin>>d>>p;
        data[i] = make_pair(d, p);
    }
    sort(data.begin(), data.end());
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long ans = 0;
    for(int i=0; i<N; i++) {
        if(data[i].first>pq.size()) {
            pq.push(data[i].second);
            ans += data[i].second;
        }
        else{
            if(data[i].second > pq.top()) {
                ans = ans - pq.top() + data[i].second;
                pq.pop();
                pq.push(data[i].second);
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
