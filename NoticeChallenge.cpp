#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Evidence{
    public:
        string vehicleNumber;
        string witnesses;
        string detailsOfViolation;
        string responseOfPerson;
        string ownerName;
        int age;
        string gender;
        string address;
};

class ViolationDetails{
    public:
        void addNoticeChallenges(vector<Evidence>& evid, vector<Vehicles>& vehicles){
            string vehicleNo;
            Evidence evids;
            cout << "Enter Vehicle Number: ";
            cin >> vehicleNo;
            cin.ignore();
            cout << "Enter the name of witnesses: ";
            getline(cin, evids.witnesses);
            cout << "Enter the details of violation: ";
            getline(cin, evids.detailsOfViolation);
            cout << "Enter the response of person: ";
            getline(cin, evids.responseOfPerson);

            auto it = find_if(vehicles.begin(), vehicles.end(), [vehicleNo](const Vehicles& vs) {
                return vs.vehicleNumber == vehicleNo;
            });

            if (it != vehicles.end()) {
                evids.ownerName = it->ownerName;
                evids.age = it->age;
                evids.gender = it->gender;
                evids.address = it->address;   
                evids.vehicleNumber = it->vehicleNumber;             
            }
            else
                cout << "Vehicle Details not found." << endl;

            evid.push_back(evids);
            cout << "Details are added successfully !" << endl;
        }
        void showChallengeDetails(vector<Evidence>& evid){
            for_each(evid.begin(), evid.end(), [](const Evidence& es){
                cout << "Vehicle Number: " << es.vehicleNumber << endl;
                cout << "Name of Witnesses: " << es.witnesses << endl;
                cout << "Details: " << es.detailsOfViolation << endl;
                cout << "Respons of Person: " << es.responseOfPerson << endl;
                cout << "Owner Name: " << es.ownerName << endl;
                cout << "Age: " << es.age << endl;
                cout << "Gender: " << es.gender << endl;
                cout << "Address: " << es.address << endl << endl << endl;
            });
        }
};

int main(){
    vector<Vehicles> vehicles;
    VehicleDetails vd(vehicles);
    vector<Evidence> evid;
    ViolationDetails vds;
    int choice, flag = 0;
 
    while(!flag){
        cout << "Enter 1 to add challenge details" << endl;
        cout << "Enter 2 to show list of challenges" << endl;
        cout << "Enter 3 to exit" << endl;
        cin >> choice;
        if(choice == 1){
            vds.addNoticeChallenges(evid, vehicles);
        }
        else if(choice == 2){
            vds.showChallengeDetails(evid);
        }
        else if(choice == 3){
            flag = 1;
        }
        else
            cout << "Enter correct choice next time:" << endl; 
    }

    return 0;
}