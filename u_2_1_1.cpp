/*
ID: liuq9011
LANG: C++
TASK: castle
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
char ch;
int m,n,ans,xx,yy,a[51][51][5],f[51][51],s[2600];
int main()
{
   in=fopen("castle.in","r");
   out=fopen("castle.out","w");
   void floodfill(int,int),search(int,int);
   int i,j,x;
   fscanf(in,"%d%d",&m,&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
         fscanf(in,"%d",&x);
         if (x>=8)
         {
            x-=8;
            a[i][j][3]=1;
         }
         if (x>=4)
         {
            x-=4;
            a[i][j][1]=1;
         }
         if (x>=2)
         {
            x-=2;
            a[i][j][4]=1;
         }
         if (x>=1)
         {
            x-=1;
            a[i][j][2]=1;
         }
      }
   memset(f,0,sizeof(f));
   ans=0;
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         if (!f[i][j])
         {
            ans++;
            f[i][j]=ans;
            floodfill(i,j);
         }
   fprintf(out,"%d\n",ans);
   memset(s,0,sizeof(s));
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         s[f[i][j]]++;
   x=0;
   for (i=1;i<=ans;i++)
      if (s[i]>x)
         x=s[i];
   fprintf(out,"%d\n",x);
   ans=0;
   search(n,1);
   fprintf(out,"%d\n",ans);
   fprintf(out,"%d %d %c\n",xx,yy,ch);
   fclose(in),fclose(out);
   return(0);
}
void floodfill(int x,int y)
{
   if (!a[x][y][1] && !f[x][y+1])
   {
      f[x][y+1]=ans;
      floodfill(x,y+1);
   }
   if (!a[x][y][2] && !f[x][y-1])
   {
      f[x][y-1]=ans;
      floodfill(x,y-1);
   }
   if (!a[x][y][3] && !f[x+1][y])
   {
      f[x+1][y]=ans;
      floodfill(x+1,y);
   }
   if (!a[x][y][4] && !f[x-1][y])
   {
      f[x-1][y]=ans;
      floodfill(x-1,y);
   }
}
void search(int x,int y)
{
   if (x-1>0)
      if (f[x][y]!=f[x-1][y] && s[f[x][y]]+s[f[x-1][y]]>ans)
      {
         ans=s[f[x][y]]+s[f[x-1][y]];
         xx=x,yy=y,ch='N';
      }
   if (y+1<=m)
      if (f[x][y]!=f[x][y+1] && s[f[x][y]]+s[f[x][y+1]]>ans)
      {
         ans=s[f[x][y]]+s[f[x][y+1]];
         xx=x,yy=y,ch='E';
      }
   if (x-1>0)
      search(x-1,y);
   else if (y+1<=m)
      search(n,y+1);
}
