#include <iostream>
#include <string>
using namespace std;

class Engine
{
public:
    void start()
    {
        cout << "Started." << endl;
    }
};

class Car
{
private:
    Engine engine;

public:
    void drive()
    {
        engine.start();
        cout << "Car is driving" << endl;
    }
    void hunk()
    {
        cout << "BEEP" << endl;
    }
};

class Driver
{
public:
    void drive(Car &c)
    {
        c.hunk();
        cout << "Driver is driving the car." << endl;
    }
};

int main()
{
    Car object;
    object.drive();

    Driver d;
    d.drive(object);
    return 0;
}