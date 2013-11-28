#include <cstdio>
#include <cstdlib>
int main()
{
   void init(),print(int);
   init();
   int n;
   scanf("%d",&n);
   if (n==1)
      printf("2(0)\n");
   else
   {
      print(n);
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
