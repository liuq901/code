#include <cstdio>
#include <cstdlib>
int ans,b[50001],a[100001][2];
bool f[50001][21];
int main()
{
   void floodfill(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n-1;i++)
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
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   int k=0;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
      for (int j=0;j<=20;j++)
      {
         if (f[x][j] && f[a[i][0]][j] && j>k)
            k=j;
         f[x][j]|=f[a[i][0]][j];
      }
   }
   while (f[x][k])
      k++;
   for (int i=0;i<=k-1;i++)
      f[x][i]=false;
   f[x][k]=true;
   ans>?=k;
}
