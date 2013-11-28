#include <cstdio>
#include <cstdlib>
int b[10001],a[100001];
unsigned short p[100001];
int main()
{
   int n,tot=0;
   scanf("%d%*c",&n);
   for (int i=1;i<=n;i++)
   {
      char ch;
      scanf("%*c%*c%*c%c",&ch);
      if (ch=='H')
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i]=(y<<1)+(b[x]&1);
         p[i]=b[x]>>1;
         b[x]=i;
      }
      else
      {
         int x;
         scanf("%d",&x);
         printf("%d\n",a[b[x]]>>1);
         b[x]=(p[b[x]]<<1)+(a[b[x]]&1);
      }
      scanf("%*c");
   }
   system("pause");
   return(0);
}
