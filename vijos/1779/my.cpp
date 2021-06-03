#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> p;

vector<int> mul(vector<int> a, int b) {
    vector<int> res;
    int c = 0;
    for(int i=0; i<a.size()||c; i++) {
        if(i<a.size())
            c += a[i] * b;
        res.push_back(c%10);
        c = c / 10;
    }
    return res;
}

vector<int> divd(vector<int> a, int b) {
    vector<int> res;
    int c = 0;
    for(int i=a.size()-1; i>=0; i--) {
        c = c*10 + a[i];
        int d = c / b;
        if(d || !res.empty())
            res.push_back(d);
        c %= b;
    }
    reverse(res.begin(), res.end());
    if(res.empty())
        res.push_back(0);
    return res;
}

vector<int> maxVectorInt(vector<int> a, vector<int> b) {
    if(a.size() != b.size())
        return a.size()>b.size()? a: b;
    for(int i=a.size()-1; i>=0; i--) {
        if(a[i]!=b[i])
            return a[i]>b[i]?a: b;
    }
    return a;
}

int main() {
    cin>>n;
    p.resize(n+1);
    cin>>p[0].first>>p[0].second;
    int a, b;
    for(int i=1; i<=n; i++) {
        cin>>a>>b;
        p[i] = make_pair(a*b, b);
    }
    sort(p.begin()+1, p.end());
    vector<int> res(1, 0);
    vector<int> prod(1, 1);
    prod = mul(prod, p[0].first);
    for(int i=1; i<=n; i++) {
        res = maxVectorInt(res, divd(prod, p[i].second));
        prod = mul(prod, p[i].first / p[i].second);
    }
    for(int i=res.size()-1; i>=0; i--) {
        printf("%d", res[i]);
    }
    cout<<endl;
	return 0;
}

