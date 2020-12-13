#include<iostream>
#include<vector>

using namespace std;

/**
* ����k�ж��ʤ���߶���arr�����У�����һ�α�����
* ����arr�����е����ֵ֮ǰ��û������������ʤ���ߣ���ôʤ����һ����������ֵ��
* ������һ�ξͻ�����arr�����е����ֵ����������ľͲ����ٿ��ǡ�
**/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int preNum = arr[0], winCount = 0, max = preNum;
        for (int i = 1; i < arr.size(); i++) {
            if (preNum > arr[i]) {
                winCount++;
            }
            else
            {
                max = preNum = arr[i];
                winCount = 1;
            }
            if (winCount >= k) {
                return preNum;
            }
        }
        return max;
    }
};

int main() {
    vector<int> arr = { 3,2,1 };
    Solution solution;
    int result = solution.getWinner(arr, 2);
    return 0;
}