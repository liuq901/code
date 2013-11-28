#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100010],t[110];
int f[100010][110];
int main()
{
   scanf("%s%s",s,t);
   int n=strlen(s),m=strlen(t);
   for (int i=0;i<n;i++)
      f[i][0]=1;
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<m;j++)
         if (s[i]==t[j])
            f[i+1][j+1]+=f[i][j];
         else
            f[i+1][j]+=f[i][j];
   }
   long long ans=0;
   for (int i=m;i<=n;i++)
      ans+=(long long)f[i][m]*(n-i+1);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
