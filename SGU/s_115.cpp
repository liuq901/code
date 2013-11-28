#include <cstdio>
#include <cstdlib>
const int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
   int n,m,c,y,ans;
   scanf("%d%d",&n,&m);
   if (m<1 || m>12)
      printf("Impossible\n");
   else if (n<1 || n>a[m])
      printf("Impossible\n");
   else
   {
      c=20;
      y=1;
      if (m<3)
      {
         m+=12;
         y=0;
      }
      ans=y+y/4+c/4-2*c+26*(m+1)/10+n-1;
      while (ans<0)
         ans+=7;
      ans%=7;
      if (ans==0)
         ans=7;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
