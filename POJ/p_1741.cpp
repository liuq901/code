#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,k,min,p,ans,l,q[10001],f[10001],c[10001],belong[10001];
int b[10001],a[20000][4];
int main()
{
   void search(int,int);
   int x,y,z,i;
   while (1)
   {
      scanf("%d%d",&n,&k);
      if (n==0 && k==0)
         break;
      memset(b,0,sizeof(b));
      for (i=1;i<=n-1;i++)
      {
         scanf("%d%d%d",&x,&y,&z);
         a[2*i-1][0]=y;
         a[2*i-1][1]=z;
         a[2*i-1][2]=b[x];
         a[2*i-1][3]=1;
         b[x]=2*i-1;
         a[2*i][0]=x;
         a[2*i][1]=z;
         a[2*i][2]=b[y];
         a[2*i][3]=1;
         b[y]=2*i;
      }
      ans=0;
      search(1,n);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void search(int t,int sum)
{
   int count(int,int);
   void calc(int,int,int),sort(int,int,int *),work(int,int,int,int *);
   int i,j,flag;
   if (sum==1)
      return;
   min=20000000;
   count(t,sum);
   i=b[p];
   l=1;
   c[1]=0;
   belong[1]=0;
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      calc(a[i][0],a[i][1],a[i][0]);
      if (i%2==1)
         a[i+1][3]=1;
      else
         a[i-1][3]=1;
      i=a[i][2];
   }
   for (i=1;i<=l;i++)
      q[i]=c[i];
   sort(1,l,c);
   work(1,1,l,c);
   j=1;
   flag=belong[1];
   for (i=2;i<=l;i++)
   {
      if (belong[i]==flag)
         continue;
      sort(j,i-1,q);
      work(-1,j,i-1,q);
      flag=belong[i];
      j=i;
   }
   sort(j,l,q);
   work(-1,j,l,q);
   i=b[p];
   count(p,sum);
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      search(a[i][0],f[a[i][0]]);
      i=a[i][2];
   }
}
int count(int x,int sum)
{
   int i,t,max;
   i=b[x];
   f[x]=1;
   max=0;
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      t=count(a[i][0],sum);
      if (i%2==1)
         a[i+1][3]=1;
      else
         a[i-1][3]=1;
      if (t>max)
         max=t;
      f[x]+=t;
      i=a[i][2];
   }
   if (sum-f[x]>max)
      max=sum-f[x];
   if (max<min)
   {
      min=max;
      p=x;
   }
   return(f[x]);
}
void calc(int x,int y,int z)
{
   int i;
   l++;
   c[l]=y;
   belong[l]=z;
   i=b[x];
   while (i!=0)
   {
      if (!a[i][3])
      {
         i=a[i][2];
         continue;
      }
      if (i%2==1)
         a[i+1][3]=0;
      else
         a[i-1][3]=0;
      calc(a[i][0],y+a[i][1],z);
      if (i%2==1)
         a[i+1][3]=1;
      else
         a[i-1][3]=1;
      i=a[i][2];
   }
}
void sort(int l,int r,int *a)
{
   int i,j,t,x;
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
void work(int t,int l,int r,int *a)
{
   int i,j;
   i=l;
   j=r;
   while (i<j)
   {
      while (a[i]+a[j]>k && i<j)
         j--;
      ans+=t*(j-i);
      i++;
   }
}
