#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const int q=32767;
char s[500010];
int main()
{
   void work();
   int t,i;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int i,l,t,p,x,y;
   scanf("%s",s);
   l=strlen(s);
   if (l==1 && s[0]=='1')
   {
      printf("1\n");
      return;
   }
   if (l==1 && s[0]=='0')
   {
      printf("0\n");
      return;
   }
   t=1;
   while (1)
   {
      if (t*log10((double)t)>l)
      {
         t--;
         break;
      }
      t++;
   }
   x=0;
   for (i=0;i<l;i++)
      x=(x*10+s[i]-'0')%q;
   y=1;
   p=t;
   t%=q;
   for (i=1;i<=p;i++)
      y=y*t%q;
   if (x==y)
      printf("%d\n",p);
   else
      printf("-1\n");
}
