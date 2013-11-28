#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,n,m,x,y,p,q;
   int a[101];
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&p,&q);
      for (j=1;j<=n;j++)
      {
         scanf("%d%d",&x,&y);
         if (x>y && p>q)
            a[j]+=2;
         else if (x==y && p==q)
            a[j]+=2;
         else if (x<y && p<q)
            a[j]+=2;
         if (p-q==x-y)
            a[j]+=3;
         if (p==x)
            a[j]++;
         if (q==y)
            a[j]++;
      }
   }
   for (i=1;i<=n-1;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
