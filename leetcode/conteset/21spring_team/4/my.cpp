#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    int maxGroupNumber(vector<int>& tiles) {
        map<int, int> hm;
        map<int, int> shun;
        for(int t: tiles) {
            hm[t] ++;
        }
        int count = 0;
        for(auto &[key, value]: hm) {
            while(hm[key] > 0) {
                if(hm.count(key+1) && hm[key+1]>0 && hm.count(key+2) && hm[key+2]) {
                    int mi = min(min(hm[key], hm[key+1]), hm[key+2]);
                    shun[key] += mi;
                    hm[key] -=mi;
                    hm[key+1]-=mi;
                    hm[key+2]-= mi;
                    count += mi;
                }
                else {
                    break;
                }
            }
        }
        for(auto &[key, value]: hm) {
            if(hm[key] >= 3) {
                int m = hm[key]/3;
                count += m;
                hm[key] -= m * 3;
            }
        }
        for(auto &[key, value]: hm) {
            bool flag = true;
            int n;
            while(hm[key] > 0 && flag) {
                if(hm.count(key+1) && hm[key+1]>0) {
                    n=0;
                    while(shun.count(key+n*3+2) && shun[key+n*3+2]>0) {
                        if(hm.count(key+n*3+5) && hm[key+n*3+5]>0 ){
                            count++;
                            hm[key] --;
                            hm[key+1] --;
                            hm[key+n*3+5] --;
                            shun[key+n*3+2] --;
                            shun[key+n*3+3]++;
                            break;
                        }
                        n++;
                    }
                    flag = false;
                }
                else {
                    flag = false;
                }
            }
        }
        for(auto &[key, value]: hm) {
            bool flag = true;
            int n;
            while(hm[key] > 0 && flag) {
                if(hm.count(key+2) && hm[key+2]>0) {
                    n=0;
                    while(shun.count(key+n*3+1) && shun[key+n*3+1]>0) {
                        if(hm.count(key+n*3+4) && hm[key+n*3+4]>0 ){
                            count++;
                            hm[key] --;
                            hm[key+2] --;
                            hm[key+n*3+4] --;
                            shun[key+n*3+1] --;
                            shun[key+n*3+2]++;
                            break;
                        }
                        n++;
                    }
                    flag = false;
                }
                else {
                    flag = false;
                }
            }
        }
        for(auto &[key, value] : hm) {
            if(hm[key] >=2) {
                int n=0;
                while(shun.count(key+n*3) && shun[key+n*3]>0) {
                    if(hm.count(key+n*3+3) && hm[key+n*3+3]>0){ 
                        count++;
                        hm[key] -= 2;
                        hm[key+3+n*3] --;
                        shun[key]--;
                        shun[key+1+n*3]++;
                        break;
                    }
                    n++;
                }
            }
        }
        for(auto &[key,value]:hm) {
            if(hm[key]>1 && hm.count(key+1) && hm[key+1]>1 && shun.count(key) && shun[key]>0){
                count++;
                hm[key] -= 2;
                hm[key+1] -= 2;
                hm[key+2] ++;
                shun[key] --;
            }
            if(hm[key]>1 && hm.count(key+2) && hm[key+2]>1 && shun.count(key) && shun[key]>0) {
                count++;
                hm[key] -= 2;
                hm[key+2] -= 2;
                hm[key+1] ++;
                shun[key] --;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> t = {2,2,2,3,3,3,4,5,5,5,6,7,7,7,8,10,10,10,9};
    int ans = s.maxGroupNumber(t);
    printf("%d\n", ans);
	
	return 0;
}
