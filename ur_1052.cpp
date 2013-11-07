#include <cstdio>
#include <cstdlib>
int main()
{
   int ans,n,i,j,k,s,x1,x2,y1,y2;
   int x[201],y[201];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&x[i],&y[i]);
   ans=0;
   for (i=1;i<=n;i++)
      for (j=i+1;j<=n;j++)
      {
         s=2;
         x1=x[j]-x[i];
         y1=y[j]-y[i];
         for (k=j+1;k<=n;k++)
         {
            x2=x[k]-x[i];
            y2=y[k]-y[i];
            if (x1*y2-x2*y1==0)
               s++;
         }
         if (s>ans)
            ans=s;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
