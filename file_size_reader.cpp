#include <iostream>
#include <fstream>

// Function to get file size
long getFileSize(const std::string& fileName) {
    std::ifstream file(fileName, std::ifstream::ate | std::ifstream::binary);
    if (file.is_open()) {
        return file.tellg();
    }
    return -1; // File not found or error
}

int main() {
    std::string cppFile = "source.cpp"; // replace with your .cpp file name
    std::string exeFile = "program.exe"; // replace with your .exe file name

    long sizeCpp = getFileSize(cppFile);
    long sizeExe = getFileSize(exeFile);

    if (sizeCpp != -1) {
        std::cout << "Size of " << cppFile << ": " << sizeCpp << " bytes\n";
    }
    else {
        std::cout << cppFile << " not found.\n";
    }

    if (sizeExe != -1) {
        std::cout << "Size of " << exeFile << ": " << sizeExe << " bytes\n";
    }
    else {
        std::cout << exeFile << " not found.\n";
    }

    return 0;
}
