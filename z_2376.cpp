#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int l,n,ans0,ans1;
      scanf("%d%d",&l,&n);
      ans0=ans1=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         int p,q;
         p=x,q=l-x;
         if (p>q)
         {
            int t;
            t=p,p=q,q=t;
         }
         if (p>ans0)
            ans0=p;
         if (q>ans1)
            ans1=q;
      }
      printf("%d %d\n",ans0,ans1);
   }
   system("pause");
   return(0);
}
