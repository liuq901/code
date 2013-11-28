#include <cstdio>
#include <cstdlib>
int dep[10001],b[10001],a[20001][2];
int main()
{
   void floodfill(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y;
      a[i][1]=b[x];
      b[x]=i;
      a[i+n][0]=x;
      a[i+n][1]=b[y];
      b[y]=i+n;
   }
   floodfill(1,0);
   dep[0]=-1;
   int k=0;
   for (int i=1;i<=n;i++)
      if (dep[k]<dep[i])
         k=i;
   floodfill(k,0);
   k=0;
   for (int i=1;i<=n;i++)
      if (dep[k]<dep[i])
         k=i;
   printf("%d\n",dep[k]);
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   dep[x]=dep[father]+1;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
   }
}
