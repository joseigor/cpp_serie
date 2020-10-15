## Delegating Constructors C++ 11

In this article we’ll see when and how to use Delegating Constructors in C++, a feature introduced in C++ 11. <br/> 
For exemplification propose, lets create a simple class called **Employee** that holds the *name*, *age*, *salary* and *department* of an Employee. In this class we will overload the constructor in order to be able to create an object **Employee** with some flexibility, see below:

### main1.cpp
``` c++
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
    Employee &operator=(Employee) = delete;
};

int main() {
    Employee ep1("ep1");
    Employee ep2("ep1", 20);
    Employee ep3("ep1", 21, 5000);
    Employee ep4("ep1", 20, 5000, "Software");
    return 0;
}
```

As you can see the code above, four constructors were created to allow flexibility during the creation of an Employee object:
1. Constructor 1: Only the name of the Employee is required
2. Constructor 2: The name and the age of the Employee are required
3. Constructor 3: The name, age and salary of the Employee are required
4. Constructor 4: The name, age, salary and department of the employee are required.

In the ``` main``` function, four objects were created, each one with different parameters specified in the Constructor. After running the main, the following lines appears in the console:

``` 
main1.cpp output:

Constructor 1
Constructor 2
Constructor 3
Constructor 4

```


Ok, the code is working and we have flexibility to create our Employee’s objects right? <br/>
But if you look carefully to the constructors, you can see there that is a lot of code that is **repeated** in the implementation of each constructor. <br/>
Let suppose that after a design analysis you decided to do the following changes:
* The salary of the an employee should be a ```float``` instead of ```int```.
* Instead of using temporary variables to hold a size of the employee name and department inside the constructor, you want to call the function ```strlen``` direct in the creation of the arrays.

### main2.cpp
``` c++
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

```
In order to accomplish the two bullets requirements above, it was needed to change code in 3 of the 4 constructors (see ``` main2.cpp ```). <br/>
In my perspective this isn't a good a approach. As good software engineers we should strive to produce code that is easy to maintain, easy to scale and less error prone and also to avoid code duplication. <br\>
One thing we can do to a void this repeated code is to create a common function to initialize an *Employee* object. That function can contain all the common code and it will be called by all the constructors. See below that implementation:

### main3.cpp
``` c++
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

```

Now our code is easier to maintain. But there is a problem here: other member function could call the ```init()``` function accidentally which can cause unexpected behavior.

To solve this problem, **C++ 11** brought a new feature called **delegating constructors**. 

Basically to use the power of delegating constructor we need to **identify the common code** and **put in the the target constructor** then this target constructor will be called be the delegating constructor. Let’s jump to the code to make it more simple to understand:

### main4.cpp

``` c++
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
    Employee &operator=(Employee) = delete;
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

``` 
In the code above the: 
* The constructor ``` Employee(const char *_name) ``` is a delegating constructor and its target constructor is ```  Employee(const char *_name, int _age)``` . * * Also ``` Employee(const char *_name, int _age) ``` is a delegating constructor that has ``` Employee(const char *_name, int _age, float _salary) ```  as target constructor. 
* And finally the constructor ```  Employee(const char *_name, int _age, float _salary) ```  is a delegating constructor that has as target the ``` Employee(const char *_name, int _age, float _salary, const char *_department) ``` constructor. 

As the constructor ``` Employee(const char *_name, int _age, float _salary, const char *_department) ```  doesn't have any target, actually it is our finally target that contains the implementation of our common code.

When the ```main``` function is executed, this is output:

```
main4.cpp output:

ep1 Constructor call list:
Constructor 4
Constructor 3
Constructor 2
Constructor 1
ep2 Constructor call list:
Constructor 4
Constructor 3
Constructor 2
ep3 Constructor call list:
Constructor 4
Constructor 3
ep4 Constructor call list:
Constructor 4

```

* If an object is created passing only the name as argument, *Constructor 1* calls its Target *Constructor 2* that calls its target *Constructor 3* that finally calls its target *Constructor 4*. 

* If an object is created passing the name and the age as arguments, *Constructor 2* calls its Target *Constructor 3* that finally calls its target *Constructor 4*.

* If an object is created passing the name,the age and the salary as arguments, *Constructor 3* calls its Target *Constructor 4*.

* If an object is created passing the name,the age , salary  and the department as arguments, only *Constructor 4* is called.


> Keep in mind that the code in a delegating constructor is executed only after the code in its target is executed, this is clear by looking to the output printed when the Employee object ep1 is created.

##  Points to care when using delegating constructor:

* A constructor can not delegate and use list initialization at the same time. The code below is not permitted.

```
clasee A {
  private: 
    int a;
    int b;
    
  public:
    A():A(0), b(0) {}
    A(int _a): { a = _a;}
 
}

```

* We should avoid recursive calls of target constructor. In the code  below we have a example of recursive call were A() has A(int) as target, but at the same time A() is the target of A(int).

```
clasee A {
  private: 
    int a;
    
  public:
    A():A(0) {}
    A(int _a):A() { a = _a;}
 
}

```
That is all for now... Buuut, this a open source repository, so feel free to contribute ...
:wink:
