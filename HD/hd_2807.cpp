#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
map <ll,int> s;
int t[90],v[90],c[90][90],f[90][90],va[90][90],a[90][90][90];
ll num[90];
int main()
{
   ll hash(int *,int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int k=1;k<=n;k++)
         for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
               scanf("%d",&a[k][i][j]);
      memset(c,0,sizeof(c));
      srand(2026);
      for (int i=1;i<=m;i++)
         v[i]=rand()+26;
      memset(va,0,sizeof(va));
      for (int k=1;k<=n;k++)
      {
         for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
               va[k][i]+=a[k][i][j]*v[j];
         num[k]=hash(va[k],m);
      }
      memset(f,63,sizeof(f));
      for (int A=1;A<=n;A++)
      {
         s.clear();
         for (int B=1;B<=n;B++)
         {
            if (A==B)
               continue;
            memset(t,0,sizeof(t));
            for (int i=1;i<=m;i++)
               for (int j=1;j<=m;j++)
                  t[i]+=a[A][i][j]*va[B][j];
            ll now=hash(t,m);
            if (s.count(now))
               s[now]=-1;
            else
               s[now]=B;
         }
         for (int C=1;C<=n;C++)
            if (s.count(num[C]))
            {
               int p=s[num[C]];
               if (p!=C)
                  f[A][C]=1;
            }
      }
      for (int i=1;i<=n;i++)
         f[i][i]=0;
      for (int k=1;k<=n;k++)
         for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
               if (f[i][k]+f[k][j]<f[i][j])
                  f[i][j]=f[i][k]+f[k][j];
      int Q;
      scanf("%d",&Q);
      while (Q--)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (f[x][y]>10000)
            printf("Sorry\n");
         else
            printf("%d\n",f[x][y]);
      }
   }
   system("pause");
   return(0);
}
ll hash(int *a,int n)
{
   ll ret=0;
   for (int i=1;i<=n;i++)
      ret+=ret*n+a[i];
   return(ret);
}
