#include <cstdio>
#include <cstdlib>
#include <cstring>
long long a[20],f[20][200];
int main()
{
   void prepare(),work(long long,long long);
   long long n,k;
   prepare();
   while (1)
   {
      scanf("%lld%lld",&n,&k);
      if (n==0 && k==0)
         break;
      work(n,k);
   }
   system("pause");
   return(0);
}
void prepare()
{
   int i,j,k;
   memset(f,0,sizeof(f));
   f[0][0]=1;
   for (i=1;i<=19;i++)
   {
      f[i][0]=1;
      for (j=1;j<200;j++)
      {
         f[i][j]=f[i-1][j];
         for (k=1;k<=9;k++)
         {
            if (j-k<0)
               break;
            f[i][j]+=f[i-1][j-k];
         }
      }
   }
   a[0]=1;
   for (i=1;i<=19;i++)
      a[i]=a[i-1]*10;
}
void work(long long n,long long k)
{
   long long count(long long,long long,int),calc(long long,int);
   int i,p,s;
   long long t,num;
   s=0;
   t=k;
   while (t!=0)
   {
      s+=t%10;
      t/=10;
   }
   printf("%lld ",count(n,k,s));
   i=1;
   num=k;
   while (1)
   {
      t=calc(n,i);
      if (num<=t)
         break;
      num-=t;
      i++;
   }
   p=i;
   num=0;
   while (1)
   {      
      s=0;
      t=num;
      while (t!=0)
      {
         s+=t%10;
         t/=10;
      }
      t=count(n,num,s);
      if (count(n,num,s)==k)
         break;
      num*=10;
      for (i=0;i<=9;i++)
         if (count(n,num+i,p)>=k)
            break;
      num+=i;
      s=0;
      t=num;
      while (t!=0)
      {
         s+=t%10;
         t/=10;
      }
      if (count(n,num,s)==k)
         break;
      num--;
   }
   printf("%lld\n",num);
}
long long count(long long n,long long k,int s)
{
   long long calc(long long,int),min(long long,long long);
   int i,l,len;
   long long ans,t;
   ans=0;
   for (i=1;i<=s-1;i++)
      ans+=calc(n,i);
   if (k==0)
      return(ans);
   t=k;
   l=0;
   while (t!=0)
   {
      l++;
      t/=10;
   }
   t=n;
   len=0;
   while (t!=0)
   {
      len++;
      t/=10;
   }
   t=k*10;
   for (i=l+1;i<=len;i++)
   {      
      ans+=calc(min(n,t-1),s)-f[i-1][s];   
      t*=10;
   }
   t=k;
   for (i=l;i>=1;i--)
   {
      ans+=calc(t,s)-f[i-1][s];
      t/=10;
   }
   return(ans);
}
long long calc(long long x,int k)
{
   int i,j,s;
   long long t,ans;
   if (x==0)
      return(0);
   t=x;
   s=0;
   while (t!=0)
   {
      s+=t%10;
      t/=10;
   }
   if (s==k)
      ans=1;
   else
      ans=0;
   for (j=19;j>=0;j--)
   {
      t=x/a[j];
      x%=a[j];
      for (i=0;i<t;i++)
      {
         if (k-i<0)
            break;
         ans+=f[j][k-i];
      }
      k-=t;
      if (k<0)
         break;
   }
   return(ans);
}
long long min(long long x,long long y)
{
   if (y<0)
      return(x);
   if (x<y)
      return(x);
   else
      return(y);
}
