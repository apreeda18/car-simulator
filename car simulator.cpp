#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Base class
class Car {
protected:
    string brand;
    int speed;
    int fuel;
    bool isOn;

public:
    Car(const string& b) : brand(b), speed(0), fuel(100), isOn(false) {}

    virtual void start() {
        if (!isOn && fuel > 0) {
            isOn = true;
            cout << brand << " car started.\n";
        } else if (fuel <= 0) {
            cout << "Fuel empty! Cannot start the car.\n";
        } else {
            cout << "Car is already on.\n";
        }
    }

    virtual void stop() {
        if (isOn) {
            isOn = false;
            speed = 0;
            cout << brand << " car stopped.\n";
        } else {
            cout << "Car is already off.\n";
        }
    }

    virtual void accelerate() {
        if (isOn && fuel > 0) {
            speed += 10;
            fuel = max(0, fuel - 5);
            cout << brand << " accelerated. Speed: " << speed << " km/h, Fuel: " << fuel << "%\n";
        } else {
            cout << "Start the car or check fuel.\n";
        }
    }

    virtual void brake() {
        if (speed > 0) {
            speed = max(0, speed - 10);
            cout << brand << " braking... Speed: " << speed << " km/h\n";
        } else {
            cout << brand << " is already stopped.\n";
        }
    }

    void checkFuel() const {
        cout << brand << " Fuel level: " << fuel << "%\n";
    }

    virtual ~Car() = default;
};

// Derived class with Nitro Boost
class SportsCar : public Car {
public:
    SportsCar(const string& b) : Car(b) {}

    void accelerate() override {
        if (isOn && fuel > 0) {
            speed += 20;
            fuel = max(0, fuel - 10);
            cout << brand << " sports car zooms! Speed: " << speed << " km/h, Fuel: " << fuel << "%\n";
        } else {
            cout << "Start the car or check fuel.\n";
        }
    }

    void nitroBoost() {
        if (isOn && fuel >= 20) {
            speed += 50;
            fuel -= 20;
            cout << "?? Nitro Boost activated! Speed: " << speed << " km/h, Fuel: " << fuel << "%\n";
        } else {
            cout << "? Not enough fuel for Nitro Boost or car is off.\n";
        }
    }
};

int main() {
    Car myCar("Toyota");
    SportsCar mySport("Ferrari");

    cout << "\n--- Regular Car Simulator ---\n";
    myCar.start();
    myCar.accelerate();
    myCar.brake();
    myCar.checkFuel();
    myCar.stop();

    cout << "\n--- Sports Car Simulator ---\n";
    mySport.start();
    mySport.accelerate();
    mySport.accelerate();
    mySport.nitroBoost();
    mySport.brake();
    mySport.checkFuel();
    mySport.stop();

    return 0;
}

