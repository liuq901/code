#include <cstdio>
#include <cstdlib>
bool f[110][110][110];
int main()
{
   void init();
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      int ans=0;
      for (int i=0;i<=n;i++)
         for (int j=0;j<=n;j++)
            for (int k=0;k<=n;k++)
               ans+=!f[i][j][k];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void init()
{
   f[0][0][0]=true;
   for (int i=0;i<=100;i++)
      for (int j=0;j<=100;j++)
         for (int k=0;k<=100;k++)
         {
            if (f[i][j][k])
               continue;
            int p=1;
            while (1)
            {
               p++;
               int x=i*p,y=j*p,z=k*p;
               if (x>100 || y>100 || z>100)
                  break;
               f[x][y][z]=true;
            }
         }
}
