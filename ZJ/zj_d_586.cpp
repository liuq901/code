#include <cstdio>
#include <cstdlib>
#include <cctype>
const char a[]=" mjqhofawcpnsexdkvgtzblryui";
const char b[]=" uzrmatifxopnhwvbslekycqjgd";
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,ans=0;
      scanf("%d",&n);
      bool flag=false;
      for (int i=1;i<=n;i++)
      {
         char s[10];
         scanf(" %s",s);
         if (isalpha(s[0]))
         {
            for (int j=1;j<=26;j++)
               if (s[0]==b[j])
               {
                  ans+=j;
                  break;
               }
            flag=true;
         }
         else
         {
            int x=atoi(s);
            printf("%c",a[x]);
         }
      }
      if (flag)
         printf("%d",ans);
      printf("\n");
   }
   system("pause");
   return(0);
}
