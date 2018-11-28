#include <stdlib.h>
#include <stdio.h>

int f1(int);
int f2(int); 
long f3(int);
int f4(int);
int f5(int);
int check(int);
int count(int);


int main()
{
  int i;
  
  printf("Enter a number between 1 and 50 inclusive: ");
  scanf("%d", &i);
  
  if( i < 1 || i > 50)
  {
    printf("You entered an invalid number: must be between 1 and 50\n");
    exit(1);
  }
  
  printf("f1 output is %d\n", f1(i) );
  
  printf("f2 output is %d\n", f2(i) );
   
  printf("f3 output is %ld\n", f3(i) );
    
  printf("f4 output is %d\n", f4(i) );
     
  printf("f5 output is %u\n", f5(i) );
  
  
}

/*******************************************************/
int f1(int x)
{
   if (x > 0x1d) return (x >> 2) + 17;
   else return 26 * x;
  
}
/*******************************************************/
int f2(int x)
{
  // a = eax
  // x = edx = edi
  int a = 0;
  int x_dup = x;
  while (x != 0) 
  {
    if ((x & 0xff) & 1) a += 2;
    x = x >> 2;
  }
  return (a + x_dup);
}


/*******************************************************/
long f3(int x)
{
  int b = 11 * x;   // esi
  int c = 0;        // edx
  int a = 0xab;     // eax
  while (c < b)
  {
    int r = c;    // rcx
    a += r;
    c ++;
  }
  return a;
}


/*******************************************************/
int f4(int i)
{
  int a;
  if (i > 0xf)
  {
    a = i - 0x10;
    if (a > 9) 
      return 0xab;
    return i + 0x11;
  }
  return i + 0xf; 
  
}

/*******************************************************/
int f5(int x)
{
  switch (x)
  {
    case 0: return (x >> 2);

    case 1: return (9 * x);

    case 2: return (x + 0xa);

    case 3: return check(x);

    case 4: return count(x);

    case 5: return 0x11;
    
    default: return (5 * x);
  } 
}


/*******************************************************/
int check (int x) 
{
  int a = 2;    // eax
  while (x != 0)
  {
    a += x;
    x --;
  }
  return a;
}

/*******************************************************/
int count (int x)
{
  while (x != 0) x = x >> 1;
  return 0;
}

