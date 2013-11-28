#include <cstdio>
#include <cstdlib>
int a[1001],b[1001],p[1001];
int main()
{
   void sort(int,int);
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i],&b[i]);
         p[i]=i;
      }
      sort(1,n);
      int k=-20000000;
      bool flag=false;
      for (int i=1;i<=n;i++)
         if (a[i]>k)
         {
            if (flag)
               printf(" ");
            printf("%d",p[i]);
            flag=true;
            k=b[i];
         }
      printf("\n");
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=b[l+r>>1];
   while (i<=j)
   {
      while (b[i]<x)
         i++;
      while (b[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
