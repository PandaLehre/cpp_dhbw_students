#include <cstdlib>


int main()
{
   float x = 2.0;
   float* ptr_x = &x;  // Ptr to x is set to address of x
   float y = *ptr_x;   // y is set to value behind ptr_x

   x = 7.1;             // x = 7.1 , y = 2.0
   y = 23.2;            // x = 7.1 , y = 23.2
   *ptr_x = 0.0;        // x = 0.0 , y = 23.2

   int sizeFloat = sizeof(x);
   int sizePointer = sizeof(ptr_x);

   // Create new float pointer
   float *ptr = (float *) malloc(sizeof(float));
   // Set value of pointer
   *ptr = 3.0;

   // Must not forget to free memory again!
   free(ptr);

   return 0;
}