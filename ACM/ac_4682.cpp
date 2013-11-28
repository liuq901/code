#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int m=30;
int tot,l[3000000],r[3000000];
int main()
{
   void insert(int,bool);
   bool find(int,bool);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      tot=1;
      l[1]=r[1]=0;
      int p=1;
      for (int i=0;i<=m;i++)
      {
         insert(p,false);
         p=l[p];
      }
      int now=0,ans=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         now^=x;
         int t=1,value=0;
         for (int j=m;j>=0;j--)
         {
            int p=now>>j&1;
            if (!p)
            {
               if (find(t,true))
               {
                  value=(value<<1)+1;
                  t=r[t];
                  continue;
               }
               value=value<<1;
               t=l[t];
            }
            else
            {
               if (find(t,false))
               {
                  value=(value<<1)+1;
                  t=l[t];
                  continue;
               }
               value=value<<1;
               t=r[t];
            }
         }
         ans=max(ans,value);
         t=1;
         for (int j=m;j>=0;j--)
         {
            int p=now>>j&1;
            if (!p)
            {
               insert(t,false);
               t=l[t];
            }
            else
            {
               insert(t,true);
               t=r[t];
            }
         }
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void insert(int x,bool right)
{
   if (!right && !l[x])
   {
      l[x]=++tot;
      l[tot]=r[tot]=0;
   }
   if (right && !r[x])
   {
      r[x]=++tot;
      l[tot]=r[tot]=0;
   }
}
bool find(int x,bool right)
{
   if (!right)
      return(l[x]);
   return(r[x]);
}
