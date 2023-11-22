#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>
#include "Vehicle.h"
#include "PeopleDetails.h"

using namespace std;

int main(){
    vector<People> people;
    PeopleDetails pd(people);

    vector<Vehicles> vehicles;
    VehicleDetails vd(vehicles);

    vector<string> addresses;

    // pd.showPeopleDetails(people);
    // vd.showVehicleDetails(vehicles);

    string vehicleNumber, name, gender, address;
    int age;
    cout << "Enter Vehicle Number to search: ";
    cin >> vehicleNumber;

    auto it = find_if(vehicles.begin(), vehicles.end(), [vehicleNumber](const Vehicles& vs) {
        return vs.vehicleNumber == vehicleNumber;
    });

    if (it != vehicles.end()) {
        name = it->ownerName;
        age = it->age;
        gender = it->gender;
        address = it->address;
        pd.getAddress(people, name, age, gender, address, addresses);
        cout << "Probable addresses where the notice should be sent:" << endl;
        for (const auto& adrs : addresses) {
            cout << adrs << endl;
        }
    }
    else
        cout << "Vehicle Details not found." << endl;

    return 0;
}