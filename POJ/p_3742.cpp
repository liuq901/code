#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int m=100000000;
class bignum
{
   int a[50];
public:
   bool sign;
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=1,sign=true;
   }
   bignum(int x)
   {
      sign=x>=0;
      x=abs(x);
      memset(a,0,sizeof(a));
      while (x)
      {
         a[++a[0]]=x%m;
         x/=m;
      }
      a[0]=max(a[0],1);
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
   void print()
   {
      if (!sign)
         printf("-");
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i;i--)
         printf("%08d",a[i]);
   }
};
bool operator <(bignum &a,bignum &b)
{
   if (a[0]<b[0])
      return(true);
   if (a[0]>b[0])
      return(false);
   for (int i=a[0];i;i--)
   {
      if (a[i]<b[i])
         return(true);
      if (a[i]>b[i])
         return(false);
   }
   return(false);
}
bignum operator +(bignum a,bignum b)
{
   bignum operator -(bignum,bignum);
   bignum c;
   if (!a.sign && b.sign)
   {
      a.sign=true;
      return(b-a);
   }
   if (a.sign && !b.sign)
   {
      b.sign=true;
      return(a-b);
   }
   c.sign=a.sign;
   c[0]=max(a[0],b[0]);
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/m;
      c[i]%=m;
   }
   if (x)
      c[++c[0]]=x;
   if (c[0]==1 && !c[1])
      c.sign=true;
   return(c);
}
bignum operator -(bignum a,bignum b)
{
   if (a.sign && !b.sign)
   {
      b.sign=true;
      return(a+b);
   }
   if (!a.sign && b.sign)
   {
      b.sign=false;
      return(a+b);
   }
   if (!a.sign && !b.sign)
   {
      a.sign=b.sign=true;
      return(b-a);
   }
   bignum c;
   if (a<b)
   {
      c.sign=false;
      swap(a,b);
   }
   c[0]=a[0];
   for (int i=1;i<=c[0];i++)
   {
      c[i]+=a[i]-b[i];
      if (c[i]<0)
         c[i+1]--,c[i]+=m;
   }
   while (c[0]>1 && !c[c[0]])
      c[0]--;
   if (c[0]==1 && !c[1])
      c.sign=true;
   return(c);
}
bignum operator *(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   c.sign=a.sign;
   if (b<0)
      c.sign=!c.sign;
   b=abs(b);
   int x=0;
   for (int i=1;i<=a[0];i++)
   {
      ll now=ll(a[i])*b+x;
      c[i]=now%m;
      x=now/m;
   }
   if (x)
      c[++c[0]]=x;
   if (c[0]==1 && !c[1])
      c.sign=true;
   return(c);
}
bignum operator /(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=c[0];i;i--)
   {
      ll now=ll(x)*m+a[i];
      c[i]=now/b;
      x=now%b;
   }
   c.sign=a.sign;
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   if (c[0]==1 && !c[0])
      c.sign=true;
   return(c);
}
int a[210];
bignum tt[210];
bignum b[210],d[210],c[210][210];
int main()
{
   void multi(int,int),count(int,int);
   int n,t;
   while (scanf("%d%d",&n,&t)==2)
   {
      for (int i=0;i<=n;i++)
         scanf("%d",&a[i]);
      d[0]=1;
      for (int i=1;i<=n;i++)
         d[i]=d[i-1]*(-t);
      for (int i=n;i>=0;i--)
      {
         b[i]=a[i];
         for (int j=n;j>i;j--)
         {
            int p=j-i;
            bignum tmp=b[j];
            int now=1;
            for (int k=1;k<=p;k++)
            {
               now*=-t;
               if (abs(now)>10000000)
               {
                  tmp=tmp*now;
                  now=1;
               }
            }
            tmp=tmp*now;
            p=min(p,j-p);
            now=1;
            for (int k=1;k<=p;k++)
            {
               now*=j-k+1;
               if (now>1000000)
               {
                  tmp=tmp*now;
                  now=1;
               }
            }
            tmp=tmp*now;
            now=1;
            for (int k=1;k<=p;k++)
            {
               now*=k;
               if (now>1000000)
               {
                  tmp=tmp/now;
                  now=1;
               }
            }
            tmp=tmp/now;
            b[i]=b[i]-tmp;
         }
      }
      for (int i=0;i<=n;i++)
      {
         b[i].print();
         printf("%c",i==n?'\n':' ');
      }
   }
   system("pause");
   return(0);
}
bool vis[210][210];
void count(int x,int y)
{
   if (vis[x][y])
      return;
   vis[x][y]=true;
   if (x==y || !y)
      c[x][y]=1;
   else
   {
      count(x-1,y-1),count(x-1,y);
      c[x][y]=c[x-1][y-1]+c[x-1][y];
   }
}
