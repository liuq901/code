#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[60];
public:
   bignum()
   {
      a[0]=0;
      memset(a,0,sizeof(a));
   }
   bignum(char *s)
   {
      memset(a,0,sizeof(a));
      a[0]=strlen(s);
      for (int i=0;i<a[0];i++)
         a[a[0]-i]=s[i]-'0';
   }
   void print()
   {
      for (int i=0;i<10;i++)
         printf("%d",a[a[0]-i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
   int operator [](int x) const
   {
      return(a[x]);
   }
};
bignum operator +(const bignum &a,const bignum &b)
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
char s[60];
int main()
{
   bignum ans;
   for (int i=1;i<=100;i++)
   {
      scanf("%s",s);
      ans=ans+s;
   }
   ans.print();
   system("pause");
   return(0);
}
