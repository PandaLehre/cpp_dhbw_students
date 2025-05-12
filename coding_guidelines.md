# Coding Guidelines Documentation

## Overview
This document provides an overview of the coding guidelines for `.cpp` and `.hpp` files. These guidelines ensure consistent, readable, and maintainable C++ code.

---

## General Coding Guidelines
1. **Formatting**:
   - Use consistent spacing and indentation.
   - Avoid unnecessary spaces in expressions and control structures.
2. **Comments**:
   - Use `//` for single-line and multi-line comments.
   - Provide meaningful descriptions for classes, methods, and variables.
3. **Includes**:
   - Organize includes into standard, third-party, and own headers.
4. **Namespaces**:
   - Use namespaces to encapsulate related code and avoid conflicts.
5. **Documentation**:
   - Use Doxygen-style comments for methods and classes.
   - Document parameters and return values clearly.

---

## Implementation File Structure (`.cpp`)

### Include Structure
Organize includes into three blocks:

```cpp
#include <iostream> // First Block: Standard C/C++ includes
#include <string>

#include <third_party.hpp>  // Second Block: Third-party includes
#include <third_party2.hpp> // ...

#include "coding_guidelines.hpp" // Third Block: Include own header files
#include "my_lib.hpp" // ...
```

### Namespace Definition
Namespaces should be defined at the beginning of the implementation file. Use the same namespace as in the header file.

```cpp
namespace ServiceFunctions
{

   int ServiceClass::start(const int param1, const int param2) // Class name
   {
      ServiceClass *pointerToObject; // NOT: ServiceClass *pointerToObject
      int x = param1 + 3;            // NOT: int x=param1+3

      if (param1 != param2) // NOT: if ( param1 != param2 )
      {                     // NOT: if(...), if (param1!=param2)
                            // ...
      }

      for (int i = 0; i < param1; i++) // NOT: for(...), for (int i=0;i<param1;i++)
      {
         // ...
      }

      // This is a comment which spans over more than one line.
      // Here comes the second line. /* is not used for this.
      return param1 + param2;
   }

   int ServiceClass::counter3 = 42;

} // end namespace ServiceFunctions
```




## Header File Structure (`.hpp`)

### Include Guards
Use include guards to prevent multiple inclusions of the same header file.

```cpp
#ifndef CODING_GUIDELINES_HPP_INCLUDED
#define CODING_GUIDELINES_HPP_INCLUDED
```

### Namespace Declaration
Namespaces should be declared at the beginning of the header file. Use the same namespace as in the implementation file.

```cpp
namespace ServiceFunctions
{

enum class ServiceTypes
{
   serviceA,   // Short inline description of serviceA
   serviceB,   // Short inline description of serviceB
   serviceC    // Short inline description of serviceC
};

/// This is a short description of the following class.
///
/// This is a more detailed description of the class.
/// Should include high-level description and motivation.
/// Usage code examples can also help.
class ServiceClass
{
public:
   ServiceClass(const int counter1, const int counter2)
   : m_counter1{counter1}
   , m_counter2{counter2}
   {
   }

   /// Description of method
   /// Trivial getter and setter methods can be implemented in hpp
   int getServiceBValue() const
   {
      return static_cast<int>(ServiceTypes::serviceB);
   }

   /// Description of method
   /// \param [in] param1 Description of param1
   /// \param [in] param2 Description of param2
   /// \return int Description of return value
   int start(const int param1, const int param2);

private:
   int m_counter1;      // short inline description of member
   int m_counter2;      // NOT: int m_counter1, m_counter2
   static int counter3; // short inline description of member
};

}  // end namespace ServiceFunctions

```
---
---
---

This document serves as a reference for writing clean and maintainable C++ code.