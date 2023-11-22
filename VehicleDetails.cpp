#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>

using namespace std;
const int maxSize = 1000;
int vehicleCount = 0;

class Vehicles{
    public:
        string vehicleNumber;
        string ownerName;
        int age;
        string gender;
        string address;
};

class VehicleDetails{
    public:
        Vehicles vehicles[maxSize];
        VehicleDetails(){
            ifstream data;
            string temp, temp1;
            data.open("A4-Q1.csv", ios::in);
            string line;
            getline(data, line);
            while(getline(data, line)){
                istringstream s(line);
                getline(s, temp, ',');
                getline(s, temp1, ',');
                vehicles[vehicleCount].vehicleNumber = temp + temp1;

                getline(s, temp, ',');
                getline(s, temp1, ',');
                vehicles[vehicleCount].ownerName = temp + " " + temp1;

                getline(s, temp, ',');
                vehicles[vehicleCount].age = stoi(temp);

                getline(s, temp, ',');
                vehicles[vehicleCount].gender = temp;

                getline(s, temp, ',');
                vehicles[vehicleCount].address = temp;

                vehicleCount++;
            }
        }
        void showVehicleDetails(){
            cout << "Vehicle Number \tOwner Name\t\tAge\tGender\tAddress" << endl;
            for(int i = 0; i < vehicleCount; i++){
                cout << vehicles[i].vehicleNumber << "\t" << left << setw(20) << vehicles[i].ownerName << "\t" << vehicles[i].age << "\t" << vehicles[i].gender << "\t" << vehicles[i].address << endl;
            }
        }
};

int main(){
    VehicleDetails vd;
    vd.showVehicleDetails();
    return 0;
}

In this code, we havve read the csv file, store its data to the array of type class and then we printed the data of vehicles read from the csv file.