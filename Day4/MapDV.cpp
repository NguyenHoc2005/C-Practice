#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <queue>
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

    void printInfo() const {
        cout << "\n|ID      | Name                 | Status                 |" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << left << setw(8) << id
                << " | " << left << setw(20) << name
                << " | " << left << setw(20) << connected << endl;
    }
};

void showInfoDevice(const map<string, Device> &Lstdevices){
        if (Lstdevices.empty()){
            return;
        }
        cout << "\n|ID      | Name                 | Status                 |" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (const auto &item : Lstdevices){
            const Device &dev = item.second;
            cout << left << setw(8) << dev.getID() 
                 << " | " << left << setw(20) << dev.getName() 
                 << " | " << left << setw(20) << dev.getconnectedtext() << endl;
        }
    }

void addDevice(map<string, Device> &Lstdevices){
    string id;
    string name;
    do {
        cout << "Enter device ID: ";
        getline(cin, id);
        if (id.empty()){
            cout << "ID cannot be empty!" << endl;
            continue;
        }
        //tim id trong map
        if (Lstdevices.find(id) != Lstdevices.end()){
            cout << "Device already exist" << endl;
            continue;
        }

        cout << "Enter device name: ";
        getline(cin, name);
        if (name.empty()){
            cout << "Name cannot empty!" << endl;
            continue;
        }
    } while (id.empty() || name.empty() || Lstdevices.find(id) != Lstdevices.end());

    Device dv1(id, name);

    Lstdevices[id] = dv1;

    cout << "Add device successfully!" << endl;
}

void findDevices(const map<string, Device> &Lstdevices){
    string id;
    cout << "Enter device ID: ";
    getline(cin, id);

    auto it = Lstdevices.find(id);
    if (it == Lstdevices.end()){
        cout << "Device doesn't exist!";
        return;
    }

    it->second.printInfo();
}

void connectDeviceByID(map<string, Device> &Lstdevices){
    if (Lstdevices.empty()){
        cout << "List device empty" << endl;
        return;
    }
    string id;
    cout << "Enter device ID: ";
    getline(cin, id);
    if (Lstdevices.find(id) == Lstdevices.end()){
        cout << "Device ID doesn't exist" << endl;
        return;
    }

    auto it = Lstdevices.find(id);
    it->second.connect();
}


void disconnectDeviceByID(map<string, Device> &Lstdevices){
    if (Lstdevices.empty()){
        cout << "List device empty" << endl;
        return;
    }
    string id;
    cout << "Enter device ID: ";
    getline(cin, id);
    if (Lstdevices.find(id) == Lstdevices.end()){
        cout << "Device ID doesn't exist" << endl;
        return;
    }

    auto it = Lstdevices.find(id);
    it->second.disconnect();
}

void addtask(queue<string> &tasks){
    string task;
    cout << "Enter a task: ";
    getline(cin, task);

    tasks.push(task);
    cout << "Add task succressfully!" << endl;
}

void dotask(queue<string> &tasks){
    cout << "Currently working: "<< tasks.front() << endl;
    tasks.pop();
    cout << "Task complete!" << endl;
}

void checktask(const queue<string> &tasks){
    cout << "Task oldest: " << tasks.front() << endl;
}

void CountTask(queue<string> tasks){
    while (!tasks.empty()){
        cout << tasks.front() << endl;
        tasks.pop();
    }
}

int main() {
    queue<string> tasks;
    tasks.push("Lay xe dop");
    tasks.push("di choi");
    tasks.push("di an");
    addtask(tasks);
    CountTask(tasks);
    dotask(tasks);
    CountTask(tasks);
    checktask(tasks);
    cout << "Number of tasks: "<< tasks.size() << endl;
    return 0;
}