#include <cstdio>
#include <cstdlib>
int a[1000001];
int main()
{
   void sort(int,int);
   int x;
   a[0]=0;
   while (scanf("%d",&x)!=EOF)
      a[++a[0]]=x;
   sort(1,a[0]);
   int ans=-1;
   for (int i=1;i<=a[0]-4;i+=3)
      if (a[i+1]!=a[i+2])
      {
         ans=a[i+1];
         break;
      }
   if (ans==-1)
      ans=a[a[0]];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
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
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
