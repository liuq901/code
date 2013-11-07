#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[260][260],v[260][260];
int main()
{
   void insert(int,int,int);
   int find(int,int);
   int m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         scanf("%d",&v[i][j]);
         insert(i,j,v[i][j]);
      }
   while (m--)
   {
      int op;
      scanf("%d",&op);
      if (op==1)
      {
         int x1,x2,y1,y2;
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         if (x1>x2)
            swap(x1,x2);
         if (y1>y2)
            swap(y1,y2);
         printf("%d\n",find(x2,y2)-find(x1-1,y2)-find(x2,y1-1)+find(x1-1,y1-1));
      }
      else
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         insert(x,y,z-v[x][y]);
         v[x][y]=z;
      }
   }
   system("pause");
   return(0);
}
void insert(int x,int y,int v)
{
   for (int i=x;i<=n;i+=i&-i)
      for (int j=y;j<=n;j+=j&-j)
         a[i][j]+=v;
}
int find(int x,int y)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      for (int j=y;j;j-=j&-j)
         ans+=a[i][j];
   return(ans);
}
