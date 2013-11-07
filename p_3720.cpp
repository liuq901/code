#include <cstdio>
#include <cstdlib>
int a[101][10];
int main()
{
   void init();
   init();
   int n,k;
   while (scanf("%d%d",&n,&k)!=EOF)
      printf("%d\n",a[n][k]);
   system("pause");
}
void init()
{
   for (int i=2;i<=100;i++)
   {
      int sum[10]={0};
      bool f[101]={0};
      int t=1;
      while (t!=0 && !f[t])
      {
         f[t]=true;
         t*=10;
         sum[t/i]++;
         t%=i;
      }
      for (int j=0;j<=9;j++)
         a[i][j]=a[i-1][j]+sum[j];
   }
}
