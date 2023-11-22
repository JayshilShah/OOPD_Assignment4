#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>
#include "CarReport.h"

using namespace std;

int main(){
    vector<Reports> reports;
    CarReportDetails crs(reports);
    int flag = 1;
    int choice;
    while(flag == 1){
        cout << "1 to Show all car report details" << endl;
        cout << "2 to Add car report details" << endl;
        cout << "3 to Edit car report details" << endl;
        cout << "4 to Delete car report details" << endl;
        cout << "5 to Exit" << endl;
        cout << "Enter the choice you want to select : ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                crs.showReportDetails(reports);
                break;
            }
            case 2:
            {
                crs.addReportDetails(reports);
                break;
            }
            case 3:
            {
                crs.editReportByVehicleNumber(reports);
                break;
            }
            case 4:
            {
                crs.deleteReport(reports);
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