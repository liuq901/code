#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int main()
{
   int i,j,k,top,n,*result,temp,sum,prime;
   char a[6];
   int ar[100];
   result=ar;
   result[0]=1;
   for (i=1;i<100;i++) 
      result[i]=0;
   top=sum=0;
   scanf("%d",&n);
   for (i=1,j=n;i<j;i++,j--)
   {
      temp=i*j;
      for (k=0;k<=top;k++)  
         result[k]*=temp;
         for (k=0;k<=top;k++)
            if (result[k]>=10000)
            {
               result[k+1]+=result[k]/10000; 
               if (k+1>top) 
                  top=k+1;
               result[k]%=10000;
            }
   }
   if (n&1==1)
   {
      for (k=0;k<=top;k++)  
         result[k]*=i;
         for (k=0;k<=top;k++)
            if (result[k]>=10000)
            {
               result[k+1]+=result[k]/10000; 
               if (k+1>top) 
                  top=k+1;
               result[k]%=10000;
            }
   }
   for (i=0;i<=top;i++)
   {
      itoa(result[i],a,10);
      k=strlen(a);
      for (j=0;j<k;j++) 
         sum+=a[j]-'0';
   }
   prime=1;
   k=(int)sqrt(sum);
   if (sum&1==0 && sum>2) 
      prime=0;
   else
      for (i=3;i<=k;i+=2)
         if (sum%i==0) 
         { 
            prime=0;
            break;
         }    
   printf("%d",sum);
   if (prime) 
      printf("T\n");
   else 
      printf("F\n");
   system("pause");
   return(0);
}
