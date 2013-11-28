#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b,i,j,t,m;
   int w[1001]={0};
   scanf("%d%d",&t,&m);
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&a,&b);
      for (j=t-a;j>=0;j--)
         if (w[j]+b>w[j+a])
            w[j+a]=w[j]+b;
   }
   printf("%d\n",w[t]);
   system("pause");
   return(0);
}
