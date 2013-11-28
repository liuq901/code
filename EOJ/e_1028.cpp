#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
class ip
{
   int a,b,c,d;
   friend bool operator <(ip,ip);
public:
   ip(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
};
bool operator <(ip a,ip b)
{
   if (a.a!=b.a)
      return(a.a<b.a);
   if (a.b!=b.b)
      return(a.b<b.b);
   if (a.c!=b.c)
      return(a.c<b.c);
   return(a.d<b.d);
}
map <ip,int> s;
int w[110][110];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   int t=0;
   memset(w,63,sizeof(w));
   int inf=w[0][0];
   for (int i=1;i<=m;i++)
   {
      int a,b,c,d;
      scanf("%d.%d.%d.%d",&a,&b,&c,&d);
      ip x(a,b,c,d);
      scanf("%d.%d.%d.%d",&a,&b,&c,&d);
      ip y(a,b,c,d);
      int z;
      scanf("%d",&z);
      if (!s.count(x))
         s[x]=++t;
      if (!s.count(y))
         s[y]=++t;
      w[s[x]][s[y]]=w[s[y]][s[x]]=z;
   }
   for (int i=1;i<=n;i++)
      w[i][i]=0;
   for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            if (w[i][k]+w[k][j]<w[i][j])
               w[i][j]=w[i][k]+w[k][j];
   int Q;
   scanf("%d",&Q);
   while (Q--)
   {
      int a,b,c,d;
      scanf("%d.%d.%d.%d",&a,&b,&c,&d);
      ip x(a,b,c,d);
      scanf("%d.%d.%d.%d",&a,&b,&c,&d);
      ip y(a,b,c,d);
      if (!s.count(x) || !s.count(y) || w[s[x]][s[y]]==inf)
         printf("-1\n");
      else
         printf("%d\n",w[s[x]][s[y]]);
   }
   system("pause");
   return(0);
}
