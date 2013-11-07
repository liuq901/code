#include <cstdio>
#include <cstdlib>
int main()
{ 
   int i,j,n,b[100],c[100],f[100],s,sum,max,p;
   char a[100][20],d[100],e[100];
   scanf("%d",&n);
   for (i=0;i<n;i++)
      scanf("%s%d%d%*c%c%*c%c%d",&a[i],&b[i],&c[i],&d[i],&e[i],&f[i]);
   max=0;
   s=0;
   for (i=0;i<n;i++)
   {
      sum=0;
      if (b[i]>80 && f[i]>=1)
         sum+=8000;
      if (b[i]>85 && c[i]>80)
         sum+=4000;
      if (b[i]>90)
         sum+=2000;
      if (b[i]>85 && e[i]=='Y')
         sum+=1000;
      if (c[i]>80 && d[i]=='Y')
         sum+=850;
      s+=sum;
      if (sum>max)
      {
         p=i;
         max=sum;
      }
   }
   printf("%s\n",a[p]);
   printf("%d\n",max);
   printf("%d\n",s);
   system("pause");
   return(0);
}
