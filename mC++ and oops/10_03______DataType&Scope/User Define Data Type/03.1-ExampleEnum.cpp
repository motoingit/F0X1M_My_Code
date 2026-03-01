#include <iostream>
#include <string>

// Define an enum for file operation results
enum class FileStatus {
    SUCCESS,
    FILE_NOT_FOUND,
    ACCESS_DENIED,
    READ_ERROR
};

// A function that simulates reading a file
FileStatus readFile(const std::string& filePath) {
    if (filePath == "secret.txt") {
        return FileStatus::ACCESS_DENIED;
    }
    if (filePath == "data.txt") {
        return FileStatus::SUCCESS;
    }
    return FileStatus::FILE_NOT_FOUND;
}

int main() {
    FileStatus status = readFile("secret.txt");

    if (status == FileStatus::ACCESS_DENIED) {
        std::cerr << "Error: Access to the file was denied." << std::endl;
    }

return 0;}