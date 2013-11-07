#include <cstdio>
#include <cstdlib>
#include <cstring>
int s[10001],b[10001],f[10001],g[10001],c[10001],d[10001],a[200001][2],q[400001];
bool flag[10001][2];
int main()
{
   int n,m=0;
   scanf("%d",&n);
   for (int i=2;i<n;i++)
   {
      scanf("%d",&s[i]);
      for (int j=1;j<=s[i];j++)
      {
         int x;
         scanf("%d",&x);
         a[++m][0]=i;
         a[m][1]=b[x];
         b[x]=m;
      }
   }
   memset(f,0,sizeof(f));
   memset(c,0,sizeof(c));
   for (int i=0;i<n;i++)
      d[i]=s[i];
   int l,r;
   l=r=1;
   q[1]=1,f[1]=2,flag[1][0]=true;
   while (l<=r)
   {
      int x=q[l],k=f[x];
      for (int i=b[x];i;i=a[i][1])
      {         
         int y=a[i][0];
         if (!flag[x][1])
            d[y]--;
         if (k==2)
            c[y]++;
         if (c[y]==d[y] && !f[y])
         {
            if (!flag[y][0])
            {
               q[++r]=y;
               flag[y][0]=true;
            }
            f[y]=1;
         }
         if (c[y]>d[y] && f[y]!=2)
         {
            if (!flag[y][0])
            {
               q[++r]=y;
               flag[y][0]=true;
            }
            f[y]=2;
         }
      }
      flag[x][0]=false;
      flag[x][1]=true;
      l++;
   }
   for (int i=0;i<n;i++)
      g[i]=2,c[i]=s[i];
   memset(d,0,sizeof(d));
   memset(flag,0,sizeof(flag));
   l=r=1;
   q[1]=0,g[0]=0,flag[0][0]=true;
   int sum=0;
   while (l<=r)
   {
      int x=q[l],k=g[x];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if (!flag[x][1])
            c[y]--;
         if (!k)
            d[y]++;
         if (c[y]==d[y] && g[y]==2)
         {
            if (!flag[y][0])
            {
               q[++r]=y;
               flag[y][0]=true;
            }
            g[y]=1;
         }
         if (c[y]<d[y] && g[y])
         {
            if (!flag[y][0])
            {
               q[++r]=y;
               flag[y][0]=true;
            }
            g[y]=0;
         }
      }
      flag[x][0]=false;
      flag[x][1]=true;
      l++;
   }
   for (int i=0;i<n;i++)
      if (f[i]!=g[i])
         printf("?\n");
      else if (f[i]==1)
         printf("1/2\n");
      else
         printf("%d\n",f[i]/2);
   system("pause");
   return(0);
}
