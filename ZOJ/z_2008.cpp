#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[1000001],a[1000001][3],e[1000001][3];
int main()
{
   int spfa(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=m;i++)
         scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         a[i][0]=e[i][1];
         a[i][1]=e[i][2];
         a[i][2]=b[e[i][0]];
         b[e[i][0]]=i;
      }
      int ans=spfa(n);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         a[i][0]=e[i][0];
         a[i][1]=e[i][2];
         a[i][2]=b[e[i][1]];
         b[e[i][1]]=i;
      }
      ans+=spfa(n);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int d[1000001],q[1000001];
bool f[1000001];
int spfa(int n)
{
   int l=0,r=1;
   memset(d,26,sizeof(d));
   d[1]=0;
   q[1]=1;
   f[1]=true;
   while (l!=r)
   {
      l++;
      if (l>1000000)
         l=1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            if (!f[y])
            {
               f[y]=true;
               r++;
               if (r>1000000)
                  r=1;
               q[r]=y;
            }
         }
      }
      f[x]=false;
   }
   int s=0;
   for (int i=1;i<=n;i++)
      s+=d[i];
   return(s);
}
