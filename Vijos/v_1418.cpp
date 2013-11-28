#include <cstdio>
#include <cstdlib>
#include <cstring>
int l[1100],r[1100],v[1100],a[1100];
int f[1100][110];
int main()
{
   int count(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=2;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      if (!l[x])
         l[x]=i;
      else
      {
         int t=l[x];
         while (r[t])
            t=r[t];
         r[t]=i;
      }
   }
   for (int i=1;i<=n;i++)
      scanf("%d",&v[i]);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,-1,sizeof(f));
   printf("%d\n",count(1,m));
   system("pause");
   return(0);
}
int count(int x,int p)
{
   int max(int,int);   
   if (!x)
      return(0);
   if (f[x][p]!=-1)
      return(f[x][p]);
   f[x][p]=0;
   for (int i=0;i<=p;i++)
      f[x][p]=max(f[x][p],count(l[x],i)+count(r[x],p-i));
   if (p>=v[x])
      f[x][p]=max(f[x][p],count(r[x],p-v[x])+a[x]);
   return(f[x][p]);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
