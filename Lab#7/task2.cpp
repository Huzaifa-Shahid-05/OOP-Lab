#include<iostream>
#include <cmath>
using namespace std;

struct Position{
    int x;
    int y;
};


class Shape{
    public:
        Position position;
        string color;
        float borderThickness;

        Shape(Position p, string c, float t): position(p), color (c), borderThickness(t){}

        virtual void draw(){
            cout << "Drawing Started" << endl ;
        }

        virtual float calculateArea(){
            cout << "Calculating area" << endl;
            return 0;
        };
        virtual float calculatePerimeter(){
            cout << "Calculating Perimeter" << endl;
            return 0;
        };
};

class Circle : public Shape{
    public:
        float radius;
        Position center;

        Circle(Position p, string c, float t, float r, Position d): Shape(p,c,t), radius(r),center(d) {}

        void draw() override{
            cout << "Drawing a circle" << endl; 
        }
        float calculateArea() override{
            cout << "Area: " << 3.142*radius*radius << endl;
            return 3.142*radius*radius;
        }
        float calculatePerimeter() override{
            cout << "Perimeter: " << 3.142*2*radius << endl;
            return 3.142*2*radius;
        }
};

class Rectangle : public Shape{
    public:
        float width, height;
        Position topLeft;

        Rectangle(Position p, string c, float t, float w, float h, Position d): Shape(p,c,t), width(w),height(h),topLeft(d) {}

        void draw() override{
            cout << "Drawing a Rectangle" << endl; 
        }
        float calculateArea() override{
            cout << "Area: " << height*width << endl ;
            return height*width;
        }
        float calculatePerimeter() override{
            cout << "Perimeter: " << height+height+width+width << endl;
            return height+height+width+width;
        }
};

class Triangle : public Shape{
    public:
        float s1,s2,s3;
        Position TopCorner;

        Triangle(Position p, string c, float t, float x, float y, float z, Position to): Shape(p,c,t),s1(x),s2(y),s3(z),TopCorner(to){}

        void draw() override{
            cout << "Drawing a Triangle" << endl; 
        }
        float calculateArea() override{
            float s = (s1 + s2 + s3) / 2;
            cout << "Area: " << sqrt(s*(s-s1)*(s-s2)*(s-s3)) << endl;
            return sqrt(s * (s - s1) * (s - s2) * (s - s3));
        }
        float calculatePerimeter() override{
            cout << "Perimeter: " << s1+s2+s3 << endl;
            return s1+s2+s3; 
        }
};

class Polygon : public Shape {
    public:
        float sideLength;
        int numSides;
    
        Polygon(Position p, string c, float t, int n, float s) : Shape(p, c, t), numSides(n), sideLength(s) {}
    
        void draw() override {
            cout << "Drawing a Polygon" << endl;
        }
    
        float calculatePerimeter() override {
            cout << "Perimeter: " << numSides * sideLength << endl;
            return numSides * sideLength;
        }
};

int main(){
    Position p = {0,0};
    Circle c(p,"Black",1.5,10,p);
    Rectangle r(p, "Blue", 2.0,5,10,p);
    Triangle t(p, "Green", 1.2,3,4,5,p);
    Polygon x(p, "Yellow", 1.0,6,4);

    c.draw();
    c.calculateArea();
    c.calculatePerimeter();
    cout << endl;

    r.draw();
    r.calculateArea();
    r.calculateArea();
    cout << endl;

    t.draw();
    t.calculateArea();
    t.calculatePerimeter();
    cout << endl;

    x.draw();
    x.calculateArea();
    x.calculatePerimeter();

    return 0;
}