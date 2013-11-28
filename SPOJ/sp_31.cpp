#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=10000;
class bignum
{
   int a[5200];
public:
   bignum(){}
   bignum(char *s)
   {
      int l=strlen(s),now=1,p=1;
      a[0]=(l+3)/4;
      memset(a+1,0,sizeof(int)*a[0]);
      for (int i=l-1;i>=0;i--)
      {
         a[now]+=p*(s[i]-'0');
         p*=10;
         if (p==m)
            now++,p=1;
      }
   }
   void init(int x)
   {
      a[0]=x;
      memset(a+1,0,sizeof(int)*x);
   }
   void print()
   {
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i;i--)
         printf("%04d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator *(bignum a,bignum b)
{
   bignum c;
   c.init(a[0]+b[0]);
   printf("%d\n",c[0]);
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/m;
         c[i+j-1]%=m;
      }
   while (c[0]>1 && !c[c[0]])
      c[0]--;
   return(c);
}
char s[10010],t[10010];
int main()
{
   int test;
   scanf("%d",&test);
   while (test--)
   {
      scanf("%s %s",s,t);
      bignum a=s,b=t,c=a*b;
      c.print();
   }
   system("pause");
   return(0);
}
