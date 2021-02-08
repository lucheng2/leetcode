#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class ParkingSystem {
public:
    int volume[4] = {0};
    ParkingSystem(int big, int medium, int small) {
        volume[1] = big;
        volume[2] = medium;
        volume[3] = small;
    }

    bool addCar(int carType) {
        if(carType<1 || carType>3)
            return false;
        if(volume[carType]>0) {
            volume[carType]--;
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
	
	return 0;
}
