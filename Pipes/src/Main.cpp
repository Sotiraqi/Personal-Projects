#include <stdio.h>
#include <unistd.h>

bool isPrime(int n)
{
	int i;
	if(n==1||n==0) return false;
   
      //Run a loop from 2 to n-1
      for(i=2; i<n; i++){
        // if the number is divisible by i, then n is not a prime number.
        if(n%i==0) return false;
      }
      //otherwise, n is prime number.
      return true;
}

int* program(int start, int end)
{
	
 
    //check for every number from 1 to N
      for(int i=start; i<=end; i++){
          //check if current number is prime
          if(isPrime(i)) {
            printf("%i", i);
			return nullptr;
          }
    }
}

int main()
{
	int p[10];
	int i;
	int* inbuf[16];
	
	if(pipe(p) < 0)
		_exit(1);
		
	write(p[0], program(0, 1000),  16);
	write(p[1], program(1000, 2000),  16);
	write(p[2], program(2000, 3000),  16);
	write(p[3], program(3000, 4000),  16);
	write(p[4], program(4000, 5000),  16);
	write(p[5], program(5000, 6000),  16);
	write(p[6], program(6000, 7000),  16);
	write(p[7], program(7000, 8000),  16);
	write(p[8], program(8000, 9000),  16);
	write(p[9], program(9000, 10000),  16);
	
	for (i = 0; i < 10; i++) {
        /* read pipe */
        read(p[i], inbuf, 16);
        printf("% p", inbuf);
    }
	
	
}