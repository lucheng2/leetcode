#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        vector<pair<int, int>> vec;
        int count = 0;
        for(int i=0; i<apples.size(); ++i) {
            if(apples[i] != 0) {
                vector<pair<int, int>>::iterator it = vec.begin();
                for(; it!=vec.end(); ++it) {
                    if(it->first>days[i]) {
                        vec.emplace(it, make_pair(days[i], apples[i]));
                        break;
                    }
                }
                if(it==vec.end())
                    vec.emplace_back(make_pair(days[i], apples[i]));
            }
            if(!vec.empty()) {
                vec[0].second--;
                count++;
                for(auto it=vec.begin(); it!=vec.end(); ) {
                    if(it->first <=1 || it->second<=0) {
                        it = vec.erase(it);
                    }
                    else {
                        it->first --;
                        it++;
                    }
                }
            }
        }
        while(!vec.empty()) {
                vec[0].second--;
                count++;
                for(auto it=vec.begin(); it!=vec.end(); ) {
                    if(it->first <=1 || it->second<=0) {
                        it = vec.erase(it);
                    }
                    else {
                        it->first --;
                        it++;
                    }
                }
            }
        return count;
    }
};

int main() {
	
	return 0;
}
