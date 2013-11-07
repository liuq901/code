#include <cstdio>
#include <cstdlib>
int b[61],s[61],f[101][61][61];
int main()
{
   void init(int);
   int n,m,map[101];
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=n;i++)
   {
      map[i]=0;
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         map[i]=(map[i]<<1)+(ch=='H');
      }
      scanf("%*c");
   }
   init(m);
   if (n==1)
   {
      int ans=0;
      for (int i=1;i<=b[0];i++)
      {
         if (b[i]&map[1])
            continue;
         if (s[i]>ans)
            ans=s[i];
      }
      printf("%d\n",ans);
   }
   else
   {
      for (int i=1;i<=b[0];i++)
      {
         if (b[i]&map[1])
            continue;
         for (int j=1;j<=b[0];j++)
         {
            if (b[j]&map[2] || b[i]&b[j])
               continue;
            f[2][i][j]=s[i]+s[j];
         }
      }
      for (int i=3;i<=n;i++)
         for (int j=1;j<=b[0];j++)
         {
            if (b[j]&map[i])
               continue;
            for (int k=1;k<=b[0];k++)
            {
               if (b[j]&b[k])
                  continue;
               for (int l=1;l<=b[0];l++)
               {
                  if (b[l]&b[j] || b[l]&b[k])
                     continue;
                  if (f[i-1][l][k]+s[j]>f[i][k][j])
                     f[i][k][j]=f[i-1][l][k]+s[j];
               }
            }
         }
      int ans=0;
      for (int i=1;i<=b[0];i++)
         for (int j=1;j<=b[0];j++)
            if (f[n][i][j]>ans)
               ans=f[n][i][j];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void init(int m)
{
   int tot=1<<m;
   for (int i=0;i<tot;i++)
   {
      int x=i,p[11];
      bool flag=true;
      for (int j=1;j<=m;j++)
      {
         p[j]=x&1;
         x>>=1;
         if (p[j] && (j>2 && p[j-2] || j>1 && p[j-1]))
         {
            flag=false;
            break;
         }
      }
      if (flag)
      {
         b[0]++;
         for (int j=1;j<=m;j++)
         {
            s[b[0]]+=p[j];
            b[b[0]]=(b[b[0]]<<1)+p[j];
         }
      }
   }
}
