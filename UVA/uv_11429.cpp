#include <cstdio>
#include <cstring>
#include <cstdlib>
int r,c[1001],d[1001];
int main()
{
   double calc(int,int);
   int i,m,n,a,b;
   double ans;
   while (1)
   {
      scanf("%d%d",&r,&n);
      if (r==0 && n==0)
         break;
      ans=0;
      for (i=1;i<=n;i++)
      {
         memset(c,-1,sizeof(c));
         scanf("%d%d",&a,&b);
         m=0;
         while (c[a]==-1)
         {
            c[a]=m;
            a*=r;
            d[m]=a/b;
            a%=b;
            m++;
         }
         ans+=calc(m-c[a],m);
      }
      printf("%.6lf\n",ans);
   }
   system("pause");
   return(0);
}
double calc(int k,int m)
{
   int i;
   double x,t,ans;
   x=0;
   t=1;
   for (i=1;i<=k;i++)
   {
      x=(x+d[m-i])/r;
      t/=r;
   }
   x/=1-t;
   ans=x*k;
   for (i=1;i<=k;i++)
      ans=(ans+d[m-i]*(k-i+1))/r;
   ans=ans/(1-t)+x*(m-k);
   for (i=k+1;i<=m;i++)
      ans=(ans+d[m-i]*(m-i+1))/r;
   return(ans);
}
