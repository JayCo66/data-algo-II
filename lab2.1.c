#include <stdio.h>
#include <sys/time.h>

int factorial(int n)
{

   if (n == 1)
      return n;
   else
      return n * factorial(n - 1);
}
int factorial_iterative(int n)
{

   int result = 1;
   for (int i = n; i >= 1; i--)
   {
      result *= i;
   }

   return result;
}

int main()
{
    clock_t start, end;
    for(int i=0; i<1000000; i++){
        factorial(20);
    }
    end = clock();
    double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    printf("time: %f s\n", time_ms);
    return (0);
}