#include <cstdio>
#include <cstdlib>
int main()
{
   int right(int[101],int,int);
   int n,sum,i,j,ave,x;
   int a[101];
   scanf("%d",&n);
   sum=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      sum+=a[i];
   }
   ave=sum/n;
   i=0;
   j=0;
   while (n-1!=i)
   {
      if (right(a,n,ave))
      {
         printf("%d\n",j);
         goto last;
      }   
      i++;
      x=a[i]-ave;
      if (x!=0)
         j++;
      a[i]=ave;
      a[i+1]+=x;
   }
   printf("%d\n",j);
last:
   system("pause");
   return(0);
}
int right(int a[101],int n,int ave)
{
   int i,k;
   k=1;
   for (i=1;i<=n;i++)
      if (a[i]!=ave)
      {
         k=0;
         break;
      }
   return(k);
}
