#include <cstdio>
#include <cstdlib>
int s[1000001];
int main()
{
   void init();
   init();
   int a,b;
   while (scanf("%d%d",&a,&b)!=EOF)
      printf("%d\n",s[b]-s[a-1]);
   system("pause");
   return(0);
}
bool f[1000001];
void init()
{
   f[0]=f[1]=true;
   for (int i=2;i<=1000000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;j<=1000000/i;j++)
         f[i*j]=true;
   }
   for (int i=1;i<=1000000;i++)
      s[i]=s[i-1]+1-f[i];
}
