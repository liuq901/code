#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,n,l1,l2,l3,c1,c2,c3,x,y,t;
   long long a[10001],f[10001];
   scanf("%d%d%d%d%d%d",&l1,&l2,&l3,&c1,&c2,&c3);
   scanf("%d",&n);
   scanf("%d%d",&x,&y);
   if (x>y)
      t=x,x=y,y=t;
   a[1]=0;
   for (i=2;i<=n;i++)
      scanf("%I64d",&a[i]);
   memset(f,26,sizeof(f));
   f[x]=0;
   for (i=x+1;i<=y;i++)
      for (j=x;j<=i-1;j++)
      {
         if (a[i]-a[j]>0 && a[i]-a[j]<=l1 && f[j]+c1<f[i])
            f[i]=f[j]+c1;
         if (a[i]-a[j]>l1 && a[i]-a[j]<=l2 && f[j]+c2<f[i])
            f[i]=f[j]+c2;
         if (a[i]-a[j]>l2 && a[i]-a[j]<=l3 && f[j]+c3<f[i])
            f[i]=f[j]+c3;
      }
   printf("%I64d\n",f[y]);
   system("pause");
   return(0);
}
