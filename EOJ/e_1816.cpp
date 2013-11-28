#include <cstdio>
#include <cstdlib>
int f[1000010];
int main()
{
   int find(int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      f[i]=i;
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      f[find(x)]=find(y);
   }
   bool flag=true;
   for (int i=1;i<=n;i++)
      if (find(i)!=find(1))
      {
         flag=false;
         break;
      }
   printf("%s\n",flag?"yes":"no");
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
