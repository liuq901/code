#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,n,b[1001],f[1001],a[1001][1001];
int main()
{
   int hungary(int);
   int m,i,j,x;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&m);
      memset(f,0,sizeof(f));
      for (j=1;j<=m;j++)
      {
         scanf("%d",&x);
         f[x]=1;
      }
      b[i]=1;
      a[i][0]=0;
      for (j=1;j<=n;j++)
      {
         if (f[j])
            continue;
         a[i][0]++;
         a[i][a[i][0]]=j;
      }
   }
   memset(f,0,sizeof(f));
   ans=0;
   for (i=1;i<=n;i++)
      hungary(i);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int hungary(int t)
{
   int i,x;
   for (i=b[t];i<=a[t][0];i++)
   {
      b[t]=i+1;
      x=a[t][i];
      if (!f[x])
      {
         f[x]=t;
         ans++;
         return(1);
      }
      if (hungary(f[x]))
      {
         f[x]=t;
         return(1);
      }
   }
   return(0);
}
