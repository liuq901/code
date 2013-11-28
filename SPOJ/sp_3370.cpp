#include <cstdio>
#include <cstdlib>
int a[100001];
int main()
{
   void sort(int,int);
   int x;
   while (scanf("%d",&x)!=EOF)
      a[++a[0]]=x;
   sort(1,a[0]);
   for (int i=1;i<a[0];i++)
      printf("%d ",a[i]);
   printf("%d\n",a[a[0]]);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
