#include <cstdio>
#include <cstdlib>
int flag,a[10][10],b[10][10];
int main()
{
   void count(),work();
   int n,i,j;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   if (n==1)
      if (a[i][j]==0)
         printf("1\n");
      else
         printf("NO SOLUTION\n");
   else if (n==2)
      count();
   else
      work();
   system("pause");
   return(0);
}
void count()
{
   int i,j,k,l,s;
   for (i=1;i<=9;i++)
      for (j=1;j<=9;j++)
         for (k=1;k<=9;k++)
            for (l=1;l<=9;l++)
            {
               s=0;
               if (j>i)
                  s++;
               if (k>i)
                  s++;
               if (s!=a[1][1])
                  continue;
               s=0;
               if (i>j)
                  s++;
               if (l>j)
                  s++;
               if (s!=a[1][2])
                  continue;
               s=0;
               if (i>k)
                  s++;
               if (l>k)
                  s++;
               if (s!=a[2][1])
                  continue;                                 
               s=0;
               if (j>l)
                  s++;
               if (k>l)
                  s++;
               if (s!=a[2][2])
                  continue;
               printf("%d %d\n",i,j);
               printf("%d %d\n",k,l);
               return;
            }
   printf("NO SOLUTION\n");
}
void work()
{
   int check(int);
   void search(),print();
   int i,j,k,l,p;
   flag=0;
   for (i=1;i<=9;i++)
      for (j=1;j<=9;j++)
         for (k=1;k<=9;k++)
            for (l=1;l<=9;l++)
               for (p=1;p<=9;p++)
               {
                  b[1][2]=i;
                  b[2][1]=j;
                  b[2][3]=k;
                  b[3][2]=l;
                  if (!check(p))
                     continue;
                  b[2][2]=p;
                  search();
                  if (flag)
                  {
                     print();
                     return;
                  }
               }
   printf("NO SOLUTION\n");
}
int check(int x)
{
   int s;
   s=0;
   if (b[1][2]>x)
      s++;
   if (b[2][1]>x)
      s++;
   if (b[2][3]>x)
      s++;
   if (b[3][2]>x)
      s++;
   if (s==a[2][2])
      return(1);
   else
      return(0);
}
void search()
{
   int s,i,j,k,l;
   for (i=1;i<=9;i++)
   {
      b[1][1]=i;
      s=0;
      if (b[1][2]>i)
         s++;
      if (b[2][1]>i)
         s++;
      if (s!=a[1][1])
         continue;
      for (j=1;j<=9;j++)
      {
         b[1][3]=j;
         s=0;
         if (b[1][2]>j)
            s++;
         if (b[2][3]>j)
            s++;
         if (s!=a[1][3])
            continue;
         s=0;
         if (b[1][1]>b[1][2])
            s++;
         if (b[1][3]>b[1][2])
            s++;
         if (b[2][2]>b[1][2])
            s++;
         if (s!=a[1][2])
            continue;
         for (k=1;k<=9;k++)
         {
            b[3][1]=k;
            s=0;
            if (b[2][1]>k)
               s++;
            if (b[3][2]>k)
               s++;
            if (s!=a[3][1])
               continue;
            s=0;
            if (b[1][1]>b[2][1])
               s++;
            if (b[3][1]>b[2][1])
               s++;
            if (b[2][2]>b[2][1])
               s++;
            if (s!=a[2][1])
               continue;
            for (l=1;l<=9;l++)
            {
               b[3][3]=l;
               s=0;
               if (b[2][3]>l)
                  s++;
               if (b[3][2]>l)
                  s++;
               if (s!=a[3][3])
                  continue;
               s=0;
               if (b[1][3]>b[2][3])
                  s++;
               if (b[3][3]>b[2][3])
                  s++;
               if (b[2][2]>b[2][3])
                  s++;
               if (s!=a[2][3])
                  continue;
               s=0;
               if (b[3][1]>b[3][2])
                  s++;
               if (b[3][3]>b[3][2])
                  s++;
               if (b[2][2]>b[3][2])
                  s++;
               if (s!=a[3][2])
                  continue;
               flag=1;
               return;
            }
         }
      }
   }
}
void print()
{
   int i,j;
   for (i=1;i<=3;i++)
      for (j=1;j<=3;j++)
      {
         printf("%d",b[i][j]);
         if (j==3)
            printf("\n");
         else
            printf(" ");
      }
}
