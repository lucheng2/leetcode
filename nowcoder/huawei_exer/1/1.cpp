#include <iostream>
using namespace std;

int main() {
    int n;
    while(true) {
        cin>>n;
        if (n==0) {
            break;
        }

        int ans = 0;
        while(n >= 3) {
            int drink = n/3;
            int bottle = n%3;
            ans += drink;
            n = drink + bottle;
        }
        if (n==2) {
            ans += 1;
        }
        cout<<ans<<endl;
    }
    return 0;

}
