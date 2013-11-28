#include <cstdio>
#include <cstdlib>
#include <cstring>
int len,m,a[31],f[10],g[10][10];
int main()
{
   void init(),ma(),show();
   init();
   ma();
   show();
   system("pause");
   return(0);
}
void init()
{
   int i;
   char st[260];
   scanf("%s%d",st,&m);
   len=0;
   i=0;
   while (st[i]>='0' && st[i]<='9')
   {
      len++;
      a[len]=st[i]-'0';
      i++;
   }
}
void ma()
{
   int i,j,k;
   memset(g,0,sizeof(g));
   for (k=1;k<=m;k++)
   {
      scanf("%d%d",&i,&j);
      g[i][j]=1;
   }
   for (k=0;k<=9;k++)
      for (i=0;i<=9;i++)
         for (j=0;j<=9;j++)
            g[i][j]=g[i][j] || (g[i][k] && g[k][j]);
   memset(f,0,sizeof(f));
   for (i=0;i<=9;i++)
      g[i][i]=1;
   for (i=0;i<=9;i++)
      for (j=0;j<=9;j++)
         f[i]+=g[i][j];
}
void show()
{
   int i,j,k,g;
   int ans[31];
   memset(ans,0,sizeof(ans));
   ans[1]=1;
   for (k=1;k<=len;k++)
   {
      g=0;
      for (i=1;i<=30;i++)
      {
         ans[i]=ans[i]*f[a[k]]+g;
         g=ans[i]/10;
         ans[i]%=10;
      }
   }
   j=30;
   while (ans[j]==0)
      j--;
   for (i=j;i>=1;i--)
      printf("%d",ans[i]);
   printf("\n");
}
