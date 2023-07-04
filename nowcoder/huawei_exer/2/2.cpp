#include <iostream>
using namespace std;

int h[505];

int main() {
    int N;
    cin>>N;
    int input;
    for (int i=0; i<N; i++) {
        cin>>input;
        h[input] = 1;
    }
    for(int i=0; i< 505; i++) {
        if(h[i] == 1) {
            cout<<i<<endl;
        }
    }
}
