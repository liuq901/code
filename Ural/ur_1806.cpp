#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef map <ll,int>::iterator data;
ll ten[11],s[50010];
map <ll,int> A;
int tot,value[11],b[50010],a[7000000][3];
int main()
{
   void add(int,int,int),spfa(int);
   int n;
   scanf("%d",&n);
   for (int i=0;i<10;i++)
      scanf("%d",&value[i]);
   ten[9]=1;
   for (int i=8;i>=0;i--)
      ten[i]=ten[i+1]*10;
   for (int i=1;i<=n;i++)
   {
      scanf("%lld",&s[i]);
      A[s[i]]=i;
   }
   for (int i=1;i<=n;i++)
      for (int j=0;j<10;j++)
      {
         ll now=s[i]-(s[i]/ten[j]%10*ten[j]);
         for (int k=0;k<10;k++)
         {
            if (now!=s[i])
            {
               data t=A.find(now);
               if (t!=A.end())
                  add(i,t->second,value[j]);
            }
            now+=ten[j];
         }
         for (int k=j+1;k<10;k++)
         {
            int p=s[i]/ten[j]%10,q=s[i]/ten[k]%10;
            if (p==q)
               continue;
            ll tmp=s[i]-p*ten[j]-q*ten[k]+p*ten[k]+q*ten[j];
            data t=A.find(tmp);
            if (t!=A.end())
               add(i,t->second,value[j]);
         }
      }
   spfa(n);
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
}
int q[50010],d[50010],pre[50010],ans[50010];
bool f[50010];
void spfa(int T)
{
   memset(d,63,sizeof(d));
   int l,r;
   l=0,r=1,d[1]=0,q[1]=1,f[1]=true;
   while (l!=r)
   {
      l++;
      if (l==50005)
         l=1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            pre[y]=x;
            if (!f[y])
            {
               f[y]=true;
               r++;
               if (r==50005)
                  r=1;
               q[r]=y;
            }
         }
      }
      f[x]=false;
   }
   if (d[T]==1061109567)
   {
      printf("-1\n");
      return;
   }
   printf("%d\n",d[T]);
   int m=0;
   for (int i=T;i!=1;i=pre[i])
      ans[++m]=i;
   ans[++m]=1;
   printf("%d\n",m);
   for (int i=m;i;i--)
      printf("%d%c",ans[i],i==1?'\n':' ');
}
