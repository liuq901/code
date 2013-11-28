/*
ID: liuq9011
LANG: C++
TASK: shopping
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("shopping.in","r");
   out=fopen("shopping.out","w");
   int i,j,k,n,s,i1,i2,i3,i4,i5,flag;
   int a[1000][2][10],p[1000],b[10],c[1000],d[1000],f[6][6][6][6][6],t[6];
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   memset(c,0,sizeof(c));
   memset(d,0,sizeof(d));
   fscanf(in,"%d",&s);
   for (i=1;i<=s;i++)
   {
      fscanf(in,"%d",&a[i][0][0]);
      for (j=1;j<=a[i][0][0];j++)
         fscanf(in,"%d%d",&a[i][0][j],&a[i][1][j]);
      fscanf(in,"%d",&p[i]);
   }
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d%d%d",&b[i],&c[i],&d[i]);
   memset(f,-127,sizeof(f));
   for (i1=0;i1<=c[1];i1++)
      for (i2=0;i2<=c[2];i2++)
         for (i3=0;i3<=c[3];i3++)
            for (i4=0;i4<=c[4];i4++)
               for (i5=0;i5<=c[5];i5++)
                  f[i1][i2][i3][i4][i5]=i1*d[1]+i2*d[2]+i3*d[3]+i4*d[4]+i5*d[5];
   for (i1=0;i1<=c[1];i1++)
      for (i2=0;i2<=c[2];i2++)
         for (i3=0;i3<=c[3];i3++)
            for (i4=0;i4<=c[4];i4++)
               for (i5=0;i5<=c[5];i5++)
                  for (i=1;i<=s;i++)
                  {
                     t[1]=i1,t[2]=i2,t[3]=i3,t[4]=i4,t[5]=i5;
                     for (j=1;j<=a[i][0][0];j++)
                     {
                        flag=1;
                        for (k=1;k<=n;k++)
                           if (b[k]==a[i][0][j])
                           {
                              flag=0;
                              break;
                           }
                        if (flag)
                           break;
                        if (t[k]<a[i][1][j])
                           break;
                        t[k]-=a[i][1][j];
                     }
                     if (flag)
                        break;
                     if (f[t[1]][t[2]][t[3]][t[4]][t[5]]+p[i]<f[i1][i2][i3][i4][i5])
                        f[i1][i2][i3][i4][i5]=f[t[1]][t[2]][t[3]][t[4]][t[5]]+p[i];
                  }
   fprintf(out,"%d\n",f[c[1]][c[2]][c[3]][c[4]][c[5]]);
   fclose(in),fclose(out);
   return(0);
}
