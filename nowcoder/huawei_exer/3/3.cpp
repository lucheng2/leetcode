#include <iostream>
using namespace std;

int main() {
    string input;
    cin>>input;
    int res = 0;
    int power = 1;
    for(int i = input.size()-1; i>=2; i--) {
        int v = input[i] >= 'A'? input[i]-'A'+10: input[i]-'0';
        res += v*power;
        power *= 16;
    }
    cout<<res<<endl;
}
