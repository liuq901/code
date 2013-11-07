/*
ID: liuq9011
LANG: C++
TASK: spin
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[6][6][2],w[6];
int main()
{
   in=fopen("spin.in","r");
   out=fopen("spin.out","w");
   int check();
   int i,j,k,x,flag;
   int v[6];
   for (i=1;i<=5;i++)
   {
      fscanf(in,"%d%d",&v[i],&w[i]);
      for (j=1;j<=w[i];j++)
      {
         fscanf(in,"%d%d",&a[i][j][0],&x);
         a[i][j][1]=a[i][j][0]+x;
      }
   }
   i=0;
   flag=1;
   while (1)
   {
      if (check())
      {
         fprintf(out,"%d\n",i);
         break;
      }
      for (j=1;j<=5;j++)
         for (k=1;k<=w[j];k++)
         {
            a[j][k][0]+=v[j];
            a[j][k][1]+=v[j];
            if (a[j][k][0]>=360)
            {
               a[j][k][0]-=360;
               a[j][k][1]-=360;
            }
         }
      i++;
      if (i>360)
      {
         flag=0;
         break;
      }
   }
   if (!flag)
      fprintf(out,"none\n");
   fclose(in),fclose(out);
   return(0);
}
int check()
{
   int i,j,k,flag;
   int f[10];
   for (i=1;i<=719;i++)
   {
      memset(f,0,sizeof(f));
      for (j=1;j<=5;j++)
         for (k=1;k<=w[j];k++)
            if ((i>=a[j][k][0] && i<=a[j][k][1]) || (i>=a[j][k][0]-360 && i<=a[j][k][1]-360))
            {
               f[j]=1;
               break;
            }
      if (f[1] && f[2] && f[3] && f[4] && f[5])
         return(1);
   }
   return(0);
}
