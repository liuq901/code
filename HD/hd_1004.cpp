#include <cstdio>
#include <cstdlib>
#include <cstring>
char *a[1001];
int main()
{
   void sort(int,int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      char s[1001][20];
      for (int i=1;i<=n;i++)
      {
         scanf("%s",s[i]);
         a[i]=s[i];
      }
      sort(1,n);
      char *ans;
      int max=0,sum=1;
      ans=a[1];
      for (int i=2;i<=n;i++)
         if (strcmp(a[i],a[i-1]))
         {
            if (sum>max)
            {
               max=sum;
               ans=a[i-1];
            }
            sum=1;
         }
         else
            sum++;
      if (sum>max)
      {
         max=sum;
         ans=a[n];
      }
      printf("%s\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j;
   char x[20],*t;
   i=l,j=r;
   memcpy(x,a[l+r>>1],sizeof(x));
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
