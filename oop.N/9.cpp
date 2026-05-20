#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void changeGear(int newGear) = 0;
    virtual void speedUp(int increment) = 0;
    virtual void applyBrakes(int decrement) = 0;
    virtual void displayStatus() = 0;
};

class Bicycle : public Vehicle {
private:
    int speed = 0;
    int gear = 0;
public:
    void changeGear(int newGear) override {
        gear = newGear;
        cout << "Bicycle gear changed to: " << gear << endl;
    }
    void speedUp(int increment) override {
        speed += increment;
        cout << "Bicycle speed increased to: " << speed << " km/h" << endl;
    }
    void applyBrakes(int decrement) override {
        speed -= decrement;
        if(speed < 0) speed = 0;
        cout << "Bicycle slowed down to: " << speed << " km/h" << endl;
    }
    void displayStatus() override {
        cout << "Bicycle [Speed: " << speed << " km/h, Gear: " << gear << "]" << endl;
    }
};

class Bike : public Vehicle {
private:
    int speed = 0;
    int gear = 0;
public:
    void changeGear(int newGear) override {
        gear = newGear;
        cout << "Bike gear changed to: " << gear << endl;
    }
    void speedUp(int increment) override {
        speed += increment * 2;
        cout << "Bike speed increased to: " << speed << " km/h" << endl;
    }
    void applyBrakes(int decrement) override {
        speed -= decrement;
        if(speed < 0) speed = 0;
        cout << "Bike slowed down to: " << speed << " km/h" << endl;
    }
    void displayStatus() override {
        cout << "Bike [Speed: " << speed << " km/h, Gear: " << gear << "]" << endl;
    }
};

class Car : public Vehicle {
private:
    int speed = 0;
    int gear = 0;
public:
    void changeGear(int newGear) override {
        gear = newGear;
        cout << "Car gear changed to: " << gear << endl;
    }
    void speedUp(int increment) override {
        speed += increment * 3;
        cout << "Car speed increased to: " << speed << " km/h" << endl;
    }
    void applyBrakes(int decrement) override {
        speed -= decrement * 2;
        if(speed < 0) speed = 0;
        cout << "Car slowed down to: " << speed << " km/h" << endl;
    }
    void displayStatus() override {
        cout << "Car [Speed: " << speed << " km/h, Gear: " << gear << "]" << endl;
    }
};

int main() {
    Vehicle* bicycle = new Bicycle();
    Vehicle* bike = new Bike();
    Vehicle* car = new Car();
    int choice, value;

    while(true) {
        cout << "\nSelect Vehicle:\n1. Bicycle\n2. Bike\n3. Car\n4. Exit\nChoice: ";
        cin >> choice;
        if(choice == 4) break;

        Vehicle* v = nullptr;
        if(choice == 1) v = bicycle;
        else if(choice == 2) v = bike;
        else if(choice == 3) v = car;
        else {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "Select Action:\n1. Change Gear\n2. Speed Up\n3. Apply Brakes\n4. Display Status\nAction: ";
        int action;
        cin >> action;

        switch(action) {
            case 1:
                cout << "Enter new gear: ";
                cin >> value;
                v->changeGear(value);
                break;
            case 2:
                cout << "Enter speed increment: ";
                cin >> value;
                v->speedUp(value);
                break;
            case 3:
                cout << "Enter brake decrement: ";
                cin >> value;
                v->applyBrakes(value);
                break;
            case 4:
                v->displayStatus();
                break;
            default:
                cout << "Invalid action!" << endl;
        }
    }

    delete bicycle;
    delete bike;
    delete car;

    return 0;
}
