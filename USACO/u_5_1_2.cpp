/*
ID: liuq9011
LANG: C++
TASK: starry
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int c[8][2]={{0,-1},{0,1},{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1}};
struct data
{
   int x1,y1,x2,y2,type;
};
struct data a[501];
int w,h,s,n,l[30],t[30],b[126][126],f[101][101],map[30][101][101];
int main()
{
   in=fopen("starry.in","r");
   out=fopen("starry.out","w");
   void floodfill(int,int),add(int);
   int check(int,int);
   int i,j,k,flag;
   char ch;
   fscanf(in,"%d",&w);
   fscanf(in,"%d",&h);
   memset(b,0,sizeof(b));
   for (i=1;i<=h;i++)
   {
      fscanf(in,"%*c");
      for (j=1;j<=w;j++)
      {
         fscanf(in,"%c",&ch);
         b[i][j]=ch-'0';
      }
   }
   memset(f,0,sizeof(f));
   s=0;
   for (i=1;i<=h;i++)
      for (j=1;j<=w;j++)
      {
         if (!b[i][j])
            continue;
         if (f[i][j]==0)
         {
            s++;
            floodfill(i,j);
         }
      }
   n=0;
   for (i=1;i<=s;i++)
   {
      flag=0;
      for (j=1;j<=n;j++)
         if (check(i,j))
         {
            flag=1;
            k=j;
            break;
         }
      if (!flag)
      {
         n++;
         add(i);
         a[i].type=n;
      }
      else
         a[i].type=k;
   }
   for (i=1;i<=h;i++)
   {
      for (j=1;j<=w;j++)
         if (!b[i][j])
            fprintf(out,"0");
         else
            fprintf(out,"%c",a[f[i][j]].type+'a'-1);
      fprintf(out,"\n");
   }
   fclose(in),fclose(out);
   return(0);
}
void floodfill(int x,int y)
{
   int i;
   f[x][y]=s;
   if (a[s].x1==0 && a[s].y1==0)
   {
      a[s].x1=x;
      a[s].y1=y;
   }
   if (a[s].x2==0 && a[s].y2==0)
   {
      a[s].x2=x;
      a[s].y2=y;
   }
   if (x<a[s].x1)
      a[s].x1=x;
   if (x>a[s].x2)
      a[s].x2=x;
   if (y<a[s].y1)
      a[s].y1=y;
   if (y>a[s].y2)
      a[s].y2=y;
   for (i=0;i<=7;i++)
      if (b[x+c[i][0]][y+c[i][1]] && f[x+c[i][0]][y+c[i][1]]==0)
         floodfill(x+c[i][0],y+c[i][1]);
}
int check(int p,int q)
{
   int i,j,x,y,flag;
   if (a[p].x2-a[p].x1+1==l[q] && a[p].y2-a[p].y1+1==t[q])
   {
      flag=1;
      x=a[p].x1;
      for (i=1;i<=l[q];i++)
      {
         y=a[p].y1;
         for (j=1;j<=t[q];j++)
         {
            if ((f[x][y]==p || map[q][i][j]!=0) && map[q][i][j]!=b[x][y])
            {
               flag=0;
               break;
            }
            y++;
         }
         if (!flag)
            break;
         x++;
      }
      if (flag)
         return(1);
      flag=1;
      x=a[p].x1;
      for (i=1;i<=l[q];i++)
      {
         y=a[p].y2;
         for (j=1;j<=t[q];j++)
         {
            if ((f[x][y]==p || map[q][i][j]!=0) && map[q][i][j]!=b[x][y])
            {
               flag=0;
               break;
            }
            y--;
         }
         if (!flag)
            break;
         x++;
      }
      if (flag)
         return(1);
      flag=1;
      x=a[p].x2;
      for (i=1;i<=l[q];i++)
      {
         y=a[p].y1;
         for (j=1;j<=t[q];j++)
         {
            if ((f[x][y]==p || map[q][i][j]!=0) && map[q][i][j]!=b[x][y])
            {
               flag=0;
               break;
            }
            y++;
         }
         if (!flag)
            break;
         x--;
      }
      if (flag)
         return(1);
      flag=1;
      x=a[p].x2;
      for (i=1;i<=l[q];i++)
      {
         y=a[p].y2;
         for (j=1;j<=t[q];j++)
         {
            if ((f[x][y]==p || map[q][i][j]!=0) && map[q][i][j]!=b[x][y])
            {
               flag=0;
               break;
            }
            y--;
         }
         if (!flag)
            break;
         x--;
      }
      if (flag)
         return(1);
   }
   if (a[p].x2-a[p].x1+1==t[q] && a[p].y2-a[p].y1+1==l[q])
   {
      flag=1;
      x=a[p].x1;
      for (i=1;i<=t[q];i++)
      {
         y=a[p].y1;
         for (j=1;j<=l[q];j++)
         {
            if ((f[x][y]==p || map[q][j][i]!=0) && map[q][j][i]!=b[x][y])
            {
               flag=0;
               break;
            }
            y++;
         }
         if (!flag)
            break;
         x++;
      }
      if (flag)
         return(1);
      flag=1;
      x=a[p].x1;
      for (i=1;i<=t[q];i++)
      {
         y=a[p].y2;
         for (j=1;j<=l[q];j++)
         {
            if ((f[x][y]==p || map[q][j][i]!=0) && map[q][j][i]!=b[x][y])
            {
               flag=0;
               break;
            }
            y--;
         }
         if (!flag)
            break;
         x++;
      }
      if (flag)
         return(1);
      flag=1;
      x=a[p].x2;
      for (i=1;i<=t[q];i++)
      {
         y=a[p].y1;
         for (j=1;j<=l[q];j++)
         {
            if ((f[x][y]==p || map[q][j][i]!=0) && map[q][j][i]!=b[x][y])
            {
               flag=0;
               break;
            }
            y++;
         }
         if (!flag)
            break;
         x--;
      }
      if (flag)
         return(1);
      flag=1;
      x=a[p].x2;
      for (i=1;i<=t[q];i++)
      {
         y=a[p].y2;
         for (j=1;j<=l[q];j++)
         {
            if ((f[x][y]==p || map[q][j][i]!=0) && map[q][j][i]!=b[x][y])
            {
               flag=0;
               break;
            }
            y--;
         }
         if (!flag)
            break;
         x--;
      }
      if (flag)
         return(1);
   }
   return(0);
}
void add(int p)
{
   int i,j,x,y;
   l[n]=a[p].x2-a[p].x1+1;
   t[n]=a[p].y2-a[p].y1+1;
   x=a[p].x1;
   memset(map[n],0,sizeof(map[n]));
   for (i=1;i<=l[n];i++)
   {
      y=a[p].y1;
      for (j=1;j<=t[n];j++)
      {
         if (f[x][y]==p)
            map[n][i][j]=b[x][y];
         y++;
      }
      x++;
   }
}
