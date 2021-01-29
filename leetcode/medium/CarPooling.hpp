/*
 * @Author: gary.wang 
 * @Date: 2021-01-29 17:37:09 
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-29 17:47:38
 * 
 
   You are driving a vehicle that has capacity empty seats initially available for passengers.  
   The vehicle only drives east (ie. it cannot turn around and drive west.)

    Given a list of trips, trip[i] = [num_passengers, start_location, 
    end_location] contains information about the i-th trip: the number of passengers that must be picked up, 
    and the locations to pick them up and drop them off.  
    The locations are given as the number of kilometers due east from your vehicle's initial location.

    Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

 * 
 */
#include "../ITest.h"

class  CarPooling : public ITest
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> dict;
        for(auto trip : trips) {
            for(int j = trip[1];j<trip[2];j++) {
                dict[j] += trip[0];
                if(dict[j] > capacity) return false;
            }
        }
        return true;
    }
    void test()
    {
        vector<vector<int>> trips = {{3,2,7},{3,7,9},{8,3,9}};
        int capacity = 11;
        cout << carPooling(trips, capacity) << endl;

        trips = {{2, 1, 5}, {3, 3, 7}};
        capacity = 4;
        cout << carPooling(trips, capacity) << endl;

        trips = {{2, 1, 5}, {3, 3, 7}};
        capacity = 5;
        cout << carPooling(trips, capacity) << endl;
    }
};