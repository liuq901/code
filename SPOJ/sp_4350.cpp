#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=350;
struct data
{
   int s,max,a[701];
   data *next;
};
data *root;
int main()
{
   void insert(int,int);
   int get(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      char ch;
      int x,y;
      scanf("\n%c%d%d",&ch,&x,&y);
      if (ch=='A')
         insert(x,y);
      else
         printf("%d\n",get(x,y));
   }
   system("pause");
   return(0);
}
void insert(int x,int pos)
{
   if (root==NULL)
   {
      root=new(data);
      root->s=1;
      root->a[1]=root->max=x;
      return;
   }
   data *k=root;
   while (pos>k->s && k->next!=NULL)
   {
      pos-=k->s;
      k=k->next;
   }
   if (x>k->max)
      k->max=x;
   memmove(k->a+pos+1,k->a+pos,sizeof(int)*(k->s-pos+1));
   k->s++;
   k->a[pos]=x;
   if (k->s==2*m)
   {
      data *t=new(data);
      t->next=k->next;
      k->next=t;
      memcpy(t->a+1,k->a+m+1,sizeof(int)*m);
      t->s=k->s=m;
      t->max=k->max=-1<<30;
      for (int i=1;i<=m;i++)
      {
         if (t->a[i]>t->max)
            t->max=t->a[i];
         if (k->a[i]>k->max)
            k->max=k->a[i];
      }
   }
}
int get(int l,int r)
{
   int ans=-1<<30;
   data *k=root;
   while (k->s<l)
   {
      l-=k->s;
      r-=k->s;
      k=k->next;
   }
   if (r<=k->s)
   {
      for (int i=l;i<=r;i++)
         if (k->a[i]>ans)
            ans=k->a[i];
      return(ans);
   }
   for (int i=l;i<=k->s;i++)
      if (k->a[i]>ans)
         ans=k->a[i];
   r-=k->s;
   k=k->next;
   while (r>k->s)
   {
      r-=k->s;
      if (k->max>ans)
         ans=k->max;
      k=k->next;
   }
   for (int i=1;i<=r;i++)
      if (k->a[i]>ans)
         ans=k->a[i];
   return(ans);
}
