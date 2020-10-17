#include <cstring>
#include <iostream>

class Employee {
   private:
    /* data */
    char *name = nullptr;
    int age{0};
    float salary{0.0f};
    char *department = nullptr;

   public:
    // Delegating Contructor    | Target Constructor
    Employee(const char *_name) : Employee(_name, 0) {
        std::cout << "Constructor 1" << std::endl;
    }
    // Delegating Contructor              | Target Constructor
    Employee(const char *_name, int _age) : Employee(_name, _age, 0.0f) {
        std::cout << "Constructor 2" << std::endl;
    }
    // Delegating Contructor                             | Target Constructor
    Employee(const char *_name, int _age, float _salary) : Employee(_name, _age, _salary, "") {
        std::cout << "Constructor 3" << std::endl;
    }

    // Target Constructor
    Employee(const char *_name, int _age, float _salary, const char *_department) {
        std::cout << "Constructor 4" << std::endl;

        // Common code in the target constructor
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        age = _age;
        salary = _salary;
        department = new char[strlen(_department) + 1];
    }

    // Destructor
    ~Employee() {
        delete[] name;
        delete[] department;
    }

    // Copy Constructor and Copy Operator marked as delete
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;
};

int main() {
    std::cout << "ep1 Constructor call list:" << std::endl;
    Employee ep1("ep1");

    std::cout << "ep2 Constructor call list:" << std::endl;
    Employee ep2("ep2", 20);

    std::cout << "ep3 Constructor call list:" << std::endl;
    Employee ep3("ep3", 21, 5000.0f);

    std::cout << "ep4 Constructor call list:" << std::endl;
    Employee ep4("ep4", 20, 5000.0f, "Software");
    return 0;
}
