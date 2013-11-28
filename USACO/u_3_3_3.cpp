/*
ID: liuq9011
LANG: C++
TASK: camelot
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
FILE *in,*out;
const int c[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
const int d[9][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1},{0,0}};
int ans,m,n,kx,ky,s,a[10000][2],f[27][31][27][31];
int main()
{
   in=fopen("camelot.in","r");
   out=fopen("camelot.out","w");
   void search(int,int),work(int,int);
   char ch;
   int i,j,x;
   fscanf(in,"%d%d%*c",&n,&m);
   memset(a,0,sizeof(a));
   fscanf(in,"%c%d%*c",&ch,&x);
   kx=ch-'A'+1;
   ky=x;
   s=0;
   while (!feof(in))
   {
      fscanf(in,"%c%d%*c",&ch,&x);
      s++;
      a[s][0]=ch-'A'+1;
      a[s][1]=x;
   }
   s--;
   if (s<=0)
      fprintf(out,"0\n");
   else
   {
      memset(f,15,sizeof(f));
      for (i=1;i<=m;i++)
         for (j=1;j<=n;j++)
         {
            f[i][j][i][j]=0;
               search(i,j);
         }
      ans=200000000;
      for (i=1;i<=m;i++)
         for (j=1;j<=n;j++)
            work(i,j);
      fprintf(out,"%d\n",ans);
   }
   fclose(in),fclose(out);
   return(0);
}
void search(int x,int y)
{
   int i,l,r,t;
   int a[10000][2];
   memset(a,0,sizeof(a));
   a[0][0]=x;
   a[0][1]=y;
   l=r=0;
   while (1)
   {
      t=f[x][y][a[l][0]][a[l][1]];
      for (i=0;i<8;i++)
      {
         if (a[l][0]+c[i][0]<=0 || a[l][0]+c[i][0]>m)
            continue;
         if (a[l][1]+c[i][1]<=0 || a[l][1]+c[i][1]>n)
            continue;
         if (f[x][y][a[l][0]+c[i][0]][a[l][1]+c[i][1]]<=20000)
            continue;
         r++;
         f[x][y][a[l][0]+c[i][0]][a[l][1]+c[i][1]]=t+1;
         a[r][0]=a[l][0]+c[i][0];
         a[r][1]=a[l][1]+c[i][1];
      }
      l++;
      if (l>r)
         break;
   }
}
void work(int x,int y)
{
   int make(int,int,int,int),max(int,int);
   int i,p,min,sum;
   sum=0;
   for (i=1;i<=s;i++)
      sum+=f[a[i][0]][a[i][1]][x][y];
   if (sum>=ans)
      return;
   min=20000000;
   for (i=0;i<=8;i++)
   {
      if (kx+d[i][0]<=0 || kx+d[i][1]>m)
         continue;
      if (ky+d[i][1]<=0 || ky+d[i][1]>n)
         continue;
      p=make(x,y,kx+d[i][0],ky+d[i][1]);
      if (p<min)
         min=p;
   }
   p=max(abs(kx-x),abs(ky-y));
   if (p<min)
      min=p;
   if (sum+min<ans)
      ans=sum+min;
}
int make(int x1,int y1,int x2,int y2)
{
   int max(int,int);
   int i,ans,p,q,x;
   ans=2000000;
   for (i=1;i<=s;i++)
   {
      p=a[i][0];
      q=a[i][1];
      x=f[x1][y1][x2][y2]+f[x2][y2][p][q];
      x+=max(abs(kx-x2),abs(ky-y2));
      x-=f[x1][y1][p][q];
      if (x<ans)
         ans=x;
   }
   return(ans);
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
