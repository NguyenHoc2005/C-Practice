#include <iostream>
#include <iomanip>
#include "Device.hpp"
#include <string>
#include <map>
#include <queue>

using namespace std;

//Exem Map
void showInfoDevice(const map<string, Device> &Lstdevices){
        if (Lstdevices.empty()){
            cout << "List device empty!!!" << endl;
            return;
        }
        cout << "\n|ID      | Name                 | Status                 |" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (const auto &item : Lstdevices){
            const Device &dev = item.second;
            cout << left << setw(8) << dev.getID() 
                 << " | " << left << setw(20) << dev.getName() 
                 << " | " << left << setw(20) << dev.getConnectedText() << endl;
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

//Bonus Exam
void deleteDeviceByID(map<string, Device> &Lstdevices){
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

    Lstdevices.erase(id);
}

void UpdateNameDeviceByID(map<string, Device> &Lstdevices){
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

    string name;
    cout << "Enter device name: ";
    getline(cin, name);

    auto it = Lstdevices.find(id);
    it->second.setName(name);
}

void CountDeviceConnected(const map<string, Device> &Lstdevices){
    if(Lstdevices.empty()){
        cout << "List device empty" << endl;
        return;
    }

    int count = 0;

    for (const auto &item : Lstdevices){
        const Device &dev = item.second;
        if (dev.getconnected()){
            count += 1;
        }
    }

    cout << "Device conected is: " << count << endl;
}

// Exam Queue
void addtask(queue<string> &tasks){
    string task;
    cout << "Enter a task: ";
    getline(cin, task);

    tasks.push(task);
    cout << "Add task succressfully!" << endl;
}

void dotask(queue<string> &tasks){
    if (tasks.empty()){
        cout << "No task to do!" << endl;
        return;
    }
    cout << "Currently working: "<< tasks.front() << endl;
    tasks.pop();
    cout << "Task complete!" << endl;
}

void checktask(const queue<string> &tasks){
    if (tasks.empty()){
        cout << "No task to check!" << endl;
        return;
    }
    cout << "Task oldest: " << tasks.front() << endl;
}

void CountTask(queue<string> tasks){
    if (tasks.empty()){
        cout << "No task to count!" << endl;
        return;
    }
    auto count = tasks.size();
    while (!tasks.empty()){
        cout << tasks.front() << endl;
        tasks.pop();
    }
    cout << "Total task: " << count << endl;
}

int main() {
    map<string, Device> Listdevices;
    queue<string> Task;
    int choice;

    Listdevices["dv1"] = Device("dv1", "Hieu Hoc");
    Listdevices["dv2"] = Device("dv2", "John Doe");
    Listdevices["dv3"] = Device("dv3", "Jane Smith");

    do {
        cout << "1. Add device" << endl;
        cout << "2. List device" << endl;
        cout << "3. Find device by ID" << endl;
        cout << "4. Connect device by ID" << endl;
        cout << "5. Disconnect device by ID" << endl;
        cout << "6. Delete device" << endl;
        cout << "7. Update name device by ID" << endl;
        cout << "8. Counting device connected" << endl;
        cout << "9. Add task" << endl;
        cout << "10. Do task" << endl;
        cout << "11. Check task" << endl;
        cout << "12. Counting task" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                addDevice(Listdevices);
                break;
            case 2:
                showInfoDevice(Listdevices);
                break;
            case 3:
                findDevices(Listdevices);
                break;
            case 4:
                connectDeviceByID(Listdevices);
                break;
            case 5:
                disconnectDeviceByID(Listdevices);
                break;
            case 6:
                deleteDeviceByID(Listdevices);
                break;
            case 7:
                UpdateNameDeviceByID(Listdevices);
                break;
            case 8:
                CountDeviceConnected(Listdevices);
                break;
            case 9:
                addtask(Task);
                break;
            case 10:
                dotask(Task);
                break;
            case 11:
                checktask(Task);
                break;
            case 12:
                CountTask(Task);
                break;
            case 0:
                cout << "Program ceased operations!" << endl;
                break;
            default:
                cout << "The choice isn't valid !" << endl;   
                break;
        }
    } while (choice != 0);
    return 0;
}