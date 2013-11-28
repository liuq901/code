/*
ID: liuq9011
LANG: C++
TASK: humble
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("humble.in","r");
   out=fopen("humble.out","w");
   int i,j,k,n,t,min;
   int a[101],b[101],c[100001];
   fscanf(in,"%d%d",&k,&n);
   for (i=1;i<=k;i++)
      fscanf(in,"%d",&a[i]);
   for (i=1;i<=k-1;i++)
      for (j=i+1;j<=k;j++)
         if (a[i]>a[j])
            t=a[i],a[i]=a[j],a[j]=t;
   for (i=1;i<=k;i++)
      b[i]=0;
   c[0]=1;
   i=0;
   while (1)
   {
      i++;
      min=2000000000;
      t=0;
      for (j=1;j<=k;j++)
         if (a[j]*c[b[j]]<min)
            min=a[j]*c[b[j]];
      c[i]=min;
      for (j=1;j<=k;j++)
         if (a[j]*c[b[j]]==min)
            b[j]++;
      if (i>=n)
         break;
   }
   fprintf(out,"%d\n",c[n]);
   fclose(in),fclose(out);
   return(0);
}
