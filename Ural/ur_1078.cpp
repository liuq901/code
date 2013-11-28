#include <cstdio>
#include <cstdlib>
int l[500],r[500],p[500],f[500],pre[500];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&l[i],&r[i]);
      p[i]=i;
   }
   for (int i=1;i<=n-1;i++)
      for (int j=i+1;j<=n;j++)
         if (l[i]>l[j] || l[i]==l[j] && r[i]>r[j])
         {
            int t;
            t=l[i],l[i]=l[j],l[j]=t;
            t=r[i],r[i]=r[j],r[j]=t;
            t=p[i],p[i]=p[j],p[j]=t;
         }
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      f[i]=1;
      for (int j=1;j<=i-1;j++)
         if (r[j]>r[i] && f[j]+1>f[i])
         {
            f[i]=f[j]+1;
            pre[i]=j;
         }
      if (f[i]>ans)
      {
         ans=f[i];
         pre[0]=i;
      }
   }
   printf("%d\n",ans);
   for (int i=pre[0];i;i=pre[i])
      printf("%d%c",p[i],pre[i]?' ':'\n');
   system("pause");
   return(0);
}
