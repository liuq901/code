#include <cstdio>
#include <cstdlib>
const int m=320;
struct data
{
   int s;
   int a[700];
   struct data *next;
};
struct data *head;
int main()
{
   void insert(int),del(int);
   int find(int,int);
   int t,k;
   long long ans;
   double x;
   char ch;
   ans=0;
   while (1)
   {
      scanf("%c",&ch);
      if (ch=='B')
      {
         scanf("%*c%*c%*c%lf%*c",&x);
         t=(int)(x*100+0.5);
         insert(t);
      }
      else if (ch=='D')
      {
         scanf("%*c%*c%*c%lf%*c",&x);
         t=(int)(x*100+0.5);
         del(t);
      }
      else if (ch=='S')
      {
         scanf("%*c%*c%*c%*c%lf%d%*c",&x,&k);
         t=(int)(x*100+0.5);
         ans+=find(t,k);
      }
      else
         break;
   }
   x=(double)ans/100.0;
   printf("%.2lf\n",x);
   system("pause");
   return(0);
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
      if (k->a[k->s]>=x)
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
void del(int x)
{
   int i,t;
   struct data *k;
   k=head;
   while (1)
   {
      if (x>=k->a[1] && x<=k->a[k->s])
         break;
      k=k->next;
   }
   for (i=1;i<=k->s;i++)
      if (k->a[i]==x)
      {
         t=i;
         break;
      }
   for (i=t;i<=k->s-1;i++)
      k->a[i]=k->a[i+1];
   k->s--;
}
int find(int x,int y)
{
   int i,s;
   struct data *k;
   k=head;
   s=0;
   if (head==NULL)
      return(0);
   k=head;
   while (1)
   {
      if (k->a[k->s]>=x)
         break;
      if (k->next==NULL)
         break;
      k=k->next;
   }
   for (i=1;i<=k->s;i++)
   {
      if (k->a[i]>=x)
         s++;
      if (s>=y)
         return(y);
   }
   while (1)
   {
      if (k->next==NULL)
         break;
      k=k->next;
      s+=k->s;
      if (s>=y)
         return(y);
   }
   return(s);
}
