#include <cstdio>
#include <cstdlib>
struct tree
{
   int t0,t1,num;
   struct tree *next,*father,*son;
};
int a[6001];
int main()
{
   void count(struct tree *);
   int max(int,int);
   struct tree *root,*k;
   struct tree *f[6001];
   int i,n,x,y;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      f[i]=(struct tree *)malloc(sizeof(struct tree));
      f[i]->t0=0;
      f[i]->t1=0;
      f[i]->num=i;
      f[i]->next=NULL;
      f[i]->father=NULL;
      f[i]->son=NULL;
   }
   if (n==1)
      printf("%d\n",a[1]);
   else
   {
      while (1)
      {
         scanf("%d%d",&x,&y);
         if (x==y && x==0)
            break;
         f[x]->father=f[y];
         if (f[y]->son==NULL)
            f[y]->son=f[x];
         else
         {
            k=f[y]->son;
            while (1)
            {
               if (k->next==NULL)
                  break;
               k=k->next;
            }
            k->next=f[x];
         }
      } 
      k=f[1];
      while (1)
      {
         if (k->father==NULL)
            break;
         k=k->father;
      }
      root=k;
      count(root);
      printf("%d\n",max(root->t0,root->t1));
   }
   system("pause");
   return(0);
}
void count(struct tree *t)
{
   int max(int,int);
   struct tree *k;
   if (t->son==NULL)
   {
      if (a[t->num]>0)
         t->father->t0+=a[t->num];
      return;
   }
   k=t->son;
   while (1)
   {
      count(k);
      if (max(k->t0,k->t1)>0)
         k->father->t0+=max(k->t0,k->t1);    
      if (k->t0>0)
         k->father->t1+=k->t0;
      if (k->next==NULL)
         break;
      k=k->next;
   }
   t->t1+=a[t->num];
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
