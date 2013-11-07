#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,i,ll,rl,ls,rs;
   int a[21][21],f[21][21][21];
   memset(f,0,sizeof(f));
   f[0][0][0]=f[1][1][1]=1;
   for (i=1;i<=19;i++)
      for (ls=0;ls<=20;ls++)
         for (ll=0;ll<=ls;ll++)
            for (rs=0;rs<=20-ls-1;rs++)
               for (rl=0;rl<=rs;rl++)
               {
                  f[i+1][ls+rs+1][ll+rl]+=f[i][ls][ll]*f[i][rs][rl];
                  f[i+1][ls+rs+1][ll+rl]+=f[i-1][ls][ll]*f[i][rs][rl];
                  f[i+1][ls+rs+1][ll+rl]+=f[i][ls][ll]*f[i-1][rs][rl];
               }
   for (ls=1;ls<=20;ls++)
      for (ll=1;ll<=20;ll++)
      {
         a[ls][ll]=0;
         for (i=0;i<=20;i++)
            a[ls][ll]+=f[i][ls][ll];
      }
   while (scanf("%d%d",&n,&m)!=EOF)
      printf("%d\n",a[n][m]);
   system("pause");
   return(0);
}
