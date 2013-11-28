/*
ID: liuq9011
LANG: C++
TASK: maze1
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int w,h,a[101][40],f[101][40][4];
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
   in=fopen("maze1.in","r");
   out=fopen("maze1.out","w");
   void search(int,int,int);
   int i,j,s;
   int b[10];
   char ch;
   fscanf(in,"%d%d%*c",&w,&h);
   memset(f,0,sizeof(f));
   for (i=1;i<=w;i++)
   {
      fscanf(in,"%*c%c",&ch);
      if (ch=='-')
         f[1][i][0]=1;
   }
   fscanf(in,"%*c%*c");
   for (i=1;i<=h;i++)
   {
      for (j=1;j<=w;j++)
      {
         fscanf(in,"%c%*c",&ch);
         if (ch=='|')
         {
            f[i][j][2]=1;
            if (j!=1)
               f[i][j-1][3]=1;
         }
      }
      fscanf(in,"%c%*c",&ch);
      if (ch=='|')
         f[i][w][3]=1;
      for (j=1;j<=w;j++)
      {
         fscanf(in,"%*c%c",&ch);
         if (ch=='-')
         {
            f[i][j][1]=1;
            if (i!=h)
               f[i+1][j][0]=1;
         }
      }
      fscanf(in,"%*c%*c");
   }
   memset(a,127,sizeof(a));
   s=0;
   for (i=1;i<=w;i++)
   {
      if (!f[1][i][0])
      {
         a[1][i]=1;
         b[s+1]=1;
         b[s+2]=i;
         s+=2;
      }
      if (!f[h][i][1])
      {
         a[h][i]=1;
         b[s+1]=h;
         b[s+2]=i;
         s+=2;
      }
   }
   for (i=1;i<=h;i++)
   {
      if (!f[i][1][2])
      {
         a[i][1]=1;
         b[s+1]=i;
         b[s+2]=1;
         s+=2;
      }
      if (!f[i][w][3])
      {
         a[i][w]=1;
         b[s+1]=i;
         b[s+2]=w;
         s+=2;
      }
   }
   search(b[1],b[2],1);
   search(b[3],b[4],1);
   s=0;
   for (i=1;i<=h;i++)
      for (j=1;j<=w;j++)
         if (a[i][j]>s)
            s=a[i][j];
   fprintf(out,"%d\n",s);
   fclose(in),fclose(out);
   return(0);
}
void search(int x,int y,int t)
{
   int i,s1,s2;
   for (i=0;i<=3;i++)
   {
      s1=x+c[i][0];
      s2=y+c[i][1];
      if (s1<1 || s1>h || s2<1 || s2>w)
         continue;
      if (!f[x][y][i] && t+1<a[s1][s2])
      {
         a[s1][s2]=t+1;
         search(s1,s2,t+1);
      }
   }
}
