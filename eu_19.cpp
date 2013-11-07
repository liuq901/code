#include <cstdio>
#include <cstdlib>
int main()
{
   int zeller(int,int,int);
   int ans=0;
   for (int i=1901;i<=2000;i++)
      for (int j=1;j<=12;j++)
      {
         int p=zeller(i,j,1);
         ans+=!p;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int zeller(int y,int m,int d)
{
   if (m<=2)
      y--,m+=12;
   int c=y/100;
   y%=100;
   int w=((c>>2)-(c<<1)+y+(y>>2)+(13*(m+1)/5)+d-1)%7;
   if (w<0)
      w+=7;
   return(w);
}
