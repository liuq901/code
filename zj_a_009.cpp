#include <cstdio>
#include <cstdlib>
int main()
{
   int i,l;
   char ch;
   while (scanf("%c",&ch)!=EOF)
   {
      if (ch!='\n')
         ch-=7;
      printf("%c",ch);
   }
   system("pause");
   return(0);
}
