#include <cstdio>
#include <cstdlib>
int main()
{
   bool check(int);
   int ans=0,a,b;
   scanf("%d%d",&a,&b);
   for (int i=a;i<=b;i++)
      ans+=check(i);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   if (!(x%400))
      return(true);
   if (!(x%100))
      return(false);
   return(!(x%4));
}
