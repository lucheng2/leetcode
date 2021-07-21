#include<iostream>
#include<vector>
#include<list>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#define ll long long 

using namespace std;

list<int> fun(vector<list<int>> &lists) {
    int n = lists.size();
    list<int> ans;
    int cnt = n;
    while(cnt) {
        int mx = INT_MAX, mx_id;
        for(int i=0; i<n; i++) {
            if(lists[i].size()) {
                if(lists[i].front() < mx)  {
                    mx = lists[i].front();
                    mx_id = i;
                }
            }
        }
        ans.push_back(mx);
        lists[mx_id].pop_front();
        if(lists[mx_id].size() == 0) {
            cnt --;
        }
    }
    return ans;
    
}


int main() {
    vector<list<int>> test;
    test.push_back({1, 4, 5});
    test.push_back({1, 3, 4});
    test.push_back({2, 6});
    list<int> ans = fun(test);
    for(auto i: ans)
        printf("%d ", i);

}
