#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[1010];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(char *s)
   {
      memset(a,0,sizeof(a));
      a[0]=strlen(s);
      for (int i=1;i<=a[0];i++)
         a[i]=s[a[0]-i]-'0';
   }
   bool empty()
   {
      return(a[0]==1 && !a[1]);
   }
   bool odd()
   {
      return(a[1]&1);
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator -(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=b;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]-x;
      if (c[i]<0)
         c[i]+=10,x=1;
      else
         x=0;
   }
   while (c[0]>1 && !c[c[0]])
      c[0]--;
   return(c);
}
bignum operator /(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=c[0];i;i--)
   {
      int t=a[i]+x*10;
      c[i]=t/b;
      x=t%b;
   }
   while (c[0]>1 && !c[c[0]])
      c[0]--;
   return(c);
}
int ans;
bignum x;
int main()
{
   void calc();
   int t;
   scanf("%d",&t);
   while (t--)
   {
      char s[1010];
      scanf("%s",s);
      bignum a(s);
      ans=0;
      x=a;
      calc();
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void calc()
{
   while (!x.empty())
      if (x.odd())
      {
         ans++;
         x=(x-1)/2;
      }
      else
      {
         ans+=2;
         x=x/2-1;
      }
}
