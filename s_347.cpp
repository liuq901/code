#include <cstdio>
#include <cstdlib>
#include <cstring>
char *a[101];
int main()
{
   void sort(int,int);
   int n,i,j,l,t,p;
   char s[101][110];
   while (1){i=j=1;}
   scanf("%d%*c",&n);
   l=0;
   for (i=1;i<=n;i++)
   {
      scanf("%s",s[i]);
      a[i]=s[i];
   }
   sort(1,n);
   for (i=1;i<=n;i++)
      printf("%s",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int compare(char *,char *);
   int i,j;
   char *x,*t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (compare(a[i],x)<0)
         i++;
      while (compare(a[j],x)>0)
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
int compare(char *a,char *b)
{
   int l1,l2,t1,t2;
   t1=t2=-1;
   l1=strlen(a);
   l2=strlen(b);
   while (1)
   {
      t1++;
      t2++;
      if (t1==l1 && t2==l2)
         break;
      if (t1==l1)
         t1=0;
      if (t2==l2)
         t2=0;
      if (a[t1]<b[t2])
         return(-1);
      if (a[t1]>b[t2])
         return(1);
   }
   return(0);
}
