/*
ID: liuq9011
LANG: C++
TASK: ttwo
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int w[5][2]={{0},{-1,0},{0,1},{1,0},{0,-1}};
int main()
{
   in=fopen("ttwo.in","r");
   out=fopen("ttwo.out","w");
   int i,j,x1,y1,z1,x2,y2,z2,s;
   int f[26][26];
   char ch;
   memset(f,0,sizeof(f));
   for (i=1;i<=10;i++)
   {
      for (j=1;j<=10;j++)
      {
         fscanf(in,"%c",&ch);
         if (ch=='*')
            f[i][j]=1;
         else
            f[i][j]=0;
         if (ch=='F')
         {
            x1=i;
            y1=j;
         }
         if (ch=='C')
         {
            x2=i;
            y2=j;
         }
      }
      fscanf(in,"%*c");
   }
   for (i=0;i<=11;i++)
   {
      f[0][i]=1;
      f[11][i]=1;
      f[i][0]=1;
      f[i][11]=1;
   }
   s=0;
   z1=z2=1;
   while (1)
   {
      if (x1==x2 && y1==y2)
         break;
      if (s>10000000)
      {
         s=-1;
         break;
      }
      if (!f[x1+w[z1][0]][y1+w[z1][1]])
      {
         x1+=w[z1][0];
         y1+=w[z1][1];
      }
      else
      {
         z1++;
         if (z1==5)
            z1=1;
      }
      if (!f[x2+w[z2][0]][y2+w[z2][1]])
      {
         x2+=w[z2][0];
         y2+=w[z2][1];
      }
      else
      {
         z2++;
         if (z2==5)
            z2=1;
      }
      s++;
   }
   if (s==-1)
      fprintf(out,"0\n");
   else
      fprintf(out,"%d\n",s);
   fclose(in),fclose(out);
   return(0);
}
