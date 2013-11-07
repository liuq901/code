#include <cstdio>
#include <cstdlib>
int t[101],l[101];
int main()
{
   int n,i,j,k,s;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&t[i]);
   for (i=1;i<=n;i++)
      scanf("%d",&l[i]);
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (l[i]<l[j])
         {
            k=l[i],l[i]=l[j],l[j]=k;
            k=t[i],t[i]=t[j],t[j]=k;
         }
   s=k=0;
   for (i=1;i<=n;i++)
   {
      s+=t[i];
      if (s+l[i]>k)
         k=s+l[i];
   }
   printf("%d\n",k);
   system("pause");
   return(0);
}
