#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int op[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int sum[1000010],c[1000010],d[1000010],a[1010][1010],b[1010][1010],p[1010][1010],pos[1000010][2];
int main()
{
   int calc(int,int,int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int t=0;
      memset(c,0,sizeof(c));
      memset(sum,0,sizeof(sum));
      bool flag=true;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            scanf("%d",&a[i][j]);
            pos[a[i][j]][0]=i,pos[a[i][j]][1]=j;
            b[i][j]=++t;
            p[i][j]=calc(i,j,n);
            d[b[i][j]]=p[i][j];
            if (c[a[i][j]])
               flag=false;
            else
               c[a[i][j]]=p[i][j];
            sum[p[i][j]]++;
         }
      for (int i=1;i<=n;i++)
         p[i][0]=p[i][n+1]=p[0][i]=p[n+1][i]=0;
      for (int i=1;i<=n*n;i++)
         if (c[i]!=d[i])
         {
            flag=false;
            break;
         }
      static int id=0;
      printf("%d. ",++id);
      if (flag)
         for (int t=1;t<=n+1>>1;t++)
         {
            int num=b[t][t],x0=t,y0=t,z0=0,x1=pos[num][0],y1=pos[num][1],z1,tot=1;
            if (x1==t)
               z1=0;
            else if (y1==n-t+1)
               z1=1;
            else if (x1==n-t+1)
               z1=2;
            else
               z1=3;
            while (tot<sum[t])
            {
               tot++;
               while (p[x0+op[z0][0]][y0+op[z0][1]]!=p[t][t])
                  z0=z0+1&3;
               while (p[x1+op[z1][0]][y1+op[z1][1]]!=p[t][t])
                  z1=z1+1&3;
               x0+=op[z0][0],y0+=op[z0][1],x1+=op[z1][0],y1+=op[z1][1];
               if (b[x0][y0]!=a[x1][y1])
               {
                  flag=false;
                  break;
               }
            }
            if (!flag)
               break;
         }
      printf("%s\n",flag?"YES":"NO");
   }
   system("pause");
   return(0);
}
int calc(int x,int y,int n)
{
   return(min(min(x,y),min(n-x+1,n-y+1)));
}
