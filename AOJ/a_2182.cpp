#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[80010];
int a[80010],f[80010][20];
int main()
{
   int calc(int);
   while (1)
   {
      scanf("%s",s);
      int n=strlen(s);
      if (n==1 && s[0]=='0')
         break;
      for (int i=1;i<=n;i++)
         a[i]=s[i-1]-'0';
      memset(f,0,sizeof(f));
      for (int i=1;i<=n+1;i++)
         f[i][0]=1;
      int ans=0;
      for (int i=n;i;i--)
      {
         if (a[i])
            ans+=i&1?f[i+1][11-a[i]]:f[i+1][a[i]];
         int p=i&1?1:-1;
         for (int j=0;j<11;j++)
            f[i][calc(j+p*a[i])]+=f[i+1][j];
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int calc(int x)
{
   int p=x%11;
   return(p>=0?p:p+11);
}
