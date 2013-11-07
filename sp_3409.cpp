#include <cstdio>
#include <cstdlib>
const int c[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class date
{
   int y,m,d;
   friend bool operator ==(date,date);
   bool leap()
   {
      if (!(y%400))
         return(true);
      if (!(y%100))
         return(false);
      return(!(y&3));
   }
public:
   date(){}
   date(int y,int m,int d):y(y),m(m),d(d){}
   void next()
   {
      int p=c[m];
      if (m==2 && leap())
         p++;
      d++;
      if (d>p)
         m++,d=1;
      if (m>12)
         y++,m=1;
   }
};
bool operator ==(date a,date b)
{
   return(a.y==b.y && a.m==b.m && a.d==b.d);
}
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int ans1=0,ans2=0,tot=0;
      date now(26,1,1);
      for (int i=1;i<=n;i++)
      {
         int d,m,y,x;
         scanf("%d%d%d%d",&d,&m,&y,&x);
         date t(y,m,d);
         now.next();
         if (t==now)
            ans1++,ans2+=x-tot;
         tot=x,now=t;
      }
      printf("%d %d\n",ans1,ans2);
   }
   system("pause");
   return(0);
}
