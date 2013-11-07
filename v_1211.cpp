#include <cstdio>
#include <cstdlib>
const int a[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int main()
{
   int work(int);
   int y,m,d,i;
   scanf("%d%d%d",&y,&m,&d);
   for (i=1;i<=10000;i++)
   {
      d++;
      if (m!=2 && d>a[m])
      {
         m++;
         d=1;
      }
      if (m==2 && work(y) && d>29)
      {
         m++;
         d=1;
      }
      if (m==2 && !work(y) && d>28)
      {
         m++;
         d=1;
      }
      if (m>12)
      {
         y++;
         m=1;
      }
   }
   printf("%d-%d-%d\n",y,m,d);
   system("pause");
   return(0);
}
int work(int y)
{
   if (y%4==0 && y%100!=0)
      return(1);
   if (y%400==0)
      return(1);
   return(0);
}
