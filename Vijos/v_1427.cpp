#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   int f,s,l;
};
struct tree a[10001];
int n;
int main()
{
   void build(),work(int,int);
   int i,j,s,t,x;
   char st[256];
   scanf("%d%d%d",&n,&s,&t);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d %s",&j,&x,st);
      a[j].f=x;
      a[j].s=0;
      a[j].l=strlen(st);
   }
   a[0].f=-1;
   a[0].s=0;
   a[0].l=0;
   build();
   work(s,t);
   system("pause");
   return(0);
}
void build()
{
   int i,t;
   struct data *k;
   for (i=1;i<=n;i++)
   {
      t=a[i].f;
      a[t].s++;
   }
}
void work(int s,int t)
{
   int x,k,length,time;
   int flag[10001];
   length=time=0;
   x=s;
   memset(flag,0,sizeof(flag));
   flag[s]=1;
   while (x!=0)
   {
      x=a[x].f;
      flag[x]=1;
   }
   x=t;
   while (flag[x]==0)
      x=a[x].f;
   if (x==s)
   {
      k=t;
      while (k!=s)
      {
         length+=a[k].l;
         time+=a[k].s;
         k=a[k].f;
      }
      length+=a[s].l;
      time-=a[t].s;
   }
   else if (x==t)
   {
      k=s;
      while (k!=t)
      {
         length+=a[k].l;
         time+=a[k].s;
         k=a[k].f;
      }
      length+=a[t].l;
      time+=a[t].s;
      time-=a[s].s;
   }
   else
   {
      k=s;
      while (k!=x)
      {
         length+=a[k].l;
         time+=a[k].s;
         k=a[k].f;
      }
      k=t;
      while (k!=x)
      {
         length+=a[k].l;
         time+=a[k].s;
         k=a[k].f;
      }
      length+=a[x].l;
      time+=a[x].s;
      time-=a[s].s;
      time-=a[t].s;
   }
   printf("%d\n",length);
   printf("%d\n",time);
}
