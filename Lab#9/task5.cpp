#include<iostream>
using namespace std;

class Activity{
    public:
        virtual void calculateCaloriesBurned() = 0;
        virtual ~Activity() {}
};

class Running: public Activity{
    private:
        double distance;
        double time;
    public:
        Running(double d, double t):distance(d), time(t) {}

        void calculateCaloriesBurned()override{
            cout <<"Calories burned by running: " << 60 * distance << endl;
        }
};

class Cycling: public Activity{
    private:
        double speed;
        double time;
    public:
        Cycling(double s, double t):speed(s), time(t) {}

        void calculateCaloriesBurned()override{
            cout << "Calories burned by Cycling " << speed * time *3.5 << endl;
        }
};

int main(){
    Cycling c(25, 40);
    Running r(15, 20);

    c.calculateCaloriesBurned();
    r.calculateCaloriesBurned();
}