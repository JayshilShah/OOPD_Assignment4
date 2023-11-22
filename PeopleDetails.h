#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <bits/stdc++.h>
#include <vector>
#include "CarReport.h"

using namespace std;

class People{
    public:
        string firstName;
        string lastName;
        int age;
        string gender;
        string address;
};

class PeopleDetails{
    public:
        PeopleDetails(vector<People>& people){
            ifstream data;
            string temp;
            data.open("A4-Q3.csv", ios::in);
            string line;
            getline(data, line);
            while(getline(data, line)){
                People p;
                istringstream s(line);
                getline(s, p.firstName, ',');
                getline(s, p.lastName, ',');
                getline(s, temp, ',');
                p.age = stoi(temp);
                getline(s, p.gender, ',');
                getline(s, p.address, ',');

                people.push_back(p);;
            }
        }
        void showPeopleDetails(vector<People>& people){
            cout << "First Name\tLast Name\tAge\tGender\tAddress" << endl;
            for_each(people.begin(), people.end(), [](const People& p){
                cout << left << setw(10) << p.firstName << "\t" << left << setw(10) << p.lastName << "\t" << p.age << "\t" << p.gender << "\t" << p.address << endl;
            });
        }
        void getAddress(vector<People>& people, string name, int age, string gender, string address, vector<string>& addresses){
            for (const auto& person : people) {
                if (((person.firstName+person.lastName) == name && person.age == age && person.gender == gender)
                || ((person.firstName+person.lastName) == name && person.age == age) || (person.age == age && person.gender == gender)
                || ((person.firstName+person.lastName) == name && person.gender == gender)) {
                    addresses.push_back(person.address);
                }
            }
        }
};