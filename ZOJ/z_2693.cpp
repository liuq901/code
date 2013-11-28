#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   double calc(int);
   int time;
   scanf("%*s%d",&time);
   int n[3];
   scanf("%d%d%d%*c",&n[0],&n[1],&n[2]);
   double s=0;
   for (int i=0;i<3;i++)
      s+=calc(n[i]);
   scanf("%d%d%d%*c",&n[0],&n[1],&n[2]);
   double t=0;
   for (int i=0;i<3;i++)
      t+=calc(n[i]);
   if (s>=t)
      printf("Test %d: Yes\n",time);
   else
      printf("Test %d: No\n",time);
}
double calc(int n)
{
   char s[200];
   gets(s);
   int i=0;
   bool a[51];
   while (i/2<n)
   {
      if (s[i]=='W')
         a[i/2+1]=true;
      else
         a[i/2+1]=false;
      i+=2;
   }
   double x=0;
   i=1;
   while (i<=n && a[i]==a[1])
   {
      if (a[i])
         x++;
      else
         x--;
      i++;
   }
   long long k=2;
   while (i<=n)
   {
      if (a[i])
         x+=1.0/k;
      else
         x-=1.0/k;
      i++;
      k*=2;
   }
   return(x);
}
