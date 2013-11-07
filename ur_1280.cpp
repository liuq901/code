#include <cstdio>
#include <cstdlib>
int l[100001],r[100001];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
      scanf("%d%d",&l[i],&r[i]);
   bool flag=true;
   int f[1001]={0};
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      f[x]=i;
   }
   for (int i=1;i<=m;i++)
      if (f[l[i]]>f[r[i]])
      {
         flag=false;
         break;
      }
   printf("%s\n",flag?"YES":"NO");
   system("pause");
   return(0);
}
