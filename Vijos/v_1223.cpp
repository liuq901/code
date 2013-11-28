#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int p,i,k,n;
int a[510],ar[110];
int main()
{
   void sqr(int *);
   void chen(int,int *);
   int t,jj;
   scanf("%d",&p);
   memset(a,0,sizeof(a));
   memset(ar,0,sizeof(ar));
   i=1;
   k=0;
   n=(int)(p*log(2)/log(10)+1);
   while (p!=0)
   {
      k++;
      ar[k]=p%2;
      p/=2;
   }
   a[0]=a[1]=1;
   for (i=k;i>=1;i--)
   {
      sqr(a);
      if (ar[i]==1)
         chen(2,a);
   }
   a[1]--;
   printf("%d\n",n);
   t=0;
   for (jj=500;jj>=1;jj--)
   {
      t++;
      printf("%d",a[jj]);
      if (t%50==0)
         printf("\n");
   }
   system("pause");
   return(0);
}
void sqr(int *a)
{
   int i,j,k,x;
   int b[510];
   memset(b,0,sizeof(b));
   k=500;
   for (i=1;i<=a[0];i++)
   {
      x=0;
      for (j=1;j<=a[0];j++)
      {
         if (i+j-1>500)
            break;
         x=a[i]*a[j]+x/10+b[i+j-1];
         b[i+j-1]=x%10;
      }
      j--;
      if (i+j-1<500)
         b[i+j]=x/10;
   }
   i--;
   if (i+j-1<500)
      for (k=i+j;k>=1;k--)
         if (b[k]!=0)
            break;
   k++;
   for (i=1;i<=k;i++)
      a[i]=b[i];
   a[0]=k;
}
void chen(int n,int *a)
{
   int i,x;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=a[i]*n+x;
      x=a[i]/10;
      a[i]%=10;
   }
   if (a[0]>500)
      a[0]=500;
   if (x!=0)
   {
      a[0]++;
      a[i+1]=x;
   }
}
