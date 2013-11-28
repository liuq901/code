#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int x,c;
   struct data *next,*tail,*opp;
};
struct data *a[56000];
int n,b[56000];
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   struct data *add(int,int,int,int);
   int build(),dinic(int,int);
   int i,x,y,z,m,s,ans;
   memset(a,0,sizeof(a));
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      add(0,i,x,0);
   }
   s=0;
   for (i=1;i<=m;i++)
   {
      scanf("%d%d%d",&x,&y,&z);
      add(x,i+n,20000000,0);
      add(y,i+n,20000000,0);
      add(i+n,n+m+1,z,0);
      s+=z;
   }
   n+=m+1;
   ans=0;
   while (build())
      ans+=dinic(0,20000000);
   printf("%d\n",s-ans);
}
struct data *add(int x,int y,int z,int flag)
{
   struct data *k;
   if (a[x]==NULL)
   {
      a[x]=(struct data *)malloc(sizeof(struct data));
      a[x]->x=y;
      a[x]->c=z;
      a[x]->next=NULL;
      a[x]->tail=a[x];
   }
   else
   {
      k=a[x]->tail;
      k->next=(struct data *)malloc(sizeof(struct data));
      k=k->next;
      k->x=y;
      k->c=z;
      k->next=NULL;
      a[x]->tail=k;
   }
   if (flag)
      return(a[x]->tail);
   else
   {
      k=add(y,x,0,1);
      a[x]->tail->opp=k;
      k->opp=a[x]->tail;
   }
}
int build()
{
   struct data *k;
   int l,r;
   int f[56000],q[56000];
   memset(f,0,sizeof(f));
   f[0]=1,q[1]=0,b[0]=0;
   l=r=1;
   while (1)
   {
      k=a[q[l]];
      while (k!=NULL)
      {
         if (!f[k->x] && k->c!=0)
         {
            r++;
            q[r]=k->x;
            b[k->x]=b[q[l]]+1;
            f[k->x]=1;
            if (k->x==n)
               return(1);
         }
         k=k->next;
      }
      l++;
      if (l>r)
         break;
   }
   return(0);
}
int dinic(int x,int flow)
{
   int min(int,int);
   int s,t,y;
   struct data *k;
   if (x==n)
      return(flow);
   k=a[x];
   s=0;
   y=flow;
   while (k!=NULL)
   {
      if (b[x]+1==b[k->x] && k->c!=0)
      {
         t=dinic(k->x,min(k->c,y));
         k->c-=t;
         k->opp->c+=t;
         s+=t;
         y-=t;
         if (y==0)
            return(flow);
      }
      k=k->next;
   }
   if (s==0)
      b[x]=-1;
   return(s);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
