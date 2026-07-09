#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

class Device {
    private:
    std::string id;
    std::string name;
    bool connected = false;

    public:
    Device();
    Device(std::string id, std::string name);

    void setID(std::string id);
    void setName(std::string name);
    void setConnected();

    std::string getID() const;
    std::string getName() const;
    bool getconnected() const;

    void connect();
    void disconnect();
    std::string getConnectedText() const;
    void printInfo() const;
};

#endif