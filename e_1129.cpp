#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll d[30],c[30][30];
int main()
{
   void init();
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      printf("%I64d\n",c[n][m]*d[m]);
   }
   system("pause");
   return(0);
}
void init()
{
   d[1]=0,d[2]=1;
   for (int i=3;i<=20;i++)
      d[i]=(i-1)*(d[i-2]+d[i-1]);
   for (int i=1;i<=20;i++)
   {
      c[i][0]=c[i][i]=1;
      for (int j=1;j<i;j++)
         c[i][j]=c[i-1][j-1]+c[i-1][j];
   }
}
