#include <cstdio>
#include <cstdlib>
int n,c[500001];
int main()
{
   void insert(int,int);
   int count(int);
   int m;
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=m;i++)
   {
      char ch;
      scanf("%c",&ch);
      if (ch=='A')
      {
         int x;
         scanf("%d",&x);
         printf("%d\n",count(x));
      }
      else
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (ch=='B')
            insert(x,y);
         else
            insert(x,-y);
      }
      scanf("%*c");
   }
   system("pause");
   return(0);
}
void insert(int x,int value)
{
   for (int i=x;i<=n;i+=i&-i)
      c[i]+=value;
}
int count(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
