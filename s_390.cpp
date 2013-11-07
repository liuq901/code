#include <cstdio>
#include <cstdlib>
#include <cstring>
const double max=1000000000000000000ll;
struct data
{
   long long a;
   int b;
};
long long ten[19];
struct data f[19][170][1000];
int k,visit[19][170][1000];
int main()
{
   struct data count(long long,long long);
   long long l,r;
   int i,flag;
   struct data ans;
   scanf("%I64d%I64d%d",&l,&r,&k);
   flag=0;
   ten[0]=1;
   for (i=1;i<=18;i++)
      ten[i]=ten[i-1]*10;
   if (r==max && l<r)
   {
      r--;
      flag=1;
   }
   memset(visit,0,sizeof(0));
   ans=count(l,r);
   if (flag)
   {
      if (ans.b==0)
      {
         ans.a++;
         ans.b=k;
      }
      ans.b--;
   }
   if (ans.b>0)
      ans.a--;
   printf("%I64d\n",ans.a);
   system("pause");
   return(0);
}
struct data count(long long l,long long r)
{
   struct data calc(int,int,int);
   long long l2,r2;
   int i,j,h,sum;
   struct data ans,t;
   l2=l;
   r2=r;
   h=-1;
   sum=0;
   for (i=18;i>=0;i--)
   {
      if (h<0 && l/ten[i]!=r/ten[i])
         h=i;
      sum+=l/ten[i];
      l%=ten[i];
      r%=ten[i];
   }
   if (h<0)
   {
      ans.a=1;
      if (sum>=k)
         ans.b=0;
      else
         ans.b=k-sum;
      return(ans);
   }
   ans.a=0;
   ans.b=0;
   l=l2;
   r=r2;
   t=calc(0,sum,ans.b);
   ans.a+=t.a;
   ans.b=t.b;
   for (i=0;i<h;i++)
   {
      sum-=l%ten[i+1]/ten[i];
      for (j=l%ten[i+1]/ten[i]+1;j<=9;j++)
      {
         t=calc(i,sum+j,ans.b);
         ans.a+=t.a;
         ans.b=t.b;
      }
   }
   sum-=l%ten[h+1]/ten[h];
   for (i=l%ten[h+1]/ten[h]+1;i<r%ten[h+1]/ten[h];i++)
   {
      t=calc(h,sum+i,ans.b);
      ans.a+=t.a;
      ans.b=t.b;
   }
   for (i=h-1;i>=0;i--)
   {
      sum+=r%ten[i+2]/ten[i+1];
      for (j=0;j<r%ten[i+1]/ten[i];j++)
      {
         t=calc(i,sum+j,ans.b);
         ans.a+=t.a;
         ans.b=t.b;
      }
   }
   t=calc(0,sum+r%10,ans.b);
   ans.a+=t.a;
   ans.b=t.b;
   return(ans);
}
struct data calc(int h,int sum,int x)
{
   struct data ans,t;
   int i;
   if (visit[h][sum][x])
      return(f[h][sum][x]);
   if (h==0)
      if (x==0)
      {
         ans.a=1;
         if (sum<k)
            ans.b=k-sum;
         else
            ans.b=0;
      }
      else
      {
         ans.a=0;
         if (x>sum)
            ans.b=x-sum;
         else
            ans.b=0;
      }
   else
   {
      ans.a=0;
      ans.b=x;
      for (i=0;i<=9;i++)
      {
         t=calc(h-1,sum+i,ans.b);
         ans.a+=t.a;
         ans.b=t.b;
      }
   }
   visit[h][sum][x]=1;
   f[h][sum][x]=ans;
   return(ans);
}
