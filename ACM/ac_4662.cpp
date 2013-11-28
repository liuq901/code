#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int c[8][2]={{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
const int d[8][8]={{0,1,2,3,4,5,6,7},{2,3,4,5,6,7,0,1},{4,5,6,7,0,1,2,3},{6,7,0,1,2,3,4,5},{4,3,2,1,0,7,6,5},{0,7,6,5,4,3,2,1},{6,5,4,3,2,1,0,7},{2,1,0,7,6,5,4,3}};
int n,m,g[10010][10],p[10010][10],f[110][110];
char ans[10010],a[110][110];
int main()
{
   void floodfill(int,int,int),work(int,int);
   bool first=true;
   while (1)
   {
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            cin>>a[i][j];
      memset(f,0,sizeof(f));
      int t=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (a[i][j]=='1' && !f[i][j])
               floodfill(i,j,++t);
      memset(p,0,sizeof(p));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (!f[i][j])
               continue;
            work(i,j);
         }
      char now='A';
      int num=0;
      for (int i=1;i<=t;i++)
      {
         int pos=0;
         for (int j=1;j<=num;j++)
         {
            bool same=false;
            for (int l=0;l<8;l++)
            {
               bool now=true;
               for (int k=0;k<8;k++)
                  if (p[i][d[l][k]]!=g[j][k])
                  {
                     now=false;
                     break;
                  }
               if (now)
               {
                  same=true;
                  break;
               }
            }
            if (same)
            {
               pos=j;
               break;
            }
         }
         if (!pos)
         {
            num++;
            ans[i]=now++;
            if (now=='Z'+1)
               now='a';
            memcpy(g[num],p[i],sizeof(p[i]));
         }
         else
            ans[i]=pos<=26?pos+'A'-1:pos+'a'-27;
      }
      if (!first)
         printf("\n");
      first=false;
      printf("%d\n",num);
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=m;j++)
            printf("%c",f[i][j]?ans[f[i][j]]:'0');
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
void floodfill(int x,int y,int num)
{
   f[x][y]=num;
   for (int i=0;i<8;i++)
   {
      int x0=x+c[i][0],y0=y+c[i][1];
      if (x0>0 && x0<=n && y0>0 && y0<=m && !f[x0][y0] && a[x0][y0]=='1')
         floodfill(x0,y0,num);
   }
}
void work(int x0,int y0)
{
   int num=f[x0][y0];
   for (int i=0;i<8;i++)
   {
      int x=x0,y=y0;
      while (1)
      {
         if (x>0 && x<=n && y>0 && y<=m && f[x][y]==num)
            p[num][i]++;
         else
            break;
         x+=c[i][0],y+=c[i][1];
      }
   }
}
