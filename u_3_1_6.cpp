/*
ID: liuq9011
LANG: C++
TASK: stamps
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[51],f[2000001];
int main()
{
   in=fopen("stamps.in","r");
   out=fopen("stamps.out","w");
   void sort(int,int);
   int m,n,x,i,j,k;
   fscanf(in,"%d%d",&m,&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&a[i]);
   a[0]=1;
   memset(f,0,sizeof(f));
   i=0;
   sort(1,n);
   while (1)
   {
      i++;
      k=2000000;
      for (j=1;j<=n;j++)
         if (i-a[j]>=0 && f[i-a[j]]+1<k)
             k=f[i-a[j]]+1;
      f[i]=k;
      if (k>m)
      {
         fprintf(out,"%d\n",i-1);
         break;
      }
   }
   fclose(in),fclose(out);
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}

