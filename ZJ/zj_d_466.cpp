#include <cstdio>
#include <cstdlib>
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
   bool check(int);
   int y,m,d;
   while (scanf("%d%d%d",&y,&m,&d)!=EOF)
   {
      if (check(y))
         a[2]=29;
      else
         a[2]=28;
      if (y<=0 || m<=0 || d<=0 || m>12 || d>a[m])
      {
         printf("Error\n"); 
         continue;
      }
      int s=d;
      for (int i=1;i<m;i++)
         s+=a[i];
      if (s==1)
         printf("It is 1 day in %d\n",y);
      else
         printf("It is %d days in %d\n",s,y);
   }
   system("pause");
   return(0);
}
bool check(int x)
{
   return(!(x%400) || x%100 && !(x%4));
}
