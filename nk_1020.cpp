#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
class bignum
{
   int a[100];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      while (x)
      {
         a[++a[0]]=x%10;
         x/=10;
      }
      if (!a[0])
         a[0]=1;
   }
   bignum(char *s)
   {
      memset(a,0,sizeof(a));
      a[0]=strlen(s);
      for (int i=1;i<=a[0];i++)
         a[i]=s[a[0]-i]-'0';
   }
   void print()
   {
      for (int i=a[0];i;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0]>b[0]?a[0]:b[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   if (x)
      c[++c[0]]=x;
   return(c);
}
bool operator ==(bignum &a,bignum &b)
{
   for (int i=0;i<=a[0];i++)
      if (a[i]!=b[i])
         return(false);
   return(true);
}
char s[1000],t[1000];
queue <pair <bignum,int> > q;
int main()
{
   scanf("%s%s",s,t);
   bignum a(s),b(t);
   q.push(make_pair(a,0));
   int ans=-1;
   while (!q.empty())
   {
      bignum &now=q.front().first;
      int time=q.front().second;
      if (now==b)
      {
         ans=time;
         break;
      }
      if (time==6)
         break;
      q.push(make_pair(now+1985429,time+1));
      q.push(make_pair(now+2006,time+1));
      q.push(make_pair(now+now,time+1));
      q.pop();
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
