#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,now[110],a[110];
bool use[110];
int main()
{
   void search(int,int);
   while (1)
   {
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      search(1,1);
   }
   system("pause");
   return(0);
}
void search(int dep,int pos)
{
   if (dep==m+1)
   {
      for (int i=1;i<m;i++)
         printf("%d ",now[i]);
      printf("%d\n",now[m]);
      return;
   }
   if (m-dep>n-pos)
      return;
   if (a[pos]!=a[pos-1] || use[pos-1])
   {
      now[dep]=a[pos];
      use[pos]=true;
      search(dep+1,pos+1);
      use[pos]=false;
   }
   search(dep,pos+1);
}
