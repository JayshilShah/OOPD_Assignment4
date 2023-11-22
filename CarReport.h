#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Reports{
    public:
        string vehicleNumber;
        string source;
        string location;
};

class CarReportDetails{
    public:
        CarReportDetails(vector<Reports>& reports){
            ifstream data;
            string temp, temp1;
            data.open("A4-Q2.csv", ios::in);
            string line;
            getline(data, line);
            while(getline(data, line)){
                Reports rs;
                istringstream s(line);
                getline(s, temp, '"');
                getline(s, temp, ',');
                getline(s, temp1, '"');
                rs.vehicleNumber = temp + temp1;

                getline(s, temp1, ',');
                getline(s, rs.source, ',');

                getline(s, rs.location, ',');

                reports.push_back(rs);;
            }
        }
        void showReportDetails(vector<Reports>& reports){
            cout << "Vehicle Number\tReport Source\tLocation" << endl;
            for_each(reports.begin(), reports.end(), [](const Reports& rs){
                cout << rs.vehicleNumber << "\t" << left << setw(15) << rs.source << "\t" << rs.location << endl;
            });
        }
        void addReportDetails(vector<Reports>& reports){
            Reports crs;
            cout << "Enter the Vehicle Number: ";
            cin >> crs.vehicleNumber;
            cout << "Enter the Source of the report (Manual_Report/Camera): ";
            cin >> crs.source;
            cin.ignore();
            cout << "Enter the Location of the report: ";
            getline(cin, crs.location);

            reports.push_back(crs);
            cout << "Report details added successfully !" << endl;
        }
        void deleteReport(vector<Reports>& reports) {
            string vehicleNumber;
            cout << "Enter Vehicle Number to delete: ";
            cin >> vehicleNumber;
            
            auto it = remove_if(reports.begin(), reports.end(), [vehicleNumber](const Reports& rs) {
                return rs.vehicleNumber == vehicleNumber;
            });

            if (it != reports.end()) {
                reports.erase(it, reports.end());
                cout << "Report details Deleted successfully!" << endl;
            } else {
                cout << "Car Report details not found." << endl;
            }
        }
        void editReportByVehicleNumber(vector<Reports>& reports) {
            string vehicleNumber;
            cout << "Enter Vehicle Number to edit address: ";
            cin >> vehicleNumber;

            auto it = find_if(reports.begin(), reports.end(), [vehicleNumber](const Reports& rs) {
                return rs.vehicleNumber == vehicleNumber;
            });

            int editChoice;
            cout << "Enter 1 to edit Source" << endl;
            cout << "Enter 2 to edit Location" << endl;
            cin >> editChoice;

            if (editChoice == 1){
                if (it != reports.end()) {
                    cout << "Enter correct Souce: ";
                    cin >> it->source;
                    cout << "Souce edited successfully!" << endl;
                } else {
                    cout << "Car Report details not found." << endl;
                }
            }
            else if (editChoice == 2){
                if (it != reports.end()) {
                    cin.ignore();
                    cout << "Enter correct Location: ";
                    getline(cin, it->location); 
                    cout << "Location edited successfully!" << endl;
                } else {
                    cout << "Car Report details not found." << endl;
                }
            }
            else
                cout << "Enter correct choice next time." << endl;
        }
};