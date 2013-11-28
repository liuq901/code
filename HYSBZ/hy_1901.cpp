#include <cstdio>
#include <cstdlib>
int a[50001],b[50001],p[50001];
int main()
{
   void sort(int,int);
   int n,m;
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      p[i]=i;
   }
   scanf("%*c");
   sort(1,n);
   for (int i=1;i<=n;i++)
      b[p[i]]=i;
   for (int i=1;i<=m;i++)
   {
      char ch;
      scanf("%c",&ch);
      if (ch=='Q')
      {
         int l,r,k;
         scanf("%d%d%d",&l,&r,&k);
         int s=0;
         for (int j=1;j<=n;j++)
         {
            if (p[j]>=l && p[j]<=r)
               s++;
            if (s==k)
            {
               printf("%d\n",a[j]);
               break;
            }
         }
      }
      else
      {
         int x,k;
         scanf("%d%d",&x,&k);
         int t=b[x];
         a[t]=k;
         while (t!=n && a[t]>a[t+1])
         {
            int tmp;
            tmp=a[t],a[t]=a[t+1],a[t+1]=tmp;
            tmp=p[t],p[t]=p[t+1],p[t+1]=tmp;
            b[p[t]]=t,b[p[t+1]]=t+1;
            t++;
         }
         while (t!=1 && a[t]<a[t-1])
         {
            int tmp;
            tmp=a[t],a[t]=a[t-1],a[t-1]=tmp;
            tmp=p[t],p[t]=p[t-1],p[t-1]=tmp;
            b[p[t]]=t,b[p[t-1]]=t-1;
            t--;
         }
      }
      scanf("%*c");
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
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
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
