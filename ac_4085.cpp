#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[1000010];
int a[1000010],ans[1000010];
int main()
{
   while (1)
   {
      scanf("%s",s);
      if (s[0]=='0')
         break;
      int n=strlen(s);
      for (int i=1;i<=n;i++)
         a[i]=s[i-1]-'0';
      for (int i=n;i;i--)
      {
         if (a[i]<0)
         {
            a[i]+=10;
            a[i-1]--;
         }
         ans[i]=a[i];
         a[i-1]-=a[i];
      }
      static int id=0;
      printf("%d. ",++id);
      if (!ans[1])
         printf("IMPOSSIBLE\n");
      else
      {
         for (int i=1;i<=n;i++)
            printf("%d",ans[i]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
