#include <cstdio>
#include <cstdlib>
int main()
{
   const char a[]=" 0123456789ABCDEFGHIJ";
   char b[100];
   int n,r,y,t,i,j,n1;
   while (1)
   {
      scanf("%d%d",&n,&r);
      i=1;
      b[i]='0';
      n1=n;
      while (n!=0)
      {
         if (n>=(n/r)*r)
         {
            y=n-(n/r)*r;
            n/=r;
         }
         else
         {
            y=n-(n/r+1)*r;
            n=n/r+1;
         }
         b[i]=a[y+1];
         i++;
      }
      if (n1==0 && r==t)
         break;
      printf("%d=",n1);
      for (j=i-1;j>=1;j--)
         printf("%c",b[j]);
      printf("(base %d)\n",r);
      t=r;
   }
   system("pause");
   return(0);
}
