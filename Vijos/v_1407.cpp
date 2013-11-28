#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,m,a,c[101],v[101],b[101],w[101],buy[8001]={0},z[101];
   scanf("%d%d",&n,&m);
   for (i=1;i<=3;i++)
   {
      scanf("%d",&a);
      scanf("%d%d",&c[a],&v[a]);
   }
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&b[i],&a);
      w[i]=b[i]*c[a];
      b[i]+=v[a]*b[i];
   }
   for (i=1;i<=n;i++)
      for (j=m;j>=b[i];j--)
         if (buy[j]>=0)
            if (buy[j]<buy[j-b[i]]+w[i]) 
               buy[j]=buy[j-b[i]]+w[i];
   printf("%d\n",buy[m]);
   system("pause");
   return(0);
}
