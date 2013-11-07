#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
map <string,int> s;
vector <int> a[100010];
char T[1000000];
ll f[100010],g[100010];
int pS,pF,F[100010],G[100010];
bool vis[100010];
int main()
{
   void dp(int),count(int),calc(ll &,ll&,ll,ll);
   gets(T);
   while (1)
   {
      sscanf(T,"%d%d",&pS,&pF);
      if (!pS && !pF)
         break;
      for (int i=1;i<=100000;i++)
         a[i].clear();
      s.clear();
      memset(vis,0,sizeof(vis));
      int n=0;
      while (1)
      {
         gets(T);
         if (isdigit(T[0]))
            break;
         stringstream sin(T);
         string name;
         sin>>name;
         if (!s.count(name))
            s[name]=++n;
         int num=s[name];
         while (sin>>name)
         {
            if (!s.count(name))
               s[name]=++n;
            int p=s[name];
            a[num].push_back(p);
            vis[p]=true;
         }
      }
      ll ans=0;
      int cs=0,cf=0;
      for (int i=1;i<=n;i++)
         if (!vis[i])
         {
            dp(i);
            ans+=f[i];
            ll a,b;
            calc(a,b,F[i],f[i]);
            cs+=a,cf+=b;
         }
      static int id=0;
      printf("%d. %d %d ",++id,cs,cf);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void dp(int x)
{
   ll sum=0,tot=0;
   int p=0,q=0;
   for (int i=0;i<a[x].size();i++)
   {
      int y=a[x][i];
      dp(y);
      sum+=f[y],tot+=g[y];
      p+=F[y],q+=G[y];
   }
   f[x]=min(sum+pS,tot+pF),g[x]=min(sum,tot+pF);
   F[x]=G[x]=1<<30;
   if (f[x]==sum+pS)
      F[x]=min(F[x],p+1);
   if (f[x]==tot+pF)
      F[x]=min(F[x],q+1);
   if (g[x]==sum)
      G[x]=min(G[x],p);
   if (g[x]==tot+pF)
      G[x]=min(G[x],q+1);
}
void calc(ll &a,ll &b,ll c,ll d)
{
   a=(c*pF-d)/(pF-pS);
   b=(c*pS-d)/(pS-pF);
}
