#include <cstdio>
#include <cstdlib>
int n,c,ans,sum,cost,a[3][60],b[3][60];
int main()
{
   void search(int);
   while (scanf("%d%d",&n,&c)==2)
   {
      for (int i=1;i<=n;i++)
         for (int j=0;j<3;j++)
            scanf("%d%d",&a[j][i],&b[j][i]);
      sum=cost=0;
      ans=1<<30;
      search(1);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void search(int dep)
{
   if (cost>=c || sum>=ans)
      return;
   if (dep==n+1)
   {
      ans=sum;
      return;
   }
   for (int i=0;i<3;i++)
   {
      sum+=a[i][dep];
      cost+=b[i][dep];
      search(dep+1);
      sum-=a[i][dep];
      cost-=b[i][dep];
   }
}
