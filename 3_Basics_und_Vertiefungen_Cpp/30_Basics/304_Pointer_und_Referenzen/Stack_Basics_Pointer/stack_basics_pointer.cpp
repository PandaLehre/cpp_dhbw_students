#include <iostream>
#include <cstdlib>

struct myStruct
{
   float value1;
   float value2;
   float value3;
   float value4;
   float value5;
};

int main()
{
   // FIRST PART //
   float number1 = 2.0f;
   float *ptrToNumber1 = &number1; // Ptr to number1 is set to address of number1
   float number2 = *ptrToNumber1;  // number2 is set to value behind ptr_number1

   number1 = 7.1f;       // number1 = 7.1 , number2 = 2.0
   std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;

   number2 = 23.2f;      // number1 = 7.1 , number2 = 23.2
   std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;

   *ptrToNumber1 = 0.0f; // number1 = 0.0 , number2 = 23.2
   std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;

   int sizeOfNumber1 = sizeof(number1);
   std::cout << "\nnumber1: " << number1 << "\n -> Size of number1: " << sizeOfNumber1 << std::endl;

   int sizeOfPointer1 = sizeof(ptrToNumber1);
   std::cout << "\nptrToNumber1: " << *ptrToNumber1 << "\n -> Size of ptrToNumber1: " << sizeOfPointer1 << std::endl;

   // SECOND PART //
   myStruct myFirstStruct{10, 20, 30, 40, 50}; // Create new struct with values
   int sizeOfMyStruct = sizeof(myFirstStruct);
   std::cout << "\nmyFirstStruct: " << myFirstStruct.value1 << ", " << myFirstStruct.value2 << ", "
             << myFirstStruct.value3 << ", " << myFirstStruct.value4 << ", " << myFirstStruct.value5 << std::endl;
   std::cout << " -> Size of myFirstStruct: " << sizeOfMyStruct << std::endl;

   myStruct *ptrToMyFirstStruct = &myFirstStruct;
   std::cout << " -> Address of myFirstStruct: " << ptrToMyFirstStruct << std::endl;
   std::cout << " -> Value of myFirstStruct via pointer: " << ptrToMyFirstStruct->value1 << ", "
             << ptrToMyFirstStruct->value2 << ", " << ptrToMyFirstStruct->value3 << ", "
             << ptrToMyFirstStruct->value4 << ", " << ptrToMyFirstStruct->value5 << std::endl;
   std::cout << " -> Size of pointer to myFirstStruct: " << sizeof(ptrToMyFirstStruct) << std::endl;

   // THIRD PART //
   float *pointerHeapMalloc = (float *)malloc(sizeof(float));    // Create new float pointer with malloc
   if (pointerHeapMalloc == nullptr) {
       std::cerr << "Memory allocation failed!" << std::endl;
       return 1; // Exit if memory allocation fails
   }
   std::cout << "\nAddress of pointerHeapMalloc: " << pointerHeapMalloc << std::endl;

   float *pointerHeapNew = new float; // Create new float pointer with new
   if (pointerHeapNew == nullptr) {
       std::cerr << "Memory allocation failed!" << std::endl;
       return 1; // Exit if memory allocation fails
   }
   std::cout << "Address of pointerHeapNew: " << pointerHeapNew << std::endl;

   // Set value of pointer
   *pointerHeapMalloc = 3.0;
   *pointerHeapNew = 4.0;
   std::cout << "Value of pointerHeapMalloc: " << *pointerHeapMalloc << std::endl;
   std::cout << "Value of pointerHeapNew: " << *pointerHeapNew << std::endl;

   // Must not forget to free memory again!
   free(pointerHeapMalloc);
   delete pointerHeapNew;

   std::cout << std::endl;

   return 0;
}