#include <stdarg.h>
#include <stdio.h>
  int calculated(char op, int count,...)

  int result;
  int num;
  int i;

    va_list args;
    va_start(args,count);
if(count ==0);
  return(0);
i=1;
result= va_arg(args,int)
while(i<count)
{
  num = va_args(args,int);
  if(op == '+')
    reslut += num;
  else if(op == '-')
    result -= num;
  else if(op == '*')
  result *= num;
  else if(op == '/')
       {   if (num == 0)
            {  printf("hatalı bölme islemi\n");
                va_end(args);
                  return(0);
            }
  
        result /= num;
      }
      i++;
  }
  va_end(args);
 return result;




int main()
{
   printf("Toplama: %d\n", calculate('+', 3, 10, 20, 30));    // 60
    printf("Çıkarma: %d\n", calculate('-', 3, 100, 20, 10));   // 70
    printf("Çarpma: %d\n", calculate('*', 3, 2, 3, 4));        // 24
    printf("Bölme: %d\n", calculate('/', 2, 100, 2));          // 50
    return 0;
}
