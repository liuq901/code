#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,c[5001],b[5001],pre[5001],e[5001],f[100001],a[100001][2];
int main()
{
   void floodfill(int);
   scanf("%d",&n);
   int m=0;
   for (int i=1;i<n;i++)
   {
      int k;
      scanf("%d",&k);
      for (int j=1;j<=k;j++)
      {
         int x;
         scanf("%d",&x);
         a[++m][0]=x;
         a[m][1]=b[i];
         b[i]=m;
      }
   }
   floodfill(1);
   int ans=0;
   for (int i=1;i<=m;i++)
      if (f[i]>ans)
         ans=f[i];
   printf("%d\n",ans+1);
   system("pause");
   return(0);
}
void floodfill(int x)
{
   c[x]=-1;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (!c[y])
      {
         pre[y]=x;
         e[y]=i;
         floodfill(y);
         continue;
      }
      int k=y,max=0;
      while (c[k]==1)
      {
         if (f[e[k]]>max)
            max=f[e[k]];
         k=pre[k];
      }
      int t=x;
      while (t!=k)
      {
         f[e[t]]=max+1;
         t=pre[t];
      }
      f[i]=max+1;
      pre[y]=x;
      e[y]=i;
   }
   c[x]=1;
}
