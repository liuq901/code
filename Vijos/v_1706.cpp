#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long int64;
int l[5001],r[5001],a[5001];
int64 f[5001][2];
int main()
{
   int64 max(int64,int64),count(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=2;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      if (!l[x])
         l[x]=i;
      else
      {
         int t=l[x];
         while (r[t])
            t=r[t];
         r[t]=i;
      }
   }
   memset(f,-1,sizeof(f));
   printf("%I64d\n",max(count(1,0),count(1,1)));
   system("pause");
   return(0);
}
int64 max(int64 x,int64 y)
{
   return(x>y?x:y);
}
int64 count(int x,int p)
{
   if (f[x][p]!=-1)
      return(f[x][p]);
   int64 ans=0;
   for (int i=l[x];i;i=r[i])
      ans+=count(i,1-p);
   if (p)
      ans+=a[x];
   if (p && count(x,0)>ans)
      ans=count(x,0);
   if (ans>0)
      f[x][p]=ans;
   else
      f[x][p]=0;
   return(f[x][p]);
}
