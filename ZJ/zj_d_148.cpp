#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   char ch;
   while (scanf("%c",&ch)!=EOF)
      if (isalpha(ch))
         printf("%c",ch);
   printf("\n");
   system("pause");
   return(0);
}
