#include <cstdio>
#include <cstdlib>
#include <map>
#include <utility>
using namespace std;
typedef map <int,int>::iterator data;
map <int,int> a;
pair <int,int> b[100000];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      a.clear();
      a[0]=1;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         int t=0;
         for (data k=a.begin();k!=a.end();k++)
            b[++t]=*k;
         for (int i=1;i<=t;i++)
         {
            if (b[i].first+x>m)
               break;
            a[b[i].first+x]+=b[i].second;
         }
      }
      printf("%d\n",a[m]);
   }
   system("pause");
   return(0);
}
