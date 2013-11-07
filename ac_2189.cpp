#include <cstdio>
#include <cstdlib>
int a[100010];
int main()
{
   void print(int,int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      static int id=0;
      printf("Case %d:\n",++id);
      int l,r;
      l=r=a[1];
      for (int i=2;i<=n;i++)
      {
         if (a[i]==a[i-1]+1)
         {
            r=a[i];
            continue;
         }
         print(l,r);
         l=r=a[i];
      }
      print(l,r);
      printf("\n");
   }
   system("pause");
   return(0);
}
void print(int l,int r)
{
   if (l==r)
   {
      printf("0%d\n",l);
      return;
   }
   printf("0%d-",l);
   int p=0,q=1;
   while (l!=r)
   {
      p+=r%10*q;
      l/=10,r/=10;
      q*=10;
   }
   printf("%d\n",p);
}
