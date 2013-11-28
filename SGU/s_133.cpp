#include <cstdio>
#include <cstdlib>
struct data
{
   int x,y;
};
struct data a[16000];
int main()
{
   int compare(const void *,const void *);
   int i,n,s,max;
   scanf("%d",&n);
   for (i=0;i<n;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
   qsort(a,n,sizeof(struct data),compare);
   max=-1;
   s=0;
   for (i=0;i<n;i++)
      if (a[i].y<max)
         s++;
      else
         max=a[i].y;
   printf("%d\n",s);
   system("pause");
   return(0);
}
int compare(const void *a,const void *b)
{
   struct data x,y;
   x=*(struct data *)a;
   y=*(struct data *)b;
   if (x.x<y.x)
      return(-1);
   else
      return(1);
}
