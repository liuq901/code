#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
int main()
{
   int sum,l,i;
   char s[10010];
   while (scanf("%s",s)!=EOF)
   {
      l=strlen(s);
      sum=0;
      for (i=0;i<l;i++)
      {
         if (!isdigit(s[i]))
            continue;
         sum+=s[i]-'0';
      }
      if (sum%3==0)
         printf("yes\n");
      else
         printf("no\n");
   }
   system("pause");
   return(0);
}
