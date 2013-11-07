#include <cstdio>
#include <cstdlib>
int a[100000];
int main()
{
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<n;i++)
         scanf("%d",&a[i]);
      int p=0,max=-1<<30,now=1,l,r;
      for (int i=1;i<n;i++)
      {
         if (a[i]>p+a[i])
         {
            p=a[i];
            now=i;
         }
         else
            p+=a[i];
         if (p>max)
         {
            l=now;
            r=i+1;
            max=p;
         }
         else if (p==max && i-now+1>r-l)
         {
            l=now;
            r=i+1;
         }
      }
      if (max>0)
         printf("The nicest part of route %d is between stops %d and %d\n",id,l,r);
      else
         printf("Route %d has no nice parts\n",id);
   }
   system("pause");
   return(0);
}
