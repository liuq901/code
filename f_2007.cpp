#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int tot,link[310],b[1010],a[1000000][2];
bool f[310];
int main()
{
   void add(int,int);
   bool hungary(int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      memset(b,0,sizeof(b));
      tot=0;
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         for (int j=x;j<y;j++)
            add(j,i);
      }
      int ans=0;
      for (int start=0;start<5;start++)
      {
         memset(link,-1,sizeof(link));
         int now=0;
         for (int i=start;i<=1000;i+=5)
         {
            memset(f,0,sizeof(f));
            now+=hungary(i);
         }
         ans=max(ans,now);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void add(int x,int y)
{
   a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
bool hungary(int x)
{
   if (x==-1)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(link[y]))
      {
         link[y]=x;
         return(true);
      }
   }
   return(false);
}
