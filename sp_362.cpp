#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p[7]={0,1,2,5,9,8,6};
class bignum
{
   int a[210];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(char *s)
   {
      a[0]=strlen(s);
      for (int i=1;i<=a[0];i++)
         a[i]=s[a[0]-i]-'0';
   }
   bool empty()
   {
      return(a[0]==1 && a[1]==0);
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator /(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=c[0];i>=1;i--)
   {
      c[i]=(a[i]+10*x)/b;
      x=(a[i]+10*x)%b;
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
int operator %(bignum a,int b)
{
   int x=0;
   for (int i=a[0];i>=1;i--)
      x=(a[i]+10*x)%b;
   return(x);
}
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      char s[210];
      scanf("%s",s);
      bignum n(s);
      int a[1000];
      a[0]=0;
      while (!n.empty())
      {
         a[++a[0]]=n%7;
         n=n/7;
      }
      for (int i=1;i<=a[0];i++)
         printf("%d",p[a[i]]);
      printf("\n");
   }
   system("pause");
   return(0);
}
