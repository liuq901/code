#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   int sum=0;
   while (1)
   {
      char ch;
      scanf("%c",&ch);
      if (!isdigit(ch))
         break;
      sum+=ch-'0';
   }
   if (sum%3)
      printf("1\n%d\n",sum%3);
   else
      printf("2\n");
   system("pause");
   return(0);
}
