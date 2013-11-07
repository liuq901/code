#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[1000001];
int main()
{
   int work(long long);
   int x,y,i,k,t,flag;
   while (scanf("%d%d",&x,&y)!=EOF)
   {
      flag=0;
      if (x>y)
      {
         t=x,x=y,y=t;
         flag=1;
      }
      t=0;
      for (i=x;i<=y;i++)
      {
         k=work(i);
         if (k>t)
            t=k;
      }
      if (flag)
         printf("%d %d %d\n",y,x,t);
      else
         printf("%d %d %d\n",x,y,t);
   }
   system("pause");
   return(0);
}
int work(long long x)
{
   int get(int);
   if (x<=1000000 && f[x])
      return(f[x]);
   int ans;
   if (x==1)
      ans=1;
   else if (x&1)
      ans=work(3*x+1)+1;
   else
      ans=work(x/2)+1;
   if (x<=1000000)
      f[x]=ans;
   return(ans);
}
