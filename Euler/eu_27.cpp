#include <cstdio>
#include <cstdlib>
bool f[1000010];
int main()
{
   void init();
   int calc(int,int);
   init();
   int ans=-1,now;
   for (int i=-1000;i<=1000;i++)
      for (int j=-1000;j<=1000;j++)
      {
         int t=calc(i,j);
         if (t>ans)
            ans=t,now=i*j;
      }
   printf("%d\n",now);
   system("pause");
   return(0);
}
void init()
{
   f[0]=f[1]=true;
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
}
int calc(int a,int b)
{
   for (int n=0;;n++)
   {
      int now=n*n+a*n+b;
      if (now<0)
         return(0);
      if (f[now])
         return(n);
   }
}
