#include <iostream>
#include <fstream>
#include <stdexcept>

class FileManager {
private:
    std::fstream file;

public:
    // Constructor opens the file
    FileManager(const std::string& filename) {
        file.open(filename, std::ios::in | std::ios::out | std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        std::cout << "File opened successfully." << std::endl;
    }

    // Destructor automatically closes the file
    ~FileManager() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed successfully." << std::endl;
        }
    }

    // A method to write data to the file
    void write(const std::string& data) {
        if (file.is_open()) {
            file << data << std::endl;
        }
    }

    // A method to read data from the file
    void read() {
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            // Move file pointer to the beginning after reading
            file.clear(); // Clear EOF flag
            file.seekg(0, std::ios::beg);
        }
    }
};

int main() {
    try {
        // Create a FileManager object which manages file opening/closing
        FileManager fileManager("example.txt");

        // Write some data to the file
        fileManager.write("Hello, RAII in C++!");
        fileManager.write("This is a second line.");

        // Read the data back
        std::cout << "Contents of the file:" << std::endl;
        fileManager.read();
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // The file is automatically closed when fileManager goes out of scope
    return 0;
}
