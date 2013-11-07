#include <cstdio>
#include <cstdlib>
bool f[10000];
int main()
{
   bool check(int,int,int);
   int ans=0;
   for (int i=1;i<10000;i++)
      for (int j=i+1;j<=10000;j++)
         if (check(i,j,i*j) && !f[i*j])
         {
            ans+=i*j;
            f[i*j]=true;
         }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int a,int b,int c)
{
   bool f[10]={0};
   f[0]=true;
   while (a)
   {
      int x=a%10;
      if (f[x])
         return(false);
      f[x]=true;
      a/=10;
   }
   while (b)
   {
      int x=b%10;
      if (f[x])
         return(false);
      f[x]=true;
      b/=10;
   }
   while (c)
   {
      int x=c%10;
      if (f[x])
         return(false);
      f[x]=true;
      c/=10;
   }
   for (int i=0;i<10;i++)
      if (!f[i])
         return(false);
   return(true);
}
