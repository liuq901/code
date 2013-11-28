#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int w,h,n;
   scanf("%d%d%d",&w,&h,&n);
   int x[101],y[101];
   bool map[110][110]={0};
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&x[i],&y[i]);
      x[i]++;
      y[i]++;
      map[x[i]][y[i]]=true;
   }
   int a[100]={0};
   for (int i=1;i<=n;i++)
      for (int j=0;j<4;j++)
      {
         int p=x[i],q=y[i];
         while (map[p][q])
         {
            a[i-1]++;
            p+=c[j][0];
            q+=c[j][1];
         }
      }
   memset(map,false,sizeof(map));
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&x[i],&y[i]);
      x[i]++;
      y[i]++;
      map[x[i]][y[i]]=true;
   }
   int b[100]={0};
   for (int i=1;i<=n;i++)
      for (int j=0;j<4;j++)
      {
         int p=x[i],q=y[i];
         while (map[p][q])
         {
            b[i-1]++;
            p+=c[j][0];
            q+=c[j][1];
         }
      }
   sort(a,a+n);
   sort(b,b+n);
   bool flag=false;
   for (int i=0;i<n;i++)
      if (a[i]!=b[i])
      {
         printf("NO\n");
         flag=true;
         break;
      }
   if (!flag)
      printf("YES\n");
}
