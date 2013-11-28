#include <cstdio>
#include <cstdlib>
int a[10010],b[10010];
int main()
{
   void sort(int,int);
   for (int test=1;test<=10;test++)
   {
      int x0,y0,n;
      scanf("%d%d%d",&x0,&y0,&n);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i],&a[i+n]);
         b[i]=-2,b[i+n]=1;
      }
      a[2*n+1]=x0,b[2*n+1]=-1;
      a[0]=y0,b[0]=0;
      sort(0,2*n+1);
      int sum=0,min=n,max=0;
      bool flag=false;
      for (int i=0;i<=2*n+1;i++)
      {
         if (b[i]==-2)
            sum++;
         else if (b[i]==1)
            sum--;
         else if (b[i]==-1)
            flag=true;
         else
            flag=false;
         if (flag)
         {
            if (sum<min)
               min=sum;
            if (sum>max)
               max=sum;
         }
      }
      printf("%d %d\n",min,max);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y;
   i=l,j=r;
   x=a[l+r>>1];
   y=b[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x || a[i]==x && b[i]<y)
         i++;
      while (a[j]>x || a[j]==x && b[j]>y)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
