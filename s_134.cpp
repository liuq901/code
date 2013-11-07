#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int x;
   struct data *next,*tail;
};
struct data *a[40000];
int n,ans[40000],f[40000];
int main()
{
   int search(int);
   int i,x,y,min,max;
   int b[40000];
   struct data *k;
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   max=0;
   for (i=1;i<=n-1;i++)
   {
      scanf("%d%d",&x,&y);
      if (x>max)
         max=x;
      if (y>max)
         max=y;
      if (a[x]==NULL)
      {
         a[x]=(struct data *)malloc(sizeof(struct data));
         a[x]->x=y;
         a[x]->next=NULL;
         a[x]->tail=a[x];
      }
      else
      {
         k=a[x]->tail;
         k->next=(struct data *)malloc(sizeof(struct data));
         k=k->next;
         k->x=y;
         k->next=NULL;
         a[x]->tail=k;
      }
      if (a[y]==NULL)
      {
         a[y]=(struct data *)malloc(sizeof(struct data));
         a[y]->x=x;
         a[y]->next=NULL;
         a[y]->tail=a[y];
      }
      else
      {
         k=a[y]->tail;
         k->next=(struct data *)malloc(sizeof(struct data));
         k=k->next;
         k->x=x;
         k->next=NULL;
         a[y]->tail=k;
      }
   }
   memset(ans,26,sizeof(ans));
   memset(f,0,sizeof(f));
   f[max]=1;
   search(max);
   b[0]=0;
   min=20000000;
   for (i=0;i<=max;i++)
   {
      if (ans[i]==min)
      {
         b[0]++;
         b[b[0]]=i;
      }
      if (ans[i]<min)
      {
         min=ans[i];
         b[0]=1;
         b[b[0]]=i;
      }
   }
   printf("%d %d\n",min,b[0]);
   for (i=1;i<b[0];i++)
      printf("%d ",b[i]);
   printf("%d\n",b[b[0]]);
   system("pause");
   return(0);
}
int search(int x)
{
   int s,t;
   struct data *k;
   k=a[x];
   s=0;
   ans[x]=0;
   while (k!=NULL)
   {
      if (!f[k->x])
      {
         f[k->x]=1;
         t=search(k->x);
         if (t>ans[x])
            ans[x]=t;
         s+=t;
      }
      k=k->next;
   }
   s++;
   if (n-s>ans[x])
      ans[x]=n-s;
   return(s);
}
