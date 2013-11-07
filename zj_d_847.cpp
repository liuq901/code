#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct point
{
   int x,y,pos;
};
bool operator <(point a,point b)
{
   return(a.x<b.x || a.x==b.x && a.y>b.y);
}
point a[10010];
int c[1010],ans[10010];
int main()
{
   int find(int);
   void insert(int);
   int n;
   while (scanf("%d",&n)==1)
   {
      memset(c,0,sizeof(c));
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i].x,&a[i].y);
         a[i].pos=i;
      }
      sort(a+1,a+n+1);
      for (int i=1;i<=n;i++)
      {
         ans[a[i].pos]=find(a[i].y-1);
         insert(a[i].y);
      }
      for (int i=1;i<=n;i++)
         printf("%d\n",ans[i]);
   }
   system("pause");
   return(0);
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
void insert(int x)
{
   for (int i=x;i<=1000;i+=i&-i)
      c[i]++;
}
