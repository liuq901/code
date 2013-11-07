#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[10001],c[10001],d[10001];
long long a[10001],f[10001];
int main()
{
   int n,l1,l2,l3,c1,c2,c3,x,y,i,t,t1,t2,t3,r1,r2,r3;
   scanf("%d%d%d%d%d%d",&l1,&l2,&l3,&c1,&c2,&c3);
   scanf("%d",&n);
   scanf("%d%d",&x,&y);
   if (x>y)
      i=x,x=y,y=i;
   a[1]=0;
   for (i=2;i<=n;i++)
      scanf("%I64d",&a[i]);
   memset(f,26,sizeof(f));
   f[x]=0;
   b[1]=x;
   c[1]=x;
   d[1]=x;
   t1=t2=t3=r1=r2=r3=1;
   for (i=x+1;i<=y;i++)
   {
      while (t1<=r1)
      {
         t=b[t1];
         if (a[i]-a[t]<=l1)
         {
            if (f[t]+c1<f[i])
               f[i]=f[t]+c1;
            break;
         }
         t1++;
      }
      r1++;
      b[r1]=i;
      while (t2<=r2)
      {
         t=c[t2];
         if (a[i]-a[t]<=l2)
         {
            if (f[t]+c2<f[i])
               f[i]=f[t]+c2;
            break;
         }
         t2++;
      }
      r2++;
      c[r2]=i;
      while (t3<=r3)
      {
         t=d[t3];
         if (a[i]-a[t]<=l3)
         {
            if (f[t]+c3<f[i])
               f[i]=f[t]+c3;
            break;
         }
         t3++;
      }
      r3++;
      d[r3]=i;
   }
   printf("%I64d\n",f[y]);
   system("pause");
   return(0);
}
