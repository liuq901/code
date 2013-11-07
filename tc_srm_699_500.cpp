#include <cstdio>
#include <cstdlib>
struct DiceRotation
{
   int theCount(int x,int y)
   {
      int s1,s2,s3;
      s1=x==4?y+1:0;
      s2=y==4?x+1:0;
      s3=x!=1 && y!=1?2:0;
      return(s1+s2+s3);
   }
};
int main()
{
   int a,b;
   scanf("%d%d",&a,&b);
   DiceRotation p;
   printf("%d\n",p.theCount(a,b));
   system("pause");
   return(0);
}
