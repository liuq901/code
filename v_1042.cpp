#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const int c[5]={0,1,3,7,9};
int x,y,m,n,a[26];
int main()
{
   void make(int);
   int i,t;
   scanf("%d%d",&x,&y);
   m=n=0;
   t=x;
   while (t!=0)
   {
      m++;
      t/=10;
   }
   t=y;
   while (t!=0)
   {
      n++;
      t/=10;
   }
   for (i=m;i<=n;i++)
      make(i);
   system("pause");
   return(0);
}
void make(int s)
{
   void work(int);
   int i;
   if (s%2==0)
      if (s==2)
      {
         if (11>=x && 11<=y)
            printf("11\n");
         return;
      }
      else
         return;
   else if (s==1)
   {
      if (3>=x && 3<=y)
         printf("3\n");
      if (5>=x && 5<=y)
         printf("5\n");
      if (7>=x && 7<=y)
         printf("7\n");
      return;
   }
   else
   {
      memset(a,0,sizeof(a));
      a[0]=s;
      for (i=1;i<=4;i++)
      {
         a[1]=c[i];
         work(1);
      }
   }
}
void work(int s)
{
   int ss(int);
   int i,j,z;
   if (s==a[0]/2)
      for (i=0;i<=9;i++)
      {
         a[a[0]/2+1]=i;
         for (j=a[0]/2+2;j<=a[0];j++)
            a[j]=a[a[0]-j+1];
         z=0;
         for (j=1;j<=a[0];j++)
            z=z*10+a[j];
         if (z>=x && z<=y && ss(z))
            printf("%d\n",z);
      }
   else
      for (i=0;i<=9;i++)
      {
         a[s+1]=i;
         work(s+1);
      }
}
int ss(int x)
{
   int i;
   for (i=2;i<=sqrt(x)+0.5;i++)
      if (x%i==0)
         return(0);
   return(1);
}
