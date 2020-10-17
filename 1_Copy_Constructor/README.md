1 - inthe end of the article it shown a way of removed the use of Copy Constructor by declaring it
as a privite member. This is a solutino pre-C++ 11, with C++ 11 there is a better way to do this by using
the Delete keyword. See tex below and link for reference:

[Link](https://docs.microsoft.com/en-us/cpp/cpp/explicitly-defaulted-and-deleted-functions?view=vs-2019)

"""
Before C++11, this code snippet was the idiomatic form of non-copyable types. However, it has several problems:

The copy constructor has to be declared privately to hide it, but because it's declared at all, automatic generation of the default constructor is prevented. You have to explicitly define the default constructor if you want one, even if it does nothing.

Even if the explicitly-defined default constructor does nothing, it's considered non-trivial by the compiler. It's less efficient than an automatically generated default constructor and prevents noncopyable from being a true POD type.

Even though the copy constructor and copy-assignment operator are hidden from outside code, the member functions and friends of noncopyable can still see and call them. If they are declared but not defined, calling them causes a linker error.

Although this is a commonly accepted idiom, the intent is not clear unless you understand all of the rules for automatic generation of the special member functions.

In C++11, the non-copyable idiom can be implemented in a way that is more straightforward.

....
