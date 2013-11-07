#include <cstdio>
#include <cstdlib>
char s[10000];
int main()
{
   double ans=0,a,b;
   while (scanf("%s%lf%lf",s,&a,&b)==3)
      ans+=a*b;
   printf("%.1f\n",ans);
   system("pause");
   return(0);
}
