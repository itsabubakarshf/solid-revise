#include <iostream>
#include <fstream>
#include <string>

// Violates SRP by handling both user properties and data storage
class User {
public:
    std::string name;
    int age;

    User(const std::string& name, int age) : name(name), age(age) {}

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename, std::ios::app);
        file << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    User user("John Doe", 30);
    user.saveToFile("users.txt"); // Mixing data management with storage responsibilities
    return 0;
}
