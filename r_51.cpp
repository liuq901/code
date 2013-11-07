#include <cstdio>
#include <cstdlib>
int n,a[100000];
int main()
{
   void work(int);
   char ch;
   n=0;
   while (1)
   {
      scanf("%c",&ch);
      if (ch=='E')
         break;
      if (ch=='W')
      {
         n++;
         a[n]=1;
      }
      if (ch=='L')
      {
         n++;
         a[n]=0;
      }
   }
   work(11);
   printf("\n");
   work(21);
   system("pause");
   return(0);
}
void work(int t)
{
   int x,y,i;
   x=y=0;
   for (i=1;i<=n;i++)
   {
      if (a[i])
         x++;
      else
         y++;
      if ((x>=t || y>=t) && abs(x-y)>=2)
      {
         printf("%d:%d\n",x,y);
         x=y=0;
      }
   }
   printf("%d:%d\n",x,y);
}
