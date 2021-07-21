#include<vector>

/**
 * 计数排序，仅支持[0, w]范围内的整数的排序
 */
std::vector<int> counting_sort(std::vector<int> & vec, int w) {
    std::vector<int> cnt(w+1, 0);
    std::vector<int> ans(vec.size());
    for(int i=0; i<vec.size(); i++) {
        cnt[vec[i]] ++;
    }
    for(int i=1; i<=w; i++) {
        cnt[i] += cnt[i-1];
    }
    for(int j=vec.size()-1; j>=0; j--) {
        ans[--cnt[vec[j]]] = vec[j];
    }
    return ans;
}
