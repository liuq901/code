#include <cstdio>
#include <cstdlib>
int b[10001],a[20001][2];
bool f[10001];
int main()
{
   void floodfill(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   if (m!=n-1)
      printf("NO\n");
   else
   {
      for (int i=1;i<=m;i++)
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
      for (int i=1;i<=n;i++)
         if (!f[i])
         {
            f[0]=true;
            break;
         }
      printf("%s\n",f[0]?"NO":"YES");
   }
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   f[x]=true;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
   }
}
