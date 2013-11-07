#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
struct Time
{
   int m,s,x;
   Time(){}
   Time(int m,int s,int x):m(m),s(s),x(x){}
};
Time operator +(Time a,int b)
{
   Time c(a);
   c.s+=b;
   c.m+=c.s/60;
   c.s%=60;
   return(c);
}
bool operator <(Time a,Time b)
{
   if (a.m!=b.m)
      return(a.m<b.m);
   if (a.s!=b.s)
      return(a.s<b.s);
   return(a.x<b.x);
}
char S[110];
bool f[110];
string p[110],ans[110];
Time real[110],final[110];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int m,s,x;
      scanf("%s%d:%d.%d",S,&m,&s,&x);
      p[i]=S;
      real[i]=Time(m,s,x),final[i]=real[i]+(i-1)*30;
   }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         if (real[j]<real[i] && final[j]<final[i])
         {
            f[i]=true;
            break;
         }
   int t=0;
   for (int i=1;i<=n;i++)
      if (!f[i])
         ans[++t]=p[i];
   sort(ans+1,ans+t+1);
   printf("%d\n",t);
   for (int i=1;i<=t;i++)
      printf("%s\n",ans[i].c_str());
   system("pause");
   return(0);
}
