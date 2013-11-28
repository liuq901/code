#include <cstdio>
#include <cstdlib>
int ans,n,t;
main()
{
   void search(int),test(int,int,int);
   int id;
   while (scanf("%d",&id)!=EOF)
      while (id--)
      {
         scanf("%d",&n);
         ans=0;
         t=(1<<n)-1;
         test(0,0,0);
         printf("%d\n",ans);
      }
   system("pause");
   return(0);
}
void test(int x,int y,int z)
{
   int pos,p;
   if (x!=t)
   {
      pos=~(x|y|z)&t;
      while (pos!=0)
      {
         p=pos&(~pos+1);
         pos-=p;
         test(x+p,(y+p)<<1,(z+p)>>1);
      }
   }
   else
      ans++;
}
