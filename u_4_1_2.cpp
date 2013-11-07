/*
ID: liuq9011
LANG: C++
TASK: fence8
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int m,n,flag,a[101],f[101],b[1026],s[1026];
main()
{
   in=fopen("fence8.in","r");
   out=fopen("fence8.out","w");
   void init(),work();
   init();
   work();
   fclose(in),fclose(out);
   return(0);
}
void init()
{
   void sort(int,int,int *);
   int i;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   memset(s,0,sizeof(s));
   fscanf(in,"%d",&m);
   for (i=1;i<=m;i++)
      fscanf(in,"%d",&a[i]);
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&b[i]);
   sort(1,m,a);
   sort(1,n,b);
   s[1]=b[1];
   for (i=2;i<=n;i++)
      s[i]=s[i-1]+b[i];
}
void sort(int l,int r,int *a)
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
      sort(i,r,a);
   if (l<j)
      sort(l,j,a);
}
void work()
{
   void search(int,int);
   int i,l,r,mid,t;
   l=0;
   r=n;
   while (1)
   {
      mid=(l+r+1)/2;
      flag=0;
      for (i=1;i<=m;i++)
         f[i]=a[i];
      search(mid,m);
      if (flag)
         l=mid;
      else
         r=mid-1;
      if (l>=r)
         break;
   }
   fprintf(out,"%d\n",l);
}
void search(int x,int y)
{
   int i,t,max;
   if (x==0)
   {
      flag=1;
      return;
   }
   t=0;
   max=0;
   for (i=1;i<=m;i++)
   {
      if (f[i]>=b[1])
         t+=f[i];
      if (f[i]>=max)
         max=f[i];
   }
   if (t<s[x])
      return;
   if (max>=s[x])
   {
      flag=1;
      return;
   }
   for (i=m;i>=1;i--)
      if (f[i]==b[x])
      {
         f[i]=0;
         search(x-1,m);
         f[i]=b[x];
         return;
      }
   for (i=y;i>=1;i--)
      if (f[i]>=b[x] && f[i]!=f[i-1])
      {
         f[i]-=b[x];
         if (i!=m && b[x-1]==b[x] && f[i]!=f[i+1])
            search(x-1,i);
         else
            search(x-1,m);
         if (flag)
            return;
         f[i]+=b[x];
      }
}
