#include <cstring>
#include <iostream>

class Employee {
   private:
    /* data */
    char *name = nullptr;
    int age{0};
    int salary{0};
    char *department = nullptr;

   public:
    Employee(const char *_name) {
        std::cout << "Constructor 1" << std::endl;

        int nameSize = strlen(_name);
        name = new char[nameSize + 1];
        strcpy(name, _name);
    }

    Employee(const char *_name, int _age) {
        std::cout << "Constructor 2" << std::endl;

        int nameSize = strlen(_name);
        name = new char[nameSize + 1];
        strcpy(name, _name);
        age = _age;
    }

    Employee(const char *_name, int _age, int _salary) {
        std::cout << "Constructor 3" << std::endl;

        int nameSize = strlen(_name);
        name = new char[nameSize + 1];
        strcpy(name, _name);
        age = _age;
        salary = _salary;
    }

    Employee(const char *_name, int _age, int _salary, const char *_department) {
        std::cout << "Constructor 4" << std::endl;

        int nameSize = strlen(_name);
        int deptSize = strlen(_department);
        name = new char[nameSize + 1];
        strcpy(name, _name);
        age = _age;
        salary = _salary;
        department = new char[deptSize + 1];
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
    Employee ep1("ep1");
    Employee ep2("ep1", 20);
    Employee ep3("ep1", 21, 5000);
    Employee ep4("ep1", 20, 5000, "Software");
    return 0;
}
