#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,k,n,ans;
   int f[10];
   char s[10];
   scanf("%d",&k);
   scanf("%d",&n);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
   {
      scanf("%s",s);
      f[s[0]-'0']++;
   }
   ans=2;
   for (i=0;i<=9;i++)
   {
      if (f[i]==0)
         continue;
      ans+=(f[i]-1)/k+1;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
