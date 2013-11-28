#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Time
{
   int s;
   friend bool operator <(Time,Time);
public:
   Time(int min,int sec):s(min*60+sec){}
   int minute()
   {
      return(s/60);
   }
   int second()
   {
      return(s%60);
   }
   void operator +=(Time a)
   {
      s+=a.s;
   }
   void operator /=(int x)
   {
      s/=x;
   }
};
bool operator <(Time a,Time b)
{
   return(a.s<b.s);
}
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      Time sum(0,0),best(70,0);
      for (int i=1;i<=n;i++)
      {
         int m,s;
         scanf("%d%d",&m,&s);
         Time now(m,s);
         sum+=now;
         best=min(best,now);
      }
      sum/=n;
      static int id=0;
      printf("Track %d:\n",++id);
      printf("Best Lap: %d minute(s) %d second(s).\n",best.minute(),best.second());
      printf("Average: %d minute(s) %d second(s).\n\n",sum.minute(),sum.second());
   }
   system("pause");
   return(0);
}
