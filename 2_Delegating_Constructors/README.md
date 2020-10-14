# Delegating Constructors

Delegating Constructors C++ 11

In this article we’ll see when and how to use Delegating Constructors in C++, a feature introduced in C++ 11.
For exemplification propose, lets create a simple class called Employee that holds the name, age and salary and department of an Employee. In this class we will overload the constructor in order to be able to create a object Employee with some flexibility, see below:

As you can see the code above, four constructors were create to allow flexibility, during the creation of an Employee object.
Constructor 1 : Only the name of the Employee is required
Constructor 2: The name and the age of the Employee are required
Constructor 3 : The name, age and salary of the Employee are required
Constructor 4 : The name, age, salary and department of the employee is required.

In the main function, four objects were created, each on with different parameters specified in the Constructor. After running the main, the following line appear in the console:

Ok, the code is working and we have flexibility to create our Employee’s objects, but if you look carefully to the constructors, you can see there that is a lot of code that is repeated in the implementation of each constructor.
Let suppose that after a design analysis you decided to to the following changes:
• The salary of the an employee should be a float instead of int.
• instead of using temporary variables to hold a size of the employee name and department, inside the constructor, you want to call the function strlen direct in the creation of the arrays.

In order to accomplish the two bullets requirements above, it was needed to change code in 3 of the 4 constructors. In my perspective this is not a good a approach , as good software engineers we should aim to produce code that is easy to maintain , easy to scale and less error prone and also to duplicated code.
One thing that we can do to a void this repeated code is to create a common function to initialize the an Employee object. That function can contain all the common code and will be called by all the constructors. See below that implementation.
Now our code is easier to maintain. But a problem here: other member function could call the init() function accidentally what can cause unexpected behavior.

To solve this problem, C++ 11 brought a new feature called delegating constructors. Bassically to use the power of delegating constructor we need to identify the common code and put in the the target constructor then this target constructor will be called be the delegating constructor; Let’s jump to the code to make it more simple to undertand.
