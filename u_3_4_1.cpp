/*
ID: liuq9011
LANG: C++
TASK: fence4
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
FILE *in,*out;
struct point
{
   double x,y;
};
struct line
{
   struct point *a,*b;
};
int n,f[201];
struct point *p0,*p[201];
int main()
{
   void init(),work();
   in=fopen("fence4.in","r");
   out=fopen("fence4.out","w");
   init();
   work();
   fclose(in),fclose(out);
   return(0);
}
void init()
{
   int i;
   fscanf(in,"%d",&n);
   p0=(struct point *)malloc(sizeof(struct point));
   fscanf(in,"%lf%lf",&p0->x,&p0->y);
   for (i=1;i<=n;i++)
   {
      p[i]=(struct point *)malloc(sizeof(struct point));
      fscanf(in,"%lf%lf",&p[i]->x,&p[i]->y);
   }
}
void work()
{
   int cut(struct line *,struct line *,int),check(struct line *);
   int i,j,s;
   struct line *u,*v;
   struct line *ans[201];
   u=(struct line *)malloc(sizeof(struct line));
   v=(struct line *)malloc(sizeof(struct line));
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n-1;j++)
      {
         u->a=p[i];
         u->b=p[i+1];
         v->a=p[j];
         v->b=p[j+1];
         if (cut(u,v,0))
         {
            fprintf(out,"NOFENCE\n");
            return;
         }
      }
   u->a=p[n];
   u->b=p[1];
   for (i=1;i<=n-1;i++)
   {
      v->a=p[i];
      v->b=p[i+1];
      if (cut(u,v,0))
      {
         fprintf(out,"NOFENCE\n");
         return;
      }
   }
   memset(f,0,sizeof(f));
   s=0; 
   for (i=1;i<=n-2;i++)
   {
      v->a=p[i];
      v->b=p[i+1];
      f[i]=1;
      if (check(v))
      {
         s++;
         ans[s]=(struct line *)malloc(sizeof(struct line));
         ans[s]->a=v->a;
         ans[s]->b=v->b;
      }
      f[i]=0;
   }
   v->a=p[1];
   v->b=p[n];
   f[n]=1;
   if (check(v))
   {
      s++;
      ans[s]=(struct line *)malloc(sizeof(struct line));
      ans[s]->a=v->a;
      ans[s]->b=v->b;
   }
   f[n]=0;
   v->a=p[n-1];
   v->b=p[n];
   f[n-1]=1;
   if (check(v))
   {
      s++;
      ans[s]=(struct line *)malloc(sizeof(struct line));
      ans[s]->a=v->a;
      ans[s]->b=v->b;
   }
   f[n-1]=0;
   fprintf(out,"%d\n",s);
   for (i=1;i<=s;i++)
      fprintf(out,"%.0lf %.0lf %.0lf %.0lf\n",ans[i]->a->x,ans[i]->a->y,ans[i]->b->x,ans[i]->b->y);
}
int check(struct line *v)
{
   double len(struct line *);
   struct point *middle(struct line *);
   int cut(struct line *,struct line *,int);
   int i,fa,fb,fc;
   struct line *a0,*b0,*c0,*temp;
   if (len(v)<0.01)
      return(0);
   a0=(struct line *)malloc(sizeof(struct line));
   b0=(struct line *)malloc(sizeof(struct line));
   c0=(struct line *)malloc(sizeof(struct line));
   temp=(struct line *)malloc(sizeof(struct line));
   a0->a=v->a;
   a0->b=p0;
   b0->a=v->b;
   b0->b=p0;
   c0->a=middle(v);
   c0->b=p0;
   fa=1;
   fb=1;
   fc=1;
   for (i=1;i<=n;i++)
      if (!f[i])
      {
         temp->a=p[i];
         if (i==n)
            temp->b=p[1];
         else
            temp->b=p[i+1];
         if (cut(a0,temp,1) && cut(b0,temp,1))
            return(0);
         fa=!cut(a0,temp,0)&fa;
         fb=!cut(b0,temp,0)&fb;
         fc=!cut(c0,temp,1)&fc;
      }
   if (fc)
      return(1);
   if (!fa && !fb && !fc)
      return(0);
   if (fa)
   {
      temp->a=v->a;
      temp->b=c0->a;
   }
   if (check(temp))
      return(1);
   if (fb)
   {
      temp->a=v->b;
      temp->b=c0->a;
   }
   if (check(temp))
      return(1);
   return(0);
}
int cut(struct line *u,struct line *v,int x)
{
   double max(double,double),min(double,double);
   double multi(struct point *,struct point *,struct point *);
   if (max(u->a->x,u->b->x)<min(v->a->x,v->b->x))
      return(0);
   if (max(v->a->x,v->b->x)<min(u->a->x,u->b->x))
      return(0);
   if (max(u->a->y,u->b->y)<min(v->a->y,v->b->y))
      return(0);
   if (max(v->a->y,v->b->y)<min(u->a->y,u->b->y))
      return(0);
   if (x==0)
   {
      if (multi(v->a,u->b,u->a)*multi(u->b,v->b,u->a)<=0)
         return(0);
      if (multi(u->a,v->b,v->a)*multi(v->b,u->b,v->a)<=0)
         return(0);
   }
   else
   {
      if (multi(v->a,u->b,u->a)*multi(u->b,v->b,u->a)<0)
         return(0);
      if (multi(u->a,v->b,v->a)*multi(v->b,u->b,v->a)<0)
         return(0);
   }
   return(1);
}
double max(double x,double y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
double min(double x,double y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
double multi(struct point *p1,struct point *p2,struct point *p0)
{
   return((p1->x-p0->x)*(p2->y-p0->y)-(p2->x-p0->x)*(p1->y-p0->y));
}
double len(struct line *v)
{
   double sqr(double);
   return(sqrt(sqr(v->a->x-v->b->x)+sqr(v->a->y-v->b->y)));
}
double sqr(double x)
{
   return(x*x);
}
struct point *middle(struct line *v)
{
   struct point *temp;
   temp=(struct point *)malloc(sizeof(struct point));
   temp->x=(v->a->x+v->b->x)/2.0;
   temp->y=(v->a->y+v->b->y)/2.0;
   return(temp);
}
