#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int x;
   struct data *next,*tail;
};
int main()
{
   void did();
   int t;
   scanf("%d",&t);
   while (t--)
      did();
   system("pause");
   return(0);
}
struct data *a[100001];
int n,c[100001],h[100001],g[100001],f[100001],b[500001];
void did()
{
   void build(int,int),work(),maintain(int),insert(int);
   int k,q,i,t,x,ans;
   scanf("%d%d%d",&n,&k,&q);
   memset(a,0,sizeof(a));
   for (i=1;i<=q;i++)
   {
      scanf("%d",&b[i]);
      build(b[i],i);
   }
   for (i=1;i<=n;i++)
      build(i,20000000);
   ans=0;
   memset(f,0,sizeof(f));
   i=t=0;
   while (t<k)
   {
      i++;
      if (i>q)
         break;
      if (!f[b[i]])
      {
         ans++;
         t++;
         f[b[i]]=1;
      }
      a[b[i]]=a[b[i]]->next;
   }
   work();
   t=i+1;
   for (i=t;i<=q;i++)
   {
      a[b[i]]=a[b[i]]->next;
      if (f[b[i]])
      {
         h[c[b[i]]]=a[b[i]]->x;
         maintain(c[b[i]]);
         continue;
      }
      ans++;
      insert(b[i]);
   }
   printf("%d\n",ans);
}
void build(int x,int t)
{
   if (a[x]==NULL)
   {
      a[x]=(struct data *)malloc(sizeof(struct data));
      a[x]->x=t;
      a[x]->next=NULL;
      a[x]->tail=a[x];
      return;
   }
   a[x]->tail->next=(struct data *)malloc(sizeof(struct data));
   a[x]->tail=a[x]->tail->next;
   a[x]->tail->x=t;
   a[x]->tail->next=NULL;
}
void work()
{
   void maintain(int);
   int i;
   h[0]=0;
   for (i=1;i<=n;i++)
   {
      if (!f[i])
         continue;
      h[0]++;
      h[h[0]]=a[i]->x;
      g[h[0]]=i;
      c[i]=h[0];
      maintain(h[0]);
   }
}
void maintain(int x)
{
   int t;
   if (x==1 || h[x]<h[x/2])
      return;
   t=h[x],h[x]=h[x/2],h[x/2]=t;
   t=g[x],g[x]=g[x/2],g[x/2]=t;
   c[g[x]]=x;
   c[g[x/2]]=x/2;
   maintain(x/2);
}
void insert(int x)
{
   void down(int);
   f[g[1]]=0;
   f[x]=1;
   h[1]=a[x]->x;
   g[1]=x;
   c[x]=1;
   down(1);
}
void down(int x)
{
   int t,k;
   t=h[x];
   if (2*x<=h[0] && h[2*x]>t)
      t=h[2*x];
   if (2*x+1<=h[0] && h[2*x+1]>t)
      t=h[2*x+1];
   if (t==h[x])
      return;
   if (t==h[2*x])
   {
      k=h[x],h[x]=h[2*x],h[2*x]=k;
      k=g[x],g[x]=g[2*x],g[2*x]=k;
      c[g[x]]=x;
      c[g[2*x]]=2*x;
      down(2*x);
   }
   else
   {
      k=h[x],h[x]=h[2*x+1],h[2*x+1]=k;
      k=g[x],g[x]=g[2*x+1],g[2*x+1]=k;
      c[g[x]]=x;
      c[g[2*x+1]]=2*x+1;
      down(2*x+1);
   }
}
