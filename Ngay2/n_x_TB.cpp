#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addDevices(vector<string> &device){
    string name;
    cout << "Enter Device's name: ";
    getline(cin, name);

    device.push_back(name);

    cout << "Device added successfully!" << endl;
}

void showDevices(const vector<string> &device){
    if (device.empty()){
        cout << "List Device empty!" << endl;
        return;
    } else {
        cout << "List devices: " << endl;
        for (int i = 0; i < device.size(); i++){
            cout << i + 1 <<". "<< device[i] << endl;
        }
    }
}

bool findDevices(const vector<string> device){
    if (device.empty()){
        return false;
    } else {
        string name;
        cout << "Enter Device's name: ";
        getline(cin, name);
        for (int i = 0; i < device.size(); i++){
            if (device[i] == name)
                return true;
        }
        return false;
    }
}

void menu(vector<string> &device, int choice) {
    do {
        cout << "\n===== DEVICE MANAGER =====" << endl;
        cout << "1. Add device" << endl;
        cout << "2. List devices" << endl;
        cout << "3. Find device" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1: 
                addDevices(device);
                break;
            case 2:
                showDevices(device);
                break;
            case 3:
                if (!findDevices(device)){
                    cout << "Device's name doesn't exist" << endl;
                } else {
                    cout << "The device name has been found" << endl;
                }
                break;
            case 0:
                cout << "Program ceased operations!" << endl;
                break;
            default:
                cout << "The choice isn't valid !" << endl;
                break;
        }
    } while (choice != 0);
}

int main () {
    vector<string> devices;
    int choice;

    menu(devices, choice);
    
    return 0;
}