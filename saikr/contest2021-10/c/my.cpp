#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long


using namespace std;
const double zero = 1e-9;

struct point {
    ll x, y;
    point(ll x, ll y): x(x), y(y) {
    }
};

struct vec {
    ll x, y;
    vec(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

ll prod(vec v1, vec v2) {
    return v1.x*v2.y - v2.x* v1.y;
}

bool is_c(point a, point b, point c, point d) {
    vec ac = vec(a, c);
    vec ad = vec(a, d);
    vec bc = vec(b, c);
    vec bd = vec(b, d);
    vec ca = vec(c, a);
    vec cb = vec(c, b);
    vec da = vec(d, a);
    vec db = vec(d, b);
    return (prod(ac, ad) * prod(bc, bd) <= 0) && (prod(ca, cb) * prod(da, db) <= 0);

}

int main() {
    ll n, m;
    cin>>n>>m;
    if(n<2 || m<2) {
        cout<<"NO"<<endl;
        return 0;
    }
    ll x, y;
    vector<vector<ll>> red;
    vector<vector<ll>> yellow;
    for(ll i=0; i<n; i++) {
        cin>>x>>y;
        red.push_back({x, y});
    }
    for(ll i=0; i<m; i++) {
        cin>>x>>y;
        yellow.push_back({x, y});
    }
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            for(ll k=0; k<m; k++) {
                for(ll l=k+1; l<m; l++) {
                    point a = point(red[i][0], red[i][1]);
                    point b = point(red[j][0], red[j][1]);
                    point c = point(yellow[k][0], yellow[k][1]);
                    point d = point(yellow[l][0], yellow[l][1]);
                    if(is_c(a, b, c, d)) {
                        cout<<"YES"<<endl;
                        return 0;
                    }

                }
            }
        }
    }

    cout<<"NO"<<endl;
	return 0;
}
