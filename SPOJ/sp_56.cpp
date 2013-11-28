#include <cstdio>
#include <cstdlib>
char s[20010];
int ans,deap,sum,now;
int main()
{
   void work(int);
   for (int test=1;test<=10;test++)
   {
      scanf("%*d\n%s",s);
      sum=deap=now=ans=0;
      work(0);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void work(int dep)
{
   if (dep>deap)
   {
      deap=dep;
      ans=sum;
   }
   if (s[now++]=='1')
   {
      sum++;
      work(dep+1);
      work(dep+1);
   }
}
