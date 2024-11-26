#include <iostream>
#include <memory>
#include <fstream>

// A simple class that simulates a file resource
class FileResource {
public:
    FileResource(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    ~FileResource() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed" << std::endl;
        }
    }

    void write(const std::string& text) {
        if (file.is_open()) {
            file << text;
        }
    }

private:
    std::ofstream file;
};

// Custom deleter function for FileResource
void customDeleter(FileResource* ptr) {
    std::cout << "Custom deleter: Closing file and cleaning up" << std::endl;
    delete ptr;  // Cleanup logic for the resource
}

int main() {
    try {
        // Create a unique_ptr with a custom deleter
        std::unique_ptr<FileResource, decltype(&customDeleter)> filePtr(
            new FileResource("example.txt"), customDeleter);

        // Use the file resource
        filePtr->write("Hello, this is a test file!");

        // The custom deleter will be called automatically when filePtr goes out of scope
    } catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
