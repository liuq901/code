#include <cstdio>
#include <cstdlib>
const int c[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int main()
{
   void work();
   int t,i;
   scanf("%d%*c",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int i,s,x,y,p,q;
   char a,b;
   scanf("%c%c%*c",&a,&b);
   x=a-'a'+1;
   y=b-'0';
   s=0;
   for (i=0;i<8;i++)
   {
      p=x+c[i][0];
      q=y+c[i][1];
      if (p>=1 && p<=8 && q>=1 && q<=8)
         s++;
   }
   printf("%d\n",s);
}
