#include<iostream>
using namespace std;

class SmartDevice{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool getStatus() = 0;

        virtual ~SmartDevice() {}
};

class LightBulb: public SmartDevice{
    private:
        bool isOn;
        int brightness;
    public:
        LightBulb(bool o, int b):isOn(o), brightness(b){}

        void turnOn()override{
            cout << "Light Bulb is turning on." << endl;
            isOn = true;
        }
        void turnOff()override{
            cout << "Light Bulb is turning off." << endl;
            isOn = false;
        }
        bool getStatus()override{
            cout << "Light Bulb Status: " << isOn << endl;
            return isOn;
        }
};

class Thermostat: public SmartDevice{
    private:
        bool isOn;
        double temperature;
    public:
        Thermostat(bool o, int b):isOn(o), temperature(b){}

        void turnOn()override{
            cout << "Thermostat is turning on." << endl;
            isOn = true;
        }
        void turnOff()override{
            cout << "Thermostat is turning off." << endl;
            isOn = false;
        }
        bool getStatus()override{
            cout << "Thermostat Status: " << isOn << endl;
            return isOn;
        }
};

int main() {
    LightBulb bulb(false, 75);
    Thermostat thermo(false, 22.5);

    bulb.turnOn();
    thermo.turnOn();

    bulb.getStatus();
    thermo.getStatus();

    bulb.turnOff();
    thermo.turnOff();

    bulb.getStatus();
    thermo.getStatus();

    return 0;
}