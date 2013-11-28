#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[510];
public:
   void init(char *s)
   {
      memset(a,0,sizeof(a));
      int l=strlen(s);
      a[0]=l;
      for (int i=1;i<=l;i++)
         a[i]=s[l-i]-'0';
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
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
   while (x!=0)
   {
      c[++c[0]]=x%10;
      x/=10;
   }
   return(c);
}
int main()
{
   char s[510],t[510];
   while (scanf("%s%s",&s,&t)!=EOF)
   {
      bignum a,b,c;
      a.init(s);
      b.init(t);
      c=a+b;
      c.print();
   }
   system("pause");
   return(0);
}
