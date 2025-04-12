#include<iostream>
using namespace std;

class Humidity;

class Temperature{
    private:
        float temperature;
    public:
        Temperature(float t): temperature(t) {}

        friend float calculateHeatIndex(Temperature t, Humidity h);
};

class Humidity{
    private:
        float humidity;
    public:
        Humidity(float h): humidity(h) {}

        friend float calculateHeatIndex(Temperature t, Humidity h);
};

float calculateHeatIndex(Temperature t, Humidity h){
    cout << "Heat Index: " << t.temperature* h.humidity << endl;
    return t.temperature* h.humidity;
}

int main(){
    Temperature temp(41.2);
    Humidity hum(60);
    calculateHeatIndex(temp, hum);
}