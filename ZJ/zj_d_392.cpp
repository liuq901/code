#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
int main()
{
   char s[10000];
   while (gets(s))
   {
      int ans=0,x=0,l=strlen(s);
      for (int i=0;i<l;i++)
         if (isdigit(s[i]))
            x=x*10+s[i]-'0';
         else
         {
            ans+=x;
            x=0;
         }
      printf("%d\n",ans+x);
   }
   system("pause");
   return(0);
}
