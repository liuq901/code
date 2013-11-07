#include <cstdio>
#include <cstdlib>
int main()
{
   int n,ans;
   scanf("%d",&n);
   ans=n/3*2;
   if (n%3==2)
      ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
