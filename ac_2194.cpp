#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[40];
double a0[110],a1[110],a2[110],a12[110],c[110];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int m1,m2;
      scanf("%d",&m1);
      memset(f,0,sizeof(f));
      for (int i=1;i<=m1;i++)
      {
         int x;
         scanf("%d",&x);
         f[x]=true;
      }
      scanf("%d",&m2);
      int m12=0;
      for (int i=1;i<=m2;i++)
      {
         int x;
         scanf("%d",&x);
         if (f[x])
            m12++;
      }
      int m;
      scanf("%d",&m);
      m1-=m12,m2-=m12;
      int m0=n-m1-m2-m12;
      double p0,p1,p2,p12;
      p0=double(m0)/n;
      p1=double(m1)/n;
      p2=double(m2)/n;
      p12=double(m12)/n;
      a0[0]=a1[0]=a2[0]=a12[0]=1;
      for (int i=1;i<=m;i++)
      {
         a0[i]=a0[i-1]*p0;
         a1[i]=a1[i-1]*p1;
         a2[i]=a2[i-1]*p2;
         a12[i]=a12[i-1]*p12;
      }
      c[0]=1;
      for (int i=1;i<=m;i++)
         c[i]=c[i-1]*i;
      double ans=0;
      for (int i=0;i<=m;i++)
      {
         if (i&1)
            continue;
         int k=i>>1;
         for (int j=0;j<=k;j++)
         {
            int x=i-j,y=k-j,z=m-x-y-j;
            if (z<0)
               continue;
            ans+=a0[z]*a1[y]*a2[x]*a12[j]*c[m]/(c[x]*c[y]*c[z]*c[j]);
         }
      }
      static int id=0;
      printf("Case %d: %.5f\n",++id,ans);
   }
   system("pause");
   return(0);
}
