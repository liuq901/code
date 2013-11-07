#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int main()
{
   char ch;
   int n,m,s,i,j,k,t,x,y;
   long long ans,p,tmp;
   int map[20][20];
   long long a[100][100];
   scanf("%d%d%*c",&n,&m);
   s=0;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=m;j++)
      {
         scanf("%c",&ch);
         if (ch=='.')
         {
            s++;
            map[i][j]=s;
         }
         else
            map[i][j]=0;
      }
      scanf("%*c");
   }
   for (i=1;i<=n;i++)
      map[i][0]=map[i][m+1]=0;
   for (i=1;i<=m;i++)
      map[0][i]=map[n+1][i]=0;
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
         if (!map[i][j])
            continue;
         t=map[i][j];
         for (k=0;k<4;k++)
         {
            x=i+c[k][0];
            y=j+c[k][1];
            if (map[x][y])
            {
               a[t][t]++;
               a[t][map[x][y]]=-1;
            }
         }
      }
   if (s==0)
      printf("0\n");
   else if (s==1)
      printf("1\n");
   else
   {
      s--;
      ans=1;
      p=1000000000;
      for (i=1;i<=s;i++)
      {
         for (j=i+1;j<=s;j++)
            while (a[j][i]!=0)
            {
               tmp=a[i][i]/a[j][i];
               for (k=1;k<=s;k++)
               {
                  a[i][k]-=a[j][k]*tmp;
                  a[i][k]%=p;
               }
               for (k=1;k<=s;k++)
                  tmp=a[i][k],a[i][k]=a[j][k],a[j][k]=tmp;
               ans*=-1;
            }
         ans*=a[i][i];
         ans%=p;
      }
      while (ans<0)
         ans+=p;
      printf("%I64d\n",ans);
   }
   system("pause");
   return(0);
}
