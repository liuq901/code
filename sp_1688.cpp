#include <cstdio>
#include <cstdlib>
const int a[8]={0,137,1315,73,136,255,1384,16385};
int main()
{
   void init(),print(int);
   init();
   for (int i=1;i<=7;i++)
   {
      printf("%d=",a[i]);
      print(a[i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
int p[15];
void init()
{
   p[0]=1;
   for (int i=1;i<=14;i++)
      p[i]=p[i-1]*2;
}
void print(int x)
{
   if (x<=2)
   {
      printf("%d",x);
      return;
   }
   int q[20];
   q[0]=0;
   for (int i=14;i>=0;i--)
      if (x>=p[i])
      {
         q[++q[0]]=i;
         x-=p[i];
      }
   for (int i=1;i<=q[0];i++)
   {
      if (i>1)
         printf("+");
      printf("2");
      if (q[i]!=1)
      {
         printf("(");
         print(q[i]);
         printf(")");
      }
   }
}
