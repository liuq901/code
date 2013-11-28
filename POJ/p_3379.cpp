#include <cstdio>
#include <cstdlib>
char s[10010];
int main()
{
   int n,k,m;
   scanf("%d%d%d%s",&n,&k,&m,s);
   int t=n+m,p=0,sum=0;
   while (1)
   {
      if (!p)
         sum++;
      int x=(t-p-1)/(k+1)+1;
      if (t-n<=x)
      {
         p=(p+k*(t-n))%n;
         break;
      }
      t-=x;
      p=(p+k*x)%t;
   }
   printf("%c\n",(s[p]-'A'+sum)%26+'A');
   system("pause");
   return(0);
}
