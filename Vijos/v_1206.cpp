#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int q[70000],d[70000];
int main()
{
   int start,end;
   start=end=0;
   for (int i=1;i<=4;i++)
   {
      for (int j=1;j<=4;j++)
      {
         char ch;
         scanf("%c",&ch);
         start=(start<<1)+ch-'0';
      }
      scanf("%*c");
   }
   scanf("%*c");
   for (int i=1;i<=4;i++)
   {
      for (int j=1;j<=4;j++)
      {
         char ch;
         scanf("%c",&ch);
         end=(end<<1)+ch-'0';
      }
      scanf("%*c");
   }
   int l,r;
   l=r=1,d[start]=1,q[1]=start;
   while (l<=r)
   {
      int t=15;
      bool a[5][5],b[5][5];
      for (int i=1;i<=4;i++)
         for (int j=1;j<=4;j++)
         {
            a[i][j]=q[l]>>t&1;
            t--;
         }
      for (int i=1;i<=4;i++)
         for (int j=1;j<=4;j++)
         {
            if (!a[i][j])
               continue;
            for (int k=0;k<4;k++)
            {
               int x=i+c[k][0],y=j+c[k][1];
               if (!x || x==5 || !y || y==5 || a[x][y])
                  continue;
               int t,p=0;
               memcpy(b,a,sizeof(b));
               t=b[i][j],b[i][j]=b[x][y],b[x][y]=t;
               for (int i=1;i<=4;i++)
                  for (int j=1;j<=4;j++)
                     p=(p<<1)+b[i][j];
               if (d[p])
                  continue;
               q[++r]=p,d[p]=d[q[l]]+1;
            }
         }
      l++;
   }
   printf("%d\n",d[end]-1);
   system("pause");
   return(0);
}
