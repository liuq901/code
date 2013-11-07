#include <cstdio>
#include <cstdlib>
#include <cstring>
const int mod=5281;
int n,one[60][60],ans[60][60];
int main()
{
   void calc(int);
   int m;
   while (scanf("%d%d",&n,&m)==2)
   {
      memset(one,0,sizeof(one));
      while (1)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (!x && !y && !z)
            break;
         one[x][y]+=z;
      }
      calc(m);
      int T;
      scanf("%d",&T);
      while (T--)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         printf("%d\n",ans[x][y]);
      }
   }
   system("pause");
   return(0);
}
void calc(int x)
{
   void multi(int [][60],int[][60]);
   if (x==1)
   {
      memcpy(ans,one,sizeof(one));
      return;
   }
   calc(x>>1);
   multi(ans,ans);
   if (x&1)
      multi(ans,one);
}
void multi(int a[][60],int b[][60])
{
   int c[60][60]={0};
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         for (int k=1;k<=n;k++)
            c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
   memcpy(ans,c,sizeof(c));
}
