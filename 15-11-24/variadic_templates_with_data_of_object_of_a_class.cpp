#include <iostream>
#include <tuple>

// Class to hold multiple data members of varying types using variadic templates
template <typename... Args>
class MultiData {
private:
    // A tuple to store data members of different types
    std::tuple<Args...> data;

public:
    // Constructor to initialize data members
    MultiData(Args&&... args) : data(std::forward<Args>(args)...) {}

    // Method to access the data members by index
    template <std::size_t Index>
    auto& get() {
        return std::get<Index>(data);
    }

    // Const version of get
    template <std::size_t Index>
    const auto& get() const {
        return std::get<Index>(data);
    }

    // Method to print all data members (using fold expression)
    void print() const {
        printImpl(std::index_sequence_for<Args...>{});
    }

private:
    // Helper function to print all data members (expand tuple)
    template <std::size_t... I>
    void printImpl(std::index_sequence<I...>) const {
        (void(std::cout << ... << (std::get<I>(data) << " ")));
        std::cout << std::endl;
    }
};

int main() {
    // Creating an object of MultiData with different types of data members
    MultiData<int, double, std::string> data(10, 3.14, "Hello");

    // Access data members by index
    std::cout << "Integer: " << data.get<0>() << std::endl;
    std::cout << "Double: " << data.get<1>() << std::endl;
    std::cout << "String: " << data.get<2>() << std::endl;

    // Print all data members
    data.print();  // Output: 10 3.14 Hello 

    // Modify a data member
    data.get<0>() = 20;
    data.get<1>() = 6.28;
    data.get<2>() = "World";

    // Print updated values
    data.print();  // Output: 20 6.28 World

    return 0;
}
