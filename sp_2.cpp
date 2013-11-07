#include <cstdio>
#include <cstdlib>
int main()
{
   void init();
   bool check(int);
   init();
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      for (int i=x;i<=y;i++)
         if (check(i))
            printf("%d\n",i);
      printf("\n");
   }
   system("pause");
   return(0);
}
bool f[100001];
int a[100001];
void init()
{
   f[1]=true;
   for (int i=2;i<=100001;i++)
   {
      if (f[i])
         continue;
      for (int j=i;j<=100001/i;j++)
         f[i*j]=true;
      a[++a[0]]=i;
   }
}
bool check(int x)
{
   if (x<=100001)
      return(!f[x]);
   for (int i=1;i<=a[0];i++)
   {
      if (!(x%a[i]))
         return(false);
      if (a[i]*a[i]>x)
         return(true);
   }
}
