/*
 * @Author: gary.wang 
 * @Date: 2020-11-09 14:09:05 
 * @Last Modified by:   gary.wang 
 * @Last Modified time: 2020-11-09 14:09:05 
 

    Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small,
    with a fixed number of slots for each size.

    Implement the ParkingSystem class:

    ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. 
    The number of slots for each parking space are given as part of the constructor.
    bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. 
    carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively.
    A car can only park in a parking space of its carType. If there is no space available, 
    return false, else park the car in that size space and return true.

 * 
 */
#include "../ITest.h"

class ParkingSystem : public ITest
{
private:
    // int _big;
    // int _medium;
    // int _small;
    int carParking[3];

public:
    ParkingSystem() {}
    ParkingSystem(int big, int medium, int small)
    {
        // _big = big;
        // _medium = medium;
        // _small = small;
        carParking[0] = big;
        carParking[1] = medium;
        carParking[2] = small;
    }

    bool addCar(int carType)
    {
        // bool ret = true;
        // switch (carType)
        // {
        // case 1:
        //     ret = _big-- > 0;
        //     break;
        // case 2:
        //     ret = _medium-- > 0;
        //     break;
        // case 3:
        //     ret = _small-- > 0;
        //     break;

        // default:
        //     break;
        // }
        // return ret;
        return carParking[carType - 1]-- > 0;
    }

    void test()
    {
        ParkingSystem ps1(1, 1, 0);
        cout << ps1.addCar(1) << endl;
        cout << ps1.addCar(2) << endl;
        cout << ps1.addCar(3) << endl;
        cout << ps1.addCar(1) << endl;
    }
};