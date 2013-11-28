#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,i,j,v,p,f[30001]={0};
   scanf("%d%d",&n,&m);
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&v,&p);
      for (j=n-v;j>=1;j--)
         if (f[j+v]<=f[j]+v*p)
            f[j+v]=f[j]+v*p;
   }
   printf("%d\n",f[n]);
   system("pause");
   return(0);
}
