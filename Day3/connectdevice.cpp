#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Device {
    private:
    string id;
    string name;
    bool connected = false;

    public:
    Device(string id, string name) : id(id), name(name){}

    Device() = default;

    //setter
    void setID(string id){
        if(!id.empty()){
            this->id = id;
        }
    }

    void setName(string name){
        if(!name.empty()){
            this->name = name;
        }
    }

    void setConnected(){
        if(connected == true){
            this->connected = false;
        } else {
            this->connected = true;
        }
    }

    //getter
    string getID () const {
        return id;
    }

    string getName () const {
        return name;
    }

    bool getconnected() const {
        return connected;
    }

    //function
    void connect (){
        if (connected == false){
            setConnected();
        }
        cout << "Connected successfully!" << endl;
    }

    void disconnect(){
        if (connected == true){
            setConnected();
        }
        cout << "Disconnected successfully!" << endl;
    }

    string getconnectedtext() const {
        if (getconnected()){
            return "Connected";
        } else {
            return "Disconnected";
        }
    }
};

void showInfoDevice(const vector<Device> &Lstdevices){
        if (Lstdevices.empty()){
            return;
        }
        cout << "\n|ID      | Name                 | Status                 |" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (const auto &dev : Lstdevices){
            cout << left << setw(8) << dev.getID() 
                 << " | " << left << setw(20) << dev.getName() 
                 << " | " << left << setw(20) << dev.getconnectedtext() << endl;
        }
    }

    void addDevice(vector<Device> &Lstdevices){
        Device dv1;
        string id;
        string name;
        cout << "Enter device ID: ";
        getline(cin, id);
        dv1.setID(id);
        cout << "Enter device name: ";
        getline(cin, name);
        dv1.setName(name);

        Lstdevices.push_back(dv1);
        cout << "Add device successfully!" << endl;
    }

int main() {
    vector<Device> Listdevice;
    addDevice(Listdevice);
    showInfoDevice(Listdevice);
    addDevice(Listdevice);
    Listdevice[1].connect();
    showInfoDevice(Listdevice);
    Listdevice[1].disconnect();
    showInfoDevice(Listdevice); 
    return 0;
}