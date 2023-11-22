#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Vehicles{
    public:
        string vehicleNumber;
        string ownerName;
        int age;
        string gender;
        string address;
};

bool isInteger(const string &str)
{
    istringstream ss(str);
    int n;
    ss >> n;
    return !ss.fail() && ss.eof();
}

class VehicleDetails{
    public:
        VehicleDetails(vector<Vehicles>& vehicles){
            ifstream data;
            string temp, temp1;
            data.open("A4-Q1.csv", ios::in);
            string line;
            getline(data, line);
            while(getline(data, line)){
                Vehicles vs;
                istringstream s(line);
                getline(s, temp, ',');
                getline(s, temp1, ',');
                vs.vehicleNumber = temp + temp1;

                getline(s, temp, ',');
                getline(s, temp1, ',');
                vs.ownerName = temp + " " + temp1;

                getline(s, temp, ',');
                vs.age = stoi(temp);

                getline(s, vs.gender, ',');
                getline(s, vs.address, ',');

                vehicles.push_back(vs);;
            }
        }
        void showVehicleDetails(vector<Vehicles>& vs){
            cout << "Vehicle Number \tOwner Name\t\tAge\tGender\tAddress" << endl;
            for_each(vs.begin(), vs.end(), [](const Vehicles& vs){
                cout << vs.vehicleNumber << "\t" << left << setw(20) << vs.ownerName << "\t" << vs.age << "\t" << vs.gender << "\t" << vs.address << endl;
            });
        }
        void addVehicleDetails(vector<Vehicles>& vs){
            string age;
            Vehicles vehicle;
            cout << "Enter the Vehicle Number: ";
            cin >> vehicle.vehicleNumber;
            cin.ignore();
            cout << "Enter the Vehicle Owner Name (FirstName LastName): ";
            getline(cin, vehicle.ownerName);
            cout << "Enter the Owner Age(Integer only): ";
            cin >> age;
            assert((isInteger(age) && vehicle.age>18 && vehicle.age<=100) && "The age must be integer and greater than 18.");
            istringstream(age) >> vehicle.age;
            cout << "Enter the Owner Gender(Male/Female): ";
            cin >> vehicle.gender;
            cin.ignore();
            cout << "Enter the Owner Address: ";
            getline(cin, vehicle.address);

            vs.push_back(vehicle);
            cout << "Vehicle details added successfully !" << endl;
        }
        void deleteVehicleNumber(vector<Vehicles>& vs) {
            string vehicleNumber;
            cout << "Enter Vehicle Number to delete: ";
            cin >> vehicleNumber;
            
            auto it = remove_if(vs.begin(), vs.end(), [vehicleNumber](const Vehicles& vehicle) {
                return vehicle.vehicleNumber == vehicleNumber;
            });

            if (it != vs.end()) {
                vs.erase(it, vs.end());
                cout << "Vehicle details Deleted successfully!" << endl;
            } else {
                cout << "Vehicle details not found." << endl;
            }
        }
        void editAddressByVehicleNumber(vector<Vehicles>& vs) {
            string vehicleNumber;
            cout << "Enter Vehicle Number to edit address: ";
            cin >> vehicleNumber;

            auto it = find_if(vs.begin(), vs.end(), [vehicleNumber](const Vehicles& vehicle) {
                return vehicle.vehicleNumber == vehicleNumber;
            });

            int editChoice;
            cout << "Enter 1 to edit Name" << endl;
            cout << "Enter 2 to edit Age" << endl;
            cout << "Enter 3 to edit Gender" << endl;
            cout << "Enter 4 to edit Address" << endl;
            cin >> editChoice;

            if (editChoice == 1){
                if (it != vs.end()) {
                    cout << "Enter correct Name: ";
                    cin.ignore(); 
                    getline(cin, it->ownerName);
                    cout << "Name edited successfully!" << endl;
                } else {
                    cout << "Vehicle details not found." << endl;
                }
            }
            else if (editChoice == 2){
                if (it != vs.end()) {
                    cout << "Enter correct Age: ";
                    cin >> it->age; 
                    cout << "Age edited successfully!" << endl;
                } else {
                    cout << "Vehicle details not found." << endl;
                }
            }
            else if (editChoice == 3){
                if (it != vs.end()) {
                    cout << "Enter correct Gender: ";
                    cin >> it->gender; 
                    cout << "Gender edited successfully!" << endl;
                } else {
                    cout << "Vehicle details not found." << endl;
                }
            }
            else if (editChoice == 4){
                if (it != vs.end()) {
                    cout << "Enter new Address: ";
                    cin.ignore(); 
                    getline(cin, it->address);
                    cout << "Address edited successfully!" << endl;
                } else {
                    cout << "Vehicle details not found." << endl;
                }
            }
            else
                cout << "Enter correct choice next time." << endl;
        }
};