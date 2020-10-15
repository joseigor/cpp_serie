#include <cstring>
#include <iostream>

class Employee {
   private:
    /* data */
    char *name = nullptr;
    int age{0};
    float salary{0};
    char *department = nullptr;

    void init(const char *_name, int _age, float _salary, const char *_department) {
        std::cout << "init" << std::endl;

        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        age = _age;
        salary = _salary;
        department = new char[strlen(_department) + 1];
    }

   public:
    Employee(const char *_name) {
        std::cout << "Constructor 1" << std::endl;

        init(_name, 0, 0.0f, "");
    }

    Employee(const char *_name, int _age) {
        std::cout << "Constructor 2" << std::endl;

        init(_name, _age, 0.0f, "");
    }

    Employee(const char *_name, int _age, float _salary) {
        std::cout << "Constructor 3" << std::endl;

        init(_name, _age, _salary, "");
    }

    Employee(const char *_name, int _age, float _salary, const char *_department) {
        std::cout << "Constructor 4" << std::endl;
        init(_name, _age, _salary, _department);
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