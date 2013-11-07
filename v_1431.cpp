#include <cstdio>
#include <cstdlib>
int main()
{
   int m,s,t,ma,ta,tt,ss,i;
   scanf("%d%d%d",&m,&s,&t);
   ss=tt=0;
   ta=m/10;
   ma=m%10;
   if (ta>=t)
      while (s>ss && tt<t)
      {
         ss+=60;
         tt++;
      }
   else
   {
      ss+=60*ta;
      tt+=ta;
   }
   while (s-ss>0 && t-tt>0)
   {
      if (s-ss<=17)
      {
         ss+=17;
         tt++;
         continue;
      }
      if (s-ss>17 && s-ss<=34 && ma<6)
      {
         ss+=17;
         tt++;
         continue;
      }
      if (s-ss>34 && s-ss<=51 && ma<2)
      {
         ss+=17;
         tt++;
         continue;
      }
      if (s-ss>51 && s-ss<=68)
      {
         ss+=17;
         tt++;
         continue;
      }
      if ((t-tt<7 && ma<2) || (t-tt<3 && ma>1 && ma<=5) || t-tt<=1)
         while (1)
         {
            ss+=17;
            tt++;
            if (s-ss<=0 || t-tt<=0)
               break;
         }
      else
      {
         while (1)
         {
            ta=(ma+4)/10;
            tt++;
            ma=(ma+4)%10;
            if (ta==1)
               break;
         }
         ss+=60;
         tt++;
      }
   }
   if (s-ss<=0)
   {
      printf("Yes\n");
      printf("%d\n",tt);
   }
   else
   {
      printf("No\n");
      printf("%d\n",ss);
   }
   system("pause");
   return(0);
}
