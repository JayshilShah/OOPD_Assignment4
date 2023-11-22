#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>
#include "Vehicle.h"

using namespace std;

int main(){
    vector<Vehicles> vehicles;
    VehicleDetails vd(vehicles);
    int flag = 1;
    int choice;
    while(flag == 1){
        cout << "1 to Show all vehicle details" << endl;
        cout << "2 to Add vehicle details" << endl;
        cout << "3 to Edit vehicle details" << endl;
        cout << "4 to Delete vehicle details" << endl;
        cout << "5 to Exit" << endl;
        cout << "Enter the choice you want to select : ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                vd.showVehicleDetails(vehicles);
                break;
            }
            case 2:
            {
                vd.addVehicleDetails(vehicles);
                break;
            }
            case 3:
            {
                vd.editAddressByVehicleNumber(vehicles);
                break;
            }
            case 4:
            {
                vd.deleteVehicleNumber(vehicles);
                break;
            }
            case 5:
            {                    
                flag = 0;
                break;
            }
            default:
            {
                assert(false && "The choice must be between 1 to 5.");
                break;
            }
        }
    }
            
    return 0;
}