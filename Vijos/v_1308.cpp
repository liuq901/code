#include <cstdio>
#include <cstdlib>
long long n,m,a[1001],b[1001];
int main()
{
   long long search(long long,long long,long long,long long,long long);
   int i,j;
   scanf("%I64d%I64d",&n,&m);
   for (i=1;i<=1000;i++)
   {
      for (j=1;j<=1000;j++)
         a[j]=b[j]=20000000;
      if (search(1,n,m,i,2))
         break;
   }
   for (j=1;j<i;j++)
      printf("%I64d ",a[j]);
   printf("%I64d\n",a[i]);
   system("pause");
   return(0);
}
long long search(long long x,long long u,long long d,long long h,long long res)  
{
   long long gcd(long long,long long);
   long long i,j,p,q,tep,c=0;
   if (x>h) 
      return(c);
   if (x==h)  
   {
      if (u!=1 || d<=res) 
         return(0);   
      j=1;    
      b[x]=d;
      if (d<a[x]) 
         for (j=1;j<=x;j++)  
            a[j]=b[j];           
      else
         if (d==a[x])
         {
            while (b[j]==a[j]) 
               j++;
            if (j>x) 
               return(1);
            if (b[j]<a[j])  
               for (j=1;j<=x;j++)  
                  a[j]=b[j];
         }
      return(1);
   }  
   for (i=res;;i++)
   { 
      if (d>u*i)
         continue; 
      if (d*(h-x+1)<u*i)
         return(c);
      b[x]=i;
      p=u*i-d;  
      q=d*i;  
      tep=gcd(p,q); 
      p/=tep; 
      q/=tep;    
      if (search(x+1,p,q,h,i+1))  
         c=1; 

   }
   if(c) 
      return(1);                  
}
long long gcd(long long a,long long b)
{
   if (b==0)
      return(a);
   return(gcd(b,a%b));
}
