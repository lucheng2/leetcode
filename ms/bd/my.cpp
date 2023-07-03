#include<iostream>

using namespace std;

int a[26], b[26], n=26, c[26];

int main() {
    for(int i=0; i<n; i++) 
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];
    int acc = 0;
    for(int i=0; i<n; i++) {
        int d = c[i] ;
        if(d + acc + 3*b[i] < a[i]) {
            cout<<-1<<endl;
            return 0;
        }
        if(i<n-3) {
            if(d + acc + b[i] >= a[i]) {
                acc+=b[i];
            } else {
                c[i] += b[i]*3;
                c[i+1] += b[i]*3;
                c[i+2] += b[i]*3;
            }
        } else {
                c[i] += b[i]*3;
                c[i+1] += b[i]*3;
                c[i+2] += b[i]*3;
        }
    }
    int d = c[25];
    cout<<acc + d<<endl;
}
