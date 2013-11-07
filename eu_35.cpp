#include <cstdio>
#include <cstdlib>
#include <cmath>
bool f[1000010];
int main()
{
   void init();
   bool check(int);
   init();
   int ans=0;
   for (int i=1;i<=1000000;i++)
      ans+=check(i);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void init()
{
   for (int i=2;i*i<=1000000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
   f[1]=true;
}
bool check(int x)
{
   int t=x,p=0,y=1;
   while (t)
   {
      t/=10;
      p++;
   }
   for (int i=1;i<p;i++)
      y*=10;
   for (int i=1;i<=p;i++)
   {
      x=x%y*10+x/y;
      if (f[x])
         return(false);
   }
   return(true);
}
