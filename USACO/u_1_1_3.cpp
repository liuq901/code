/*
ID: liuq9011
LANG: C++
TASK: friday
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("friday.in","r");
   out=fopen("friday.out","w");
   int n,y,m,d,i,flag,t;
   int a[8];
   fscanf(in,"%d",&n);
   y=1900;
   m=1;
   d=i=0;
   memset(a,0,sizeof(a));
   t=0;
   while (1)
   {
      i++;
      d++;
      t++;
      if (i>7)
         i=1;
      if (d==13)
         a[i]++;
      if (d>31 && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10))
      {
         d=1;
         m++;
      }
      if (d>31 && m==12)
      {
         d=m=1;
         y++;
      }
      if (d>30 && (m==4 || m==6 || m==9 || m==11))
      {
         d=1;
         m++;
      }
      if (d>28 && m==2)
      {
         flag=0;
         if (y%4==0)
            flag=1;
         if (y%100==0)
            flag=0;
         if (y%400==0)
            flag=1;
         if (flag && d>29)
         {
            d=1;
            m=3;
         }
         if (!flag)
         {
            d=1;
            m=3;
         }
      }
      if (y==1900+n-1 && m==12 && d==31)
         break;
   }
   fprintf(out,"%d %d %d %d %d %d %d\n",a[6],a[7],a[1],a[2],a[3],a[4],a[5]);
   fclose(in),fclose(out);
   return(0);
}
