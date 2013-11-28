#include <cstdio>
#include <cstdlib>
const double pi=3.1415926535897,eps=-1e-10;
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      long long d[51];
      double l[51];
      for (int i=2;i<=n;i++)
         scanf("%lld",&d[i]);
      d[1]=60;
      for (int i=1;i<=n;i++)
         scanf("%lf",&l[i]);
      long long begin,end;
      scanf("%lld%lld",&begin,&end);
      if (begin>end)
      {
         long long t;
         t=begin,begin=end,end=t;
      }
      double x[51],y[51];
      for (int i=1;i<=n;i++)
      {
         x[i]=begin%d[i];
         y[i]=end%d[i];
         begin/=d[i];
         end/=d[i];
      }
      for (int i=2;i<=n;i++)
      {
         x[i]+=x[i-1]/d[i-1];
         y[i]+=y[i-1]/d[i-1];
      }
      for (int i=1;i<=n-1;i++)
         if (l[i]*d[i+1]<l[i+1])
            l[i+1]=l[i]*d[i+1];
      double ans1,ans2,s1,s2;
      ans1=ans2=s1=s2=0;
      for (int i=1;i<=n;i++)
      {
         double p,q,k,t;
         t=y[i]-x[i]-s1;
         if (t<eps)
            t+=d[i];
         p=ans1+t/d[i]*l[i];
         t=x[i]-s2-y[i];
         if (t<eps)
            t+=d[i];
         q=ans2+t/d[i]*l[i];
         k=y[i]-x[i];
         if (k<eps)
            k+=d[i];
         if (k-s1<eps)
         {
            t=s1-k;
            if (ans1+t/d[i]*l[i]<p)
               p=ans1+t/d[i]*l[i];
         }
         else
         {
            t=d[i]-k+s1;
            if (ans1+t/d[i]*l[i]<q)
               q=ans1+t/d[i]*l[i];
         }
         k=x[i]-y[i];
         if (k<eps)
            k+=d[i];
         if (k-s2<eps)
         {
            t=s2-k;
            if (ans2+t/d[i]*l[i]<q)
               q=ans2+t/d[i]*l[i];
         }
         else
         {
            t=d[i]-k+s2;
            if (ans2+t/d[i]*l[i]<p)
               p=ans2+t/d[i]*l[i];
         }
         ans1=p,ans2=q;
         s1=y[i]-x[i];
         if (s1<eps)
            s1+=d[i];
         s1/=d[i];
         s2=x[i]-y[i];
         if (s2<eps)
            s2+=d[i];
         s2/=d[i];
      }
      double ans;
      ans=ans1<ans2?ans1:ans2;
      printf("%.10lf\n",ans*2*pi);
   }
   system("pause");
   return(0);
}
