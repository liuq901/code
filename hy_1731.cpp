#include <cstdio>
#include <cstdlib>
#include <cstring>
int s[1001],a[1001][1001][2];
int main()
{
   void spfa(int);
   int n,m0,m1;
   scanf("%d%d%d",&n,&m0,&m1);
   for (int i=2;i<=n;i++)
      a[i][++s[i]][0]=i-1;
   for (int i=1;i<=m0;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if (x>y)
      {
         int t;
         t=x,x=y,y=t;
      }
      a[x][++s[x]][0]=y;
      a[x][s[x]][1]=z;
   }
   for (int i=1;i<=m1;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if (x>y)
      {
         int t;
         t=x,x=y,y=t;
      }
      a[y][++s[y]][0]=x;
      a[y][s[y]][1]=-z;
   }
   spfa(n);
   system("pause");
   return(0);
}
void spfa(int n)
{
   int l=0,r=1,q[1001],d[1001],v[1001];
   bool f[1001]={0};
   q[1]=v[1]=1;
   memset(d,26,sizeof(d));
   d[1]=0;
   f[1]=true;
   while (l!=r)
   {
      l++;
      if (l>1000)
         l=1;
      int x=q[l];
      for (int i=1;i<=s[x];i++)
      {
         int y=a[x][i][0];
         if (d[x]+a[x][i][1]<d[y])
         {
            d[y]=d[x]+a[x][i][1];
            if (!f[y])
            {
               f[y]=true;
               r++;
               if (r>1000)
                  r=1;
               q[r]=y;
               v[y]++;
               if (v[y]>n)
               {
                  printf("-1\n");
                  return;
               }
            }
         }
      }
      f[x]=false;
   }
   int ans=d[n]-d[1];
   printf("%d\n",ans<400000000?ans:-2);
}
