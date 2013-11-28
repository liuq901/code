#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[100001],b[100001],s[100001];
int main()
{
   int m,i,ans;
   scanf("%*d%d",&m);
   memset(s,0,sizeof(s));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&a[i],&b[i]);
      s[a[i]]++;
      s[b[i]]++;
   }
   ans=0;
   for (i=1;i<=m;i++)
      ans+=s[a[i]]+s[b[i]];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
