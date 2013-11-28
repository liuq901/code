#include <cstdio>
#include <cstdlib>
#include <cstring>
long long n,k,power[50],c[50][50];
int main()
{
   long long work(long long);
   long long x,y,b;
   scanf("%I64d%I64d%I64d%I64d",&x,&y,&k,&b);
   n=0;
   power[n]=1;
   while (power[n]<y)
   {
      n++;
      power[n]=power[n-1]*b;
   }
   memset(c,-1,sizeof(c));
   printf("%I64d\n",work(y)-work(x-1));
   system("pause");
   return(0);
}
long long work(long long x)
{
   long long calc(long long,long long);
   long long i,j,t;
   long long a[50],b[50];
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   for (i=n;i>=0;i--)
      if (x>=power[i])
      {
         x-=power[i];
         b[i]=1;
      }
   j=0;
   for (i=n;i>=0;i--)
      if (b[i])
      {
         j++;
         a[j]=i;
      }
   t=0;
   for (i=1;i<=j;i++)
      if (k-i+1>0)
         t+=calc(a[i],k-i+1);
   if (j>=k)
      t++;
   return(t);
}
long long calc(long long x,long long y)
{
   if (c[x][y]!=-1)
      return(c[x][y]);
   if (x<y)
      c[x][y]=0;
   else if (x==y || y==0)
      c[x][y]=1;
   else
      c[x][y]=calc(x-1,y-1)+calc(x-1,y);
   return(c[x][y]);
}
