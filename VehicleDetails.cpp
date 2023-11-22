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

            if (it != vs.end()) {
                cout << "Enter new Address: ";
                cin.ignore(); 
                getline(cin, it->address);
                cout << "Address edited successfully!" << endl;
            } else {
                cout << "Vehicle details not found." << endl;
            }
        }
};

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