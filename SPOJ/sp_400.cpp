#include <cstdio>
#include <cstdlib>
#include <cstring>
char a[210][210];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      char s[210];
      scanf("%s",s);
      int l=strlen(s),m=l/n,t=0;
      for (int i=1;i<=m;i++)
      {
         if (i&1)
         {
            for (int j=1;j<=n;j++)
               a[i][j]=s[t++];
            continue;
         }
         for (int j=n;j>=1;j--)
            a[i][j]=s[t++];
      }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            printf("%c",a[j][i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
