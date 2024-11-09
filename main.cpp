#include <iostream>
#include <fstream>
#include <bitset>
#include <string> 
using namespace std;

class FileHandler {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Unable to open file\n";
            return;
        }
        std::string line;
        while (std::getline(file, line)) { 
            std::cout << line << std::endl;
        }
        file.close();
    }
};

class AsciiFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Unable to open file\n";
            return;
        }
        char ch;
        while (file.get(ch)) {
            std::cout << static_cast<int>(ch) << " ";
        }
        std::cout << std::endl;
        file.close();
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Unable to open file\n";
            return;
        }
        char ch;
        while (file.get(ch)) {
            std::cout << std::bitset<8>(ch) << " ";
        }
        std::cout << std::endl;
        file.close();
    }
};

int main() {
    FileHandler* handler = new FileHandler();
    handler->Display("example.txt");

    handler = new AsciiFileHandler();
    handler->Display("example.txt");

    handler = new BinaryFileHandler();
    handler->Display("example.txt");

    delete handler;
    return 0;
}
