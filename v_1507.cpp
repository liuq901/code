#include <cstdio>
#include <cstdlib>
#include <cmath>
struct biao
{
   int s;
   int a[700];
   struct biao *next;
};
struct biao *root,*k;
int m;
int main()
{
   void add(int);
   int min(int,int),del(int),find(int,int);
   int i,n,p,q,x,y,t,sum;
   char ch;
   scanf("%d%d%*c",&n,&p);
   q=t=sum=0;
   m=min((int)sqrt(n),(int)sqrt(100000));
   root=NULL;
   for (i=1;i<=n;i++)
   {
      scanf("%c%d%*c",&ch,&x);
      if (ch=='I')
      {
         if (x+q<p)
            continue;
         t++;
         add(x+q);
      }
      else if (ch=='A')
      {
         p-=x;
         q-=x;
      }
      else if (ch=='S')
      {
         p+=x;
         q+=x;
         if (root!=NULL)
         {
            y=del(p);
            sum+=y;
            t-=y;
         }
      }
      else if (x>t)
         printf("-1\n");
      else
         printf("%d\n",find(t-x+1,q));
      k=root;
   }
   printf("%d\n",sum);
   system("pause");
   return(0);
}
void add(int x)
{
   int i,p,flag;
   struct biao *k,*t;
   if (root==NULL)
   {
      root=(struct biao *)malloc(sizeof(struct biao));
      root->s=1;
      root->a[1]=x;
      root->next=NULL;
      return;
   }
   k=root;
   flag=1;
   while (1)
   {
      if (x<=k->a[k->s])
         break;
      if (k->next==NULL)
      {
         flag=0;
         k->s++;
         k->a[k->s]=x;
         break;
      }
      k=k->next;
   }
   if (flag)
   {
      for (i=1;i<=k->s;i++)
         if (x<=k->a[i])
         {
            p=i;
            break;
         }
      for (i=k->s;i>=p;i--)
         k->a[i+1]=k->a[i];
      k->a[p]=x;
      k->s++;
   }
   if (k->s==2*m)
   {
      t=(struct biao *)malloc(sizeof(struct biao));
      for (i=1;i<=m;i++)
         t->a[i]=k->a[m+i];
      t->s=m;
      t->next=k->next;
      k->s=m;
      k->next=t;
   }
}
int del(int x)
{
   int i,t,p;
   t=0;
   while (root->a[root->s]<x)
   {
      t+=root->s;
      root=root->next;
      if (root==NULL)
         return(t);
   }
   for (i=1;i<=root->s;i++)
      if (root->a[i]>=x)
      {
         p=i;
         break;
      }
   t+=p-1;
   for (i=p;i<=root->s;i++)
      root->a[i-p+1]=root->a[i];
   root->s-=p-1;
   return(t);
}
int find(int x,int y)
{
   struct biao *k;
   k=root;
   while (x>k->s)
   {
      x-=k->s;
      k=k->next;
   }
   return(k->a[x]-y);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
