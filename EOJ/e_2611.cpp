#include <cstdio>
#include <cstdlib>
class time
{
   int h,m,s;
public:
   time(){}
   time(int h,int m,int s):h(h),m(m),s(s){}
   friend time operator +(time,int);
   friend bool operator <=(time,time);
};
time operator +(time a,int b)
{
   a.m+=b;
   if (a.m>=60)
      a.h++,a.m-=60;
   if (a.h==24)
      a.h=0;
   return(a);
}
bool operator <=(time a,time b)
{
   if (a.h!=b.h)
      return(a.h<b.h);
   if (a.m!=b.m)
      return(a.m<b.m);
   return(a.s<=b.s);
}
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x,y,z;
      scanf("%d:%d:%d",&x,&y,&z);
      time now(x,y,z),limit(8,0,0);
      if (now+15<=limit)
         printf("You are living a healthy life!\n");
      else if (now+10<=limit)
         printf("Hurry up!\n");
      else
         printf("You are late!\n");
   }
   system("pause");
   return(0);
}
