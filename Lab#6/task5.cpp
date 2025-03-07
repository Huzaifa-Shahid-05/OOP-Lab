#include<iostream>
using namespace std;

class Device{
    public:
        int deviceID;
        bool status;

        Device(int d, bool s): deviceID(d), status(s){}

        void displayDetails(){
            cout << "Device ID: " << deviceID << endl;
            cout << "Status: " << status << endl;
        }
};

class SmartPhone:virtual public Device{
    public:
        float screenSize;

        SmartPhone(int d, bool s, float a): Device(d,s),screenSize(a){}

        void displayDetails(){
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << endl;
        }
};

class SmartWatch:virtual public Device{
    public:
        bool heartRateMonitor;

        SmartWatch(int d, bool s, bool h): Device(d,s), heartRateMonitor(h){}

        void displayDetails(){
            Device::displayDetails();
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
        }
};

class SmartWearable: public SmartPhone, public SmartWatch{
    public:
        int stepCounter;

        SmartWearable(int d, bool s, float a,bool h,int s1): Device(d, s), SmartPhone(d,s,a),SmartWatch(d,s,h),stepCounter(s1){}

        void displayDetails(){
            Device::displayDetails();
            cout << "Screen Size: " << screenSize << endl;
            cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
            cout << "Step Counter: " << stepCounter << endl;
        }
};

int main(){
    SmartWearable s(12345,true,6.9,false,1000);
    s.displayDetails();
}