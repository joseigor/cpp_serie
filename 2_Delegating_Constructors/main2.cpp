#include <cstring>
#include <iostream>

class Employee {
   private:
    /* data */
    char *name = nullptr;
    int age{0};
    float salary{0};
    char *department = nullptr;

   public:
    Employee(const char *_name) {
        std::cout << "Constructor 1" << std::endl;

        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    Employee(const char *_name, int _age) {
        std::cout << "Constructor 2" << std::endl;

        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        age = _age;
    }

    Employee(const char *_name, int _age, float _salary) {
        std::cout << "Constructor 3" << std::endl;

        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        age = _age;
        salary = _salary;
    }

    Employee(const char *_name, int _age, float _salary, const char *_department) {
        std::cout << "Constructor 4" << std::endl;

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
    Employee &operator=(Employee) = delete;
};

int main() {
    Employee ep1("ep1");
    Employee ep2("ep1", 20);
    Employee ep3("ep1", 21, 5000.0f);
    Employee ep4("ep1", 20, 5000.0f, "Software");
    return 0;
}