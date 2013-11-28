#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[200010],c[200010];
int main()
{
   void insert(int,int);
   int find(int);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      memset(c,0,sizeof(c));
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         insert(i,a[i]);
      }
      static int id=0;
      if (id)
         printf("\n");
      printf("Case %d:\n",++id);
      while (1)
      {
         char s[10];
         scanf("%s",s);
         if (s[0]=='E')
            break;
         int x,y;
         scanf("%d%d",&x,&y);
         if (s[0]=='S')
         {
            insert(x,y-a[x]);
            a[x]=y;
         }
         else
            printf("%d\n",find(y)-find(x-1));
      }
   }
   system("pause");
   return(0);
}
void insert(int x,int y)
{
   for (int i=x;i<=n;i+=i&-i)
      c[i]+=y;
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
