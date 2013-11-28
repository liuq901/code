#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
int main()
{
   int i,l,sum;
   char s[260];
   while (1)
   {
      scanf("%s",s);
      l=strlen(s);
      if (l==1 && s[0]=='0')
         break;
      sum=0;
      for (i=0;i<l;i++)
      {
         if (!isalpha(s[i]))
         {
            sum=-1;
            break;
         }
         sum+=tolower(s[i])-'a'+1;
      }
      if (sum==-1)
         printf("Fail\n");
      else
         printf("%d\n",sum);
   }
   system("pause");
   return(0);
}
