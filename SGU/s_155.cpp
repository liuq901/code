#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[50001],b[50001],c[50001],l[50001],r[50001],f[50001],p[50001];
int main()
{
   void sort(int,int),turn(int);
   int n,i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i],&b[i]);
      c[i]=i;
   }
   c[0]=0;
   sort(1,n);
   for (i=1;i<=n;i++)
      p[c[i]]=i;
   memset(l,0,sizeof(l));
   memset(r,0,sizeof(r));
   memset(f,0,sizeof(f));
   for (i=2;i<=n;i++)
   {
      r[i-1]=i;
      f[i]=i-1;
      turn(i);
   }
   printf("YES\n");
   for (i=1;i<=n;i++)
      printf("%d %d %d\n",c[f[p[i]]],c[l[p[i]]],c[r[p[i]]]);
   system("pause");
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
         t=b[i],b[i]=b[j],b[j]=t;
         t=c[i],c[i]=c[j],c[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void turn(int x)
{
   int t;
   while (f[x]!=0 && b[x]<b[f[x]])
   {
      t=f[x];
      f[x]=f[t];
      if (l[f[x]]==t)
         l[f[x]]=x;
      else
         r[f[x]]=x;
      r[t]=l[x];
      f[r[t]]=t;
      l[x]=t;
      f[t]=x;
   }
}
