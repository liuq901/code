#include <cstdio>
#include <cstdlib>
bool f[1000010];
int main()
{
   bool check(int);
   f[1]=true;
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
   int sum=0,ans=0;
   for (int i=11;i;i++)
   {
      if (f[i])
         continue;
      if (check(i))
         ans+=i,sum++;
      if (sum==11)
         break;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   int y=0,t=x,p=1;
   while (x)
   {
      if (f[x])
         return(false);
      x/=10;
      p*=10;
   }
   p/=10;
   while (t)
   {
      if (f[t])
         return(false);
      t%=p;
      p/=10;
   }
   return(true);
}
