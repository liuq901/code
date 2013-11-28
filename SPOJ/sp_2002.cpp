#include <cstdio>
#include <cstdlib>
int n,v[26];
int main()
{
   void work();
   int t,i;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   long double calc(int);
   int i,a,b;
   scanf("%d%d%d",&n,&a,&b);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&v[i]);
      a+=v[i];
      b+=v[i];
      v[i]*=2;
   }
   printf("%.9lf\n",(double)(calc(b)-calc(a)));
}
long double calc(int p)
{
   long double count(int);
   long double ans;
   int i,j,t,s,max;
   if (p<0)
      return(0);
   max=(1<<n)-1;
   ans=count(p);
   for (i=1;i<=max;i++)
   {
      s=0;
      t=p;
      for (j=1;j<=n;j++)
         if (i>>j-1&1)
         {
            t-=v[j];
            s++;
         }
      if (s%2==0)
         s=1;
      else
         s=-1;
      ans+=s*count(t);
   }
   for (i=1;i<=n;i++)
      ans/=v[i];
   return(ans);
}
long double count(int x)
{
   int i;
   long double ans;
   if (x<0)
      return(0);
   ans=1;
   for (i=1;i<=n;i++)
      ans*=(long double)x/i;
   return(ans);
}
