#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[1010];
   friend bignum operator +(bignum,bignum);
public:
   void init(char *s)
   {
      memset(a,0,sizeof(a));
      a[0]=strlen(s);
      for (int i=0;i<a[0];i++)
         a[a[0]-i]=s[i]-'0';
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
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
   while (x!=0)
   {
      c[++c[0]]=x%10;
      x/=10;
   }
   return(c);
}
int main()
{
   int t;
   scanf("%d%*c",&t);
   for (int i=1;i<=t;i++)
   {
      char s[1200];
      bignum a,b,c;
      scanf("%s%*c",s);
      a.init(s);
      scanf("%s%*c",s);
      b.init(s);
      c=a+b;
      printf("Case %d:\n",i);
      a.print();
      printf(" + ");
      b.print();
      printf(" = ");
      c.print();
      printf("\n");
      if (i!=t)
         printf("\n");
   }
   system("pause");
   return(0);
}
