#Default

## to mention:

- especial members ( default constructor, copy constructor, copy-assignment operator, destructor)
  C++ 11 added to that list (move constructor and move asssigment)
  -only applicable to especial member function

  - show example of how it was to make a noncyable class before c++ 11 and after;

  "Good point":
  Because of the performance benefits of trivial special member functions, we recommend that you prefer automatically generated special member functions over empty function bodies when you want the default behavior. You can do this either by explicitly defaulting the special member function, or by not declaring it (and also not declaring other special member functions that would prevent it from being automatically generated.)

#Delete

- delete class especial members
- delete member functions
- Disabling undesirable argument conversion (show use of templates)

references:
https://docs.microsoft.com/en-us/cpp/cpp/explicitly-defaulted-and-deleted-functions?view=vs-2019
https://www.geeksforgeeks.org/explicitly-defaulted-deleted-functions-c-11/
https://en.cppreference.com/w/cpp/language/member_template
https://www.bogotobogo.com/cplusplus/C11/C11_default_delete_specifier.php
