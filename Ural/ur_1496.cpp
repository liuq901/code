#include <cstdio>
#include <cstdlib>
#include <cstring>
char *a[101],s[101][100];
int main()
{
   void sort(int,int),print(int);
   int n,i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%s",s[i]);
      a[i]=s[i];
   }
   sort(1,n);
   print(n);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j;
   char *t,*x;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (strcmp(a[i],x)<0)
         i++;
      while (strcmp(a[j],x)>0)
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
void print(int n)
{
   int flag,i;
   char *s;
   s=a[1];
   flag=0;
   for (i=2;i<=n;i++)
   {
      if (strcmp(a[i],s)==0 && !flag)
      {
         printf("%s\n",a[i]);
         flag=1;
      }
      if (strcmp(a[i],s)!=0)
      {
         s=a[i];
         flag=0;
      }
   }
}
