#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n,x0,y0,x1,y1;
      scanf("%d%d%d%d%d",&n,&x0,&y0,&x1,&y1);
      if (!n)
         break;
      static int id=0;
      printf("Case %d:\n",++id);
      int m=(n<<1)-1;
      for (int i=x0;i<=x1;i++)
      {
         int k=abs(n-i%m-1);
         for (int j=y0;j<=y1;j++)
         {
            int l=abs(n-j%m-1);
            if (k+l>=n)
               printf(".");
            else
            {
               int x=(k+l)%26;
               printf("%c",'a'+x);
            }
         }
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
