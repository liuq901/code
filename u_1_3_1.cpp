/*
ID: liuq9011
LANG: C++
TASK: milk
*/
#include <cstdio>
FILE *in,*out;
int a[5001],p[5001];
int main()
{
   in=fopen("milk.in","r");
   out=fopen("milk.out","w");
   void sort(int,int);
   int n,m,i,s;
   fscanf(in,"%d%d",&n,&m);
   for (i=1;i<=m;i++)
      fscanf(in,"%d%d",&p[i],&a[i]);
   sort(1,m);
   s=0;
   for (i=1;i<=m;i++)
      if (a[i]<n)
      {
         n-=a[i];
         s+=a[i]*p[i];
      }
      else
      {
         s+=p[i]*n;
         break;
      }
   fprintf(out,"%d\n",s);
   fclose(in),fclose(out);
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=p[(l+r)/2];
   while (i<=j)
   {
      while (p[i]<x)
         i++;
      while (p[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
