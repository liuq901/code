#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
class line
{
   int a,b,c,d;
   friend bool operator <(line,line);
public:
   line(int _a,int _b,int _c,int _d):a(_a),b(_b),c(_c),d(_d){}
   int num()
   {
      return(d);
   }
};
bool operator <(line a,line b)
{
   if (a.a<b.a)
      return(true);
   if (a.a>b.a)
      return(false);
   if (a.b<b.b)
      return(true);
   if (a.b>b.b)
      return(false);
   if (a.c<b.c)
      return(true);
   if (a.c>b.c)
      return(false);
   return(false);
}
int x[771],y[771],ans[100001][3];
multiset <line> p;
int main()
{
   int gcd(int,int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      int sum=0;
      for (int i=1;i<=n;i++)
      {
         p.clear();
         for (int j=i+1;j<=n;j++)
         {
            int a,b,c;
            a=y[i]-y[j];
            b=x[j]-x[i];
            c=x[i]*y[i]-x[j]*y[i];
            if (a<0)
               a*=-1,b*=-1,c*=-1;
            int t=gcd(gcd(a,abs(b)),abs(c));
            a/=t,b/=t,c/=t;
            if (p.count(line(a,b,c,0)))
            {
               multiset <line>::iterator k,l,r;
               l=p.lower_bound(line(a,b,c,0));
               r=p.upper_bound(line(a,b,c,0));
               for (k=l;k!=r;k++)
               {
                  line p=*k;
                  ans[++sum][0]=i,ans[sum][1]=p.num(),ans[sum][2]=j;
               }
            }
            p.insert(line(a,b,c,j));
         }
      }
      printf("%d\n",sum);
      for (int i=1;i<=sum;i++)
         printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
   }
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
