#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[1001],f[1001],a[10001][2],e[10001][3];
int main()
{
   int get(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         f[i]=i;
      int tot=0;
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (!z)
         {
            f[get(x)]=get(y);
            continue;
         }
         e[++tot][0]=x,e[tot][1]=y,e[tot][2]=z;
      }
      int sum=0;
      for (int i=1;i<=n;i++)
      {
         get(i);
         if (f[i]==i)
            sum++;
      }
      memset(b,0,sizeof(b));
      int d[1001]={0};
      for (int i=1;i<=tot;i++)
      {
         int x=f[e[i][0]],y=f[e[i][1]];
         if (e[i][2]==1)
         {
            int t;
            t=x,x=y,y=t;
         }
         a[i][0]=y;
         a[i][1]=b[x];
         b[x]=i;
         d[y]++;
      }
      int q[1001][2],l,r;
      l=1,r=0;
      for (int i=1;i<=n;i++)
         if (f[i]==i && !d[i])
         {
            q[++r][0]=i;
            q[r][1]=0;
         }
      while (l<=r)
      {
         int x=q[l][0];
         for (int i=b[x];i;i=a[i][1])
         {
            int y=a[i][0];
            d[y]--;
            if (!d[y])
            {
               q[++r][0]=y;
               q[r][1]=q[l][1]+1;
            }
         }
         l++;
      }
      if (r==sum)
         printf("%d\n",q[r][1]);
      else
         printf("NO\n");
   }
   system("pause");
   return(0);
}
int get(int x)
{
   if (x!=f[x])
      f[x]=get(f[x]);
   return(f[x]);
}
