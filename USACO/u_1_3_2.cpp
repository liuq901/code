/*
ID: liuq9011
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int s,c,a[201],f[201];
int main()
{
   in=fopen("barn1.in","r");
   out=fopen("barn1.out","w");
   void sort(int,int);
   int find();
   int i,m,sum,ans;
   fscanf(in,"%d%d%d",&m,&s,&c);
   memset(f,0,sizeof(f));
   for (i=1;i<=c;i++)
   {
      fscanf(in,"%d",&a[i]);
      f[a[i]]=1;
   }
   sum=ans=c;
   sort(1,c);
   for (i=1;i<=c;i++)
      if (a[i]+1==a[i+1])
         sum--;
   while (1)
   {
      if (sum<=m)
         break;
      sum--;
      ans+=find();
      printf("%d\n",ans);
   }
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=a[(i+r)/2];
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
int find()
{
   int i,x,y,min;
   min=20000000;
   for (i=1;i<=c-1;i++)
      if (a[i+1]-a[i]<min && !f[a[i]+1])
      {
         min=a[i+1]-a[i];
         x=a[i];
         y=a[i+1];
      }
   for (i=x+1;i<y;i++)
      f[i]=1;
   return(min-1);
}
