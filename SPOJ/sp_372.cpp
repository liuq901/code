#include <cstdio>
#include <cstdlib>
#include <cstring>
int dep[50001],b[50001],a[100001][3];
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   void floodfill(int,int);
   int n;
   scanf("%d",&n);
   memset(b,0,sizeof(b));
   for (int i=1;i<n;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y;
      a[i][1]=b[x];
      a[i][2]=z;
      b[x]=i;
      a[i+n][0]=x;
      a[i+n][1]=b[y];
      a[i+n][2]=z;
      b[y]=i+n;
   }
   dep[1]=0;
   floodfill(1,0);
   int k=0;
   for (int i=1;i<=n;i++)
      if (dep[k]<dep[i])
         k=i;
   dep[k]=0;
   floodfill(k,0);
   k=0;
   for (int i=1;i<=n;i++)
      if (dep[k]<dep[i])
         k=i;
   printf("%d\n",dep[k]);
}
void floodfill(int x,int father)
{
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      dep[a[i][0]]=dep[x]+a[i][2];
      floodfill(a[i][0],x);
   }
}
