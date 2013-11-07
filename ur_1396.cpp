#include <cstdio>
#include <cstdlib>
typedef long long int64;
int64 n;
int main()
{
   void init();
   int64 get(int,int64,int64),solve(int,int64,int64,int64,int64),max(int64,int64);
   init();
   while (1)
   {
      int64 tmp;
      scanf("%I64d",&tmp);
      if (!tmp)
         break;
      n=tmp;
      int64 left,right;
      int t;
      left=1;
      t=0;
      while (left*2<=n)
      {
         left=left*2;
         t++;
      }
      right=left*2;
      int64 ans;
      ans=max(get(t,1,1),solve(t,left,right,1,1));
      printf("%I64d\n",ans);
   }
   system("pause");
   return(0);
}
int64 f[70][2];
void init()
{
   f[1][0]=f[2][1]=1;
   f[1][1]=f[2][0]=0;
   for (int i=3;i<=65;i++)
   {
      f[i][0]=f[i-2][0]+f[i-1][0];
      f[i][1]=f[i-2][1]+f[i-1][1];
   }
}
int64 solve(int t,int64 left,int64 right,int64 left_value,int64 right_value)
{
   int64 get(int,int64,int64),max(int64,int64);
   int64 mid,mid_value;
   if (t<0)
      return(0);
   mid=(left+right)/2;
   mid_value=left_value+right_value;
   if (mid<=n+1)
   {
      int64 x;
      if (t==1)
         x=left_value;
      else
         x=get(t,left_value,mid_value);
      if (mid<=n)
         x=max(x,solve(t-1,mid,right,mid_value,right_value));
      return(x);
   }
   return(solve(t-1,left,mid,left_value,mid_value));
}
int64 get(int t,int64 x,int64 y)
{
   if (x<=y)
      return(f[t+1][0]*x+f[t+1][1]*y);
   else
      return(f[t+1][0]*y+f[t+1][1]*x);
}
int64 max(int64 x,int64 y)
{
   return(x<=y?y:x);
}
