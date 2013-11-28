#include <cstdio>
#include <cstdlib>
const int m=320;
struct data
{
   int s;
   int a[700];
   struct data *next;
};
struct data *head,*k;
int p;
int main()
{
   void destory(int);
   int find(int);
   char ch;
   int n,x,y,i,max;
   scanf("%d%d%*c",&max,&n);
   head=NULL;
   p=0;
   for (i=1;i<=n;i++)
   {
      scanf("%c%d%*c",&ch,&x);
      if (ch=='D')
      {
         destory(x);
         p++;
      }
      else
      {
         y=find(x);
         if (y>max)
            printf("0\n");
         else
            printf("%d\n",y);
      }
   }
   system("pause");
   return(0);
}
void destory(int x)
{
   void insert(int);
   int find(int);
   int t;
   t=find(x);
   insert(t);
}
void insert(int x)
{
   int i,t;
   struct data *k,*l;
   if (head==NULL)
   {
      head=(struct data *)malloc(sizeof(struct data));
      head->s=1;
      head->a[1]=x;
      head->next=NULL;
      return;
   }
   k=head;
   while (1)
   {
      if (x<=k->a[k->s])
         break;
      if (k->next==NULL)
         break;
      k=k->next;
   }
   if (x>=k->a[k->s])
   {
      k->s++;
      k->a[k->s]=x;
   }
   else
   {
      for (i=1;i<=k->s;i++)
         if (k->a[i]>=x)
         {
            t=i;
            break;
         }
      for (i=k->s;i>=t;i--)
         k->a[i+1]=k->a[i];
      k->a[t]=x;
      k->s++;
   }
   if (k->s>=2*m)
   {
      l=(struct data *)malloc(sizeof(struct data));
      l->s=k->s-m;
      for (i=1;i<=l->s;i++)
         l->a[i]=k->a[i+m];
      k->s=m;
      l->next=k->next;
      k->next=l;
   }
}
int find(int x)
{
   int search(int,int,int);
   return(search(x,x,x+p));
}
int search(int x,int l,int r)
{
   struct data *k;
   int s,mid,i;
   mid=(l+r)/2;
   s=0;
   k=head;
   while (1)
   {
      if (k==NULL)
         break;
      if (k->a[k->s]>=mid)
      {
         for (i=1;i<=k->s;i++)
         {
            if (k->a[i]==mid)
            {
               if (x+s<mid)
                  return(search(x,l,mid-1));
               return(search(x,mid+1,r));
            }
            if (k->a[i]<mid)
               s++;
         }
         break;
      }
      s+=k->s;
      k=k->next;
   }
   if (x+s==mid)
      return(mid);
   if (x+s<mid)
      return(search(x,l,mid-1));
   return(search(x,mid+1,r));
}
