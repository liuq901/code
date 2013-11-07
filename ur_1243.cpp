#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   char ch;
   int s=0;
   while (scanf("%c",&ch)!=EOF)
   {
      if (!isdigit(ch))
         break;
      s=(s*10+ch-'0')%7;
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
