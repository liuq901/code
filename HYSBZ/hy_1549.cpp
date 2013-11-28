#include <cstdio>
#include <cstdlib>
#include <cstring>
const int max=20000000;
struct data
{
   int p,c,y;
   struct data *next;
};
struct data *b[20026];
int ans,n,m,s,p[20026],q[1000000],a[200][200];
int main()
{
   void build(int),work();
   int i,j;
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      for (j=1;j<=m+i-1;j++)
         scanf("%d",&a[i][j]);
   memset(b,0,sizeof(b));
   build(0);
   ans=0;
   work();
   printf("%d\n",ans);
   memset(b,0,sizeof(b));
   build(1);
   ans=0;
   work();
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void build(int flag)
{
   int count(int,int,int);
   void insert(int,int,int,int,int);
   int i,j,k,t,l;
   for (i=1;i<=n-1;i++)
      for (j=1;j<=m+i-1;j++)
      {
         t=count(i,j,m);
         if (!flag)
            k=1;
         else
            k=max;
         insert(t,t+1,k,a[i][j],0);
         insert(t+1,count(i+1,j,m),1,0,0);
         insert(t+1,count(i+1,j+1,m),1,0,0);
      }
   for (i=1;i<=m;i++)
      insert(0,2*i-1,max,0,0);
   l=(2*m+n-1)*n+1;
   s=l;
   for (i=1;i<=m+n-1;i++)
   {
      if (!flag)
         k=1;
      else
         k=max;
      t=count(n,i,m);
      insert(t,t+1,k,a[n][i],0);
      insert(t+1,l,max,0,0);
   }
}
int count(int i,int j,int m)
{
   return((2*m+i-2)*(i-1)+2*j-1);
}
void insert(int x,int y,int c,int p,int flag)
{
   struct data *k;
   if (b[x]==NULL)
   {
      b[x]=(struct data *)malloc(sizeof(struct data));
      b[x]->p=p;
      b[x]->c=c;
      b[x]->y=y;
      b[x]->next=NULL;
      if (!flag)
         insert(y,x,0,-p,1);
      return;
   }
   k=b[x];
   while (1)
   {
      if (k->next==NULL)
         break;
      k=k->next;
   }
   k->next=(struct data *)malloc(sizeof(struct data));
   k=k->next;
   k->p=p;
   k->c=c;
   k->y=y;
   k->next=NULL;
   if (!flag)
      insert(y,x,0,-p,1);
}
void work()
{
   int spfa();
   void flow();
   int i,j;
   for (i=1;i<=m;i++)
   {
      ans+=spfa();
      flow();
   }
}
int spfa()
{
   struct data *k;
   int l,r;
   int f[20026];
   memset(f,26,sizeof(f));
   memset(p,26,sizeof(p));
   f[0]=0;
   q[1]=0;
   p[0]=0;
   l=r=1;
   while (1)
   {
      k=b[q[l]];
      while (1)
      {
         if (k==NULL)
            break;
         if (k->c!=0 && f[q[l]]+k->p<f[k->y])
         {
            f[k->y]=f[q[l]]+k->p;
            r++;
            q[r]=k->y;
            p[k->y]=q[l];
         }
         k=k->next;
      }
      l++;
      if (l>r)
         break;
   }
   return(f[s]);
}
void flow()
{
   struct data *k;
   int t,x;
   t=s;
   while (1)
   {
      if (t==0)
         break;
      x=p[t];
      k=b[x];
      while (1)
      {
         if (k==NULL)
            break;
         if (k->y==t)
         {
            k->c--;
            break;
         }
         k=k->next;
      }
      k=b[t];
      while (1)
      {
         if (k==NULL)
            break;
         if (k->y==x)
         {
            k->c++;
            break;
         }
         k=k->next;
      }
      t=x;
   }
}
