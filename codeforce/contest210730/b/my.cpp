#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main() {
    int t, W, H, x1, x2, y1, y2, w, h;
    cin>>t;
    while(t) {
        t--;
        cin>>W>>H;
        cin>>x1>>y1>>x2>>y2;
        cin>>w>>h;
        if(x2-x1+w>W && y2-y1+h>H) {
            cout<<-1<<endl;
            continue;
        }
        double ans = 1e9;
        double x = (double)W / 2.0, y = (double)H / 2.0;
        double xx, yy;
        for(int i=0; i<4; i++) {
            switch (i)  {
                case 0:
                    xx = x1, yy = y1;
                    break;
                case 1:
                    xx = x1, yy = 2*y - y2;
                    break;
                case 2:
                    xx = 2*x - x2, yy = y1;
                    break;
                case 3:
                    xx = 2*x - x2, yy = 2*y - y2;
                    break;
            }
            if(w<=xx && h<=yy)
                ans = 0;
            if(w + x2 - x1<=W) 
                ans = min(ans, w - xx);
            if(h + y2 - y1<=H)
                ans = min(ans, h-yy);
            double ww = max(0.0, w - xx), hh = max(0.0, h - yy);
            ans = min(ans, sqrt(ww*ww + hh*hh));
        }
        printf("%.6lf\n", ans);
    }
	
	return 0;
}
