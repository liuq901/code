#include <cstdio>
#include <cstdlib>
bool f[1000010];
int main()
{
   void work(int);
   for (int i=1;i<=1000000;i++)
      work(i);
   for (int i=1;i<=1000000;i++)
      if (!f[i])
         printf("%d\n",i);
   system("pause");
   return(0);
}
void work(int x)
{
   int s=x;
   while (x)
   {
      s+=x%10;
      x/=10;
   }
   if (s<=1000000)
      f[s]=true;
}
