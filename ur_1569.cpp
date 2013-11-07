#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,min,ans[101][2],a[101][101];
int main()
{
   void work(int);
   int m;
   scanf("%d%d",&n,&m);
   memset(a,26,sizeof(a));
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[x][y]=a[y][x]=1;
   }
   for (int i=1;i<=n;i++)
      a[i][i]=0;
   for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            if (a[i][k]+a[k][j]<a[i][j])
               a[i][j]=a[i][k]+a[k][j];
   min=20000000;
   for (int i=1;i<=n;i++)
      work(i);
   for (int i=1;i<=n-1;i++)
      printf("%d %d\n",ans[i][0],ans[i][1]);
   system("pause");
   return(0);
}
void work(int x)
{
   int l,r,p[101],d[101],q[101];
   bool f[101]={0};
   q[1]=x;
   d[x]=0;
   f[x]=true;
   p[x]=0;
   l=r=1;
   int max=0;
   while (l<=r)
   {
      int k=q[l];
      for (int i=1;i<=n;i++)
      {
         if (a[k][i]!=1 || f[i])
            continue;
         r++;
         q[r]=i;
         p[i]=k;
         d[i]=d[k]+1;
         f[i]=true;
      }
      if (d[k]>max)
         max=d[k];
      l++;
   }
   int sum=0;
   for (int i=1;i<=n;i++)
      if (d[i]==max)
         sum++;
   int k=-1;
   for (int i=1;i<=n;i++)
   {
      if (d[i]!=1)
         continue;
      int tot=0;
      for (int j=1;j<=n;j++)
         if (d[j]==max && a[i][j]==max-1)
            tot++;
      if (tot==sum)
      {
         k=i;
         break;
      }
   }
   int t;
   if (k==-1)
      t=2*max;
   else
      t=2*max-1;
   if (t<min && k!=-1)
   {
      q[1]=x;
      q[2]=k;
      memset(f,0,sizeof(f));
      f[x]=f[k]=true;
      p[x]=0;
      p[k]=x;
      d[x]=0;
      d[k]=1;
      l=1,r=2;
      while (l<=r)
      {
         int k=q[l];
         for (int i=1;i<=n;i++)
         {
            if (a[k][i]!=1 || f[i])
               continue;
            r++;
            q[r]=i;
            p[i]=k;
            d[i]=d[k]+1;
            f[i]=true;
         }
         if (d[k]>max)
            max=d[k];
         l++;
      }
   }
   if (t<min)
   {
      min=t;
      sum=0;
      for (int i=1;i<=n;i++)
      {
         if (i==x)
            continue;
         sum++;
         ans[sum][0]=i;
         ans[sum][1]=p[i];
      }
   }
}
