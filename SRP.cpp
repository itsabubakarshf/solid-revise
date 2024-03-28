#include <iostream>
#include <fstream>
#include <string>

// Handles user properties only
class User {
public:
    std::string name;
    int age;

    User(const std::string& name, int age) : name(name), age(age) {}
};

// Handles data storage operations
class UserStorage {
public:
    static void saveToFile(const User& user, const std::string& filename) {
        std::ofstream file(filename, std::ios::app);
        file << "Name: " << user.name << ", Age: " << user.age << std::endl;
    }
};

int main() {
    User user("Jane Doe", 28);
    UserStorage::saveToFile(user, "users.txt"); // Separation of concerns
    return 0;
}
