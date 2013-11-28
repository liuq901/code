#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
int main()
{
   char s[1010];
   while (gets(s))
   {
      int sum=0,x=0,l=strlen(s);
      for (int i=0;i<l;i++)
         if (isdigit(s[i]))
            x=x*10+s[i]-'0';
         else
         {
            sum+=x;
            x=0;
         }
      sum+=x;
      printf("%d\n",sum);
   }
   system("pause");
   return(0);
}
