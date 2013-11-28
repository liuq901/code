#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   char ch;
   int flag,ans;
   flag=ans=0;
   while (scanf("%c",&ch)!=EOF)
   {
      if (ch=='\n')
      {
         if (flag==1)
            ans++;
         printf("%d\n",ans);
         flag=ans=0;
         continue;
      }
      if (isalpha(ch))
         flag=1;
      else if (flag==1)
      {
         flag=0;
         ans++;
      }
   }
   system("pause");
   return(0);
}
