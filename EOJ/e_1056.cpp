#include <cstdio>
#include <cstdlib>
int ans[100000];
int main()
{
   int gcd(int,int,int &,int &);
   int a,b,m;
   while (scanf("%d%d%d",&a,&b,&m)==3)
   {
      int p,q,t=gcd(a,m,p,q);
      if (b%t)
      {
         printf("No Answer.\n");
         continue;
      }
      a/=t,b/=t,m/=t;
      gcd(a,m,p,q);
      p*=b;
      p%=m;
      if (p<0)
         p+=m;
      q=0;
      while (1)
      {
         ans[++q]=p;
         p+=m;
         if (p>=m*t)
            break;
      }
      for (int i=1;i<q;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[q]);
   }
   system("pause");
   return(0);
}
int gcd(int a,int b,int &x,int &y)
{
   if (!b)
   {
      x=1,y=0;
      return(a);
   }
   int p,q,t=gcd(b,a%b,p,q);
   x=q,y=p-(a/b)*q;
   return(t);
}
