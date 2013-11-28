#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1010],l[1010],r[1010];
int main()
{
   void insert(int,int,int),print(int);
   int n;
   while (scanf("%d",&n)==1)
   {
      memset(l,0,sizeof(l));
      memset(r,0,sizeof(r));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (i==1)
            a[1]=x;
         else
            insert(1,x,i);
      }
      print(1);
      printf("\n");
   }
   system("pause");
   return(0);
}
void insert(int x,int value,int id)
{
   if (value<a[x])
   {
      if (!l[x])
      {
         l[x]=id;
         a[id]=value;
         return;
      }
      insert(l[x],value,id);
   }
   else
   {
      if (!r[x])
      {
         r[x]=id;
         a[id]=value;
         return;
      }
      insert(r[x],value,id);
   }
}
void print(int x)
{
   if (!x)
      return;
   if (x!=1)
      printf(" ");
   printf("%d",a[x]);
   print(l[x]);
   print(r[x]);
}
