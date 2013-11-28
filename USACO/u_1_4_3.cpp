/*
ID: liuq9011
LANG: C++
TASK: ariprog
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("ariprog.in","r");
   out=fopen("ariprog.out","w");
   int i,j,k,n,m,t,max,flag,noanswer;
   int f[130000],a[130000];
   fscanf(in,"%d%d",&n,&m);
   memset(f,0,sizeof(f));
   for (i=0;i<=m;i++)
      for (j=0;j<=m;j++)
         f[i*i+j*j]=1;
   max=2*m*m;
   t=0;
   for (i=0;i<=max;i++)
      if (f[i])
      {
         t++;
         a[t]=i;
      }
   noanswer=0;
   for (i=1;i<=max/(n-1);i++)
      for (j=1;j<=t;j++)
      {
         if (a[j]+i*(n-1)>max)
            break;
         flag=1;
         for (k=1;k<=n-1;k++)
            if (!f[a[j]+i*k])
            {
               flag=0;
               break;
            }
         if (flag)
         {
            noanswer=1;
            fprintf(out,"%d %d\n",a[j],i);
         }
      }
   if (!noanswer)
      fprintf(out,"NONE\n");
   fclose(in),fclose(out);
   return(0);
}
