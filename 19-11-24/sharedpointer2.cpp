#include <iostream>
#include <memory>  // For std::shared_ptr

// Car class representing a car object
class Car {
public:
    Car(const std::string& model) : model_(model) {
        std::cout << "Car (" << model_ << ") is created!" << std::endl;
    }

    ~Car() {
        std::cout << "Car (" << model_ << ") is destroyed!" << std::endl;
    }

    void drive() const {
        std::cout << "Driving " << model_ << "!" << std::endl;
    }

private:
    std::string model_;
};

// Garage class representing a garage where cars are stored
class Garage {
public:
    // Constructor that accepts a shared_ptr to a Car
    Garage(std::shared_ptr<Car> car) : car_(car) {}

    // A method that uses the shared Car resource
    void park() const {
        std::cout << "Parking the car." << std::endl;
        car_->drive();
    }

private:
    std::shared_ptr<Car> car_;  // Shared ownership of the car
};

int main() {
    // Create a shared_ptr to a Car object
    std::shared_ptr<Car> car1 = std::make_shared<Car>("Toyota");

    // Create two Garage objects that share ownership of the same Car object
    Garage garage1(car1);  // garage1 owns a shared_ptr to car1
    Garage garage2(car1);  // garage2 shares ownership of car1

    // Both garages can access and use the car
    garage1.park();
    garage2.park();

    // Check reference count
    std::cout << "Reference count after both garages are created: " << car1.use_count() << std::endl;

    // The car object will be deleted automatically when the last shared_ptr goes out of scope

    return 0;
}
