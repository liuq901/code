/*
ID: liuq9011
LANG: C++
TASK: clocks
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int c[10][10]={{0},{0,3,3,0,3,3,0,0,0,0},
   {0,3,3,3,0,0,0,0,0,0},{0,0,3,3,0,3,3,0,0,0},
   {0,3,0,0,3,0,0,3,0,0},{0,0,3,0,3,3,3,0,3,0},
   {0,0,0,3,0,0,3,0,0,3},{0,0,0,0,3,3,0,3,3,0},
   {0,0,0,0,0,0,0,3,3,3},{0,0,0,0,0,3,3,0,3,3}};
int min,ans[10],a[10],s[10];
int main()
{
   in=fopen("clocks.in","r");
   out=fopen("clocks.out","w");
   void work();
   int i,j,flag;
   for (i=1;i<=9;i++)
      fscanf(in,"%d",&a[i]);
   memset(ans,0,sizeof(ans));
   min=2000000;
   for (s[9]=0;s[9]<=3;s[9]++)
      for (s[8]=0;s[8]<=3;s[8]++)
         for (s[7]=0;s[7]<=3;s[7]++)
            for (s[6]=0;s[6]<=3;s[6]++)
               for (s[5]=0;s[5]<=3;s[5]++)
                  for (s[4]=0;s[4]<=3;s[4]++)
                     for (s[3]=0;s[3]<=3;s[3]++)
                        for (s[2]=0;s[2]<=3;s[2]++)
                           for (s[1]=0;s[1]<=3;s[1]++)
                              work();
   flag=0;
   for (i=1;i<=9;i++)
      for (j=1;j<=ans[i];j++)
      {
         if (flag)
            fprintf(out," ");
         fprintf(out,"%d",i);
         flag=1;
      }
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
void work()
{
   int i,j,k,t;
   int b[10];
   k=t=0;
   for (i=1;i<=9;i++)
   {
      b[i]=a[i];
      for (j=1;j<=9;j++)
         b[i]+=c[j][i]*s[j];
      b[i]%=12;
      t+=b[i];
      k+=s[i];
   }
   if (t==0 && k<min)
   {
      min=k;
      for (i=1;i<=9;i++)
         ans[i]=s[i];
   }
}
