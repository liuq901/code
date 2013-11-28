#include <cstdio>
#include <cstdlib>
using namespace std;
int f[100010],p[100010],b[100010],a[200010][2];
int main()
{
   int find(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      f[i]=i;
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
   }
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if (x==1)
      {
         p[y]=z;
         for (int i=b[y];i;i=a[i][1])
            if (p[y]==p[a[i][0]])
               f[find(y)]=find(a[i][0]);
      }
      else
         printf("%s\n",find(y)==find(z)?"YES":"NO");
   }
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
