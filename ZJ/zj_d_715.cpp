#include <cstdio>
#include <cstdlib>
const int a2[]={6,2,4,8},a3[]={1,3,9,7},a7[]={1,7,9,3},a9[]={1,9,1,9};
int main()
{
   int work(int);
   int n;
   while (scanf("%d",&n)==1)
      printf("%d\n",work(n));
   system("pause");
   return(0);
}
int s2,s3,s5,s7,s9;
int work(int n)
{
   void calc(int);
   if (n==1)
      return(1);
   s2=s3=s5=s7=s9=0;
   calc(n);
   return(a2[s2-s5&3]*a3[s3&3]*a7[s7&3]*a9[s9&3]%10);
}
void calc(int n)
{
   if (!n)
      return;
   for (int i=n;i;i/=5)
   {
      int p=i/10,q=i%10;
      s3+=p+(q>=3);
      s5+=p+(q>=5);
      s7+=p+(q>=7);
      s9+=p+(q>=9);
   }
   s2+=n>>1;
   calc(n>>1);
}
