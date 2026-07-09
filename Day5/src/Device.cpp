#include "Device.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Device::Device(string id, string name) : id(id), name(name){}

Device::Device() = default;

//setter
void Device::setID(string id){
    if(!id.empty()){
        this->id = id;
    }
}

void Device::setName(string name){
    if(!name.empty()){
        this->name = name;
    }
}

void Device::setConnected(){
    if(connected == true){
        this->connected = false;
    } else {
        this->connected = true;
    }
}

//getter
string Device::getID () const {
    return id;
}

string Device::getName () const {
    return name;
}

bool Device::getconnected() const {
    return connected;
}

//function
void Device::connect (){
    if (connected == false){
        setConnected();
    }
    cout << "Connected successfully!" << endl;
}

void Device::disconnect(){
    if (connected == true){
        setConnected();
    }
    cout << "Disconnected successfully!" << endl;
}

string Device::getConnectedText() const {
    if (getconnected()){
        return "Connected";
    } else {
        return "Disconnected";
    }
}

void Device::printInfo() const {
    cout << "\n|ID      | Name                 | Status                 |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(8) << id
            << " | " << left << setw(20) << name
            << " | " << left << setw(20) << getConnectedText() << endl;
}