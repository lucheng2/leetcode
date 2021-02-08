#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int main() {
    int n, t, k, tmp;
    scanf("%d", &n);
    map<int, map<int, vector<int>, greater<int>>, greater<int>> pro;
    vector<int> time;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &t, &k);
        tmp = t*k;
        map<int, map<int, vector<int>, greater<int>>, greater<int>>::iterator tmap;
        if((tmap = pro.find(tmp)) != pro.end()){
            if((tmap->second).find(t) != (tmap->second).end() ) {
                ((tmap->second).find(tmp)->second).emplace_back(i+1);
            }
            else{
                vector<int> v2;
                v2.emplace_back(i+1);
                (tmap->second)[t] = v2;
            }
        }
        else {
            vector<int> v;
            v.emplace_back(i+1);
            map<int, vector<int>, greater<int>> m;
            m[t] = v;
            pro[tmp] = m;
        }
    }
   map<int, map<int, vector<int>, greater<int>>, greater<int>>::iterator it; 
   map<int, vector<int>, greater<int>>::iterator it2;
    for(it=pro.begin(); it!=pro.end(); it++) {
        for (it2 = (it->second).begin(); it2!=(it->second).end(); it2++) {
            sort((it2->second).begin(), (it2->second).end());
            for(auto i: it2->second)
                printf("%d ", i);
        }
    }
	
	return 0;
}
