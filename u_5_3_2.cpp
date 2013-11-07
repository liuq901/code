/*
ID: liuq9011
LANG: C++
TASK: window
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
struct data
{
   char ch;
   int x1,y1,x2,y2,level;
};
struct data a[100];
int n,min,max;
int main()
{
   in=fopen("window.in","r");
   out=fopen("window.out","w");
   void insert(char,int,int,int,int),up(char),down(char),del(char),print(char);
   int i,x1,y1,x2,y2;
   char ch;
   n=min=max=0;
   while (!feof(in))
   {
      fscanf(in,"%c%*c",&ch);
      switch (ch)
      {
      case 'w':
         fscanf(in,"%c,%d,%d,%d,%d",&ch,&x1,&y1,&x2,&y2);
         insert(ch,x1,y1,x2,y2);
         break;
      case 't':
         fscanf(in,"%c",&ch);
         up(ch);
         break;
      case 'b':
         fscanf(in,"%c",&ch);
         down(ch);
         break;
      case 'd':
         fscanf(in,"%c",&ch);
         del(ch);
         break;
      case 's':
         fscanf(in,"%c",&ch);
         print(ch);
         break;
      }
      fscanf(in,"%*c%*c");
   }
   fclose(in),fclose(out);
   return(0);
}
void insert(char ch,int x1,int y1,int x2,int y2)
{
   int t;
   if (x1>x2)
      t=x1,x1=x2,x2=t;
   if (y1>y2)
      t=y1,y1=y2,y2=t;
   n++;
   max++;
   a[n].ch=ch;
   a[n].x1=x1;
   a[n].y1=y1;
   a[n].x2=x2;
   a[n].y2=y2;
   a[n].level=max;
}
void up(char ch)
{
   int i;
   for (i=1;i<=n;i++)
      if (a[i].ch==ch)
      {
         max++;
         a[i].level=max;
         break;
      }
}
void down(char ch)
{
   int i;
   for (i=1;i<=n;i++)
      if (a[i].ch==ch)
      {
         min--;
         a[i].level=min;
         break;
      }
}
void del(char ch)
{
   int i,k;
   for (i=1;i<=n;i++)
      if (a[i].ch==ch)
      {
         k=i;
         break;
      }
   memmove(&a[k],&a[k+1],(n-k)*sizeof(struct data));
   n--;
   max=-20000000;
   min=20000000;
   for (i=1;i<=n;i++)
   {
      if (a[i].level>max)
         max=a[i].level;
      if (a[i].level<min)
         min=a[i].level;
   }
   if (n==0)
      max=min=0;
}
void print(char ch)
{
   int count(int,int,int,int,int,int);
   int x,i;
   double s1,s2;
   for (i=1;i<=n;i++)
      if (a[i].ch==ch)
      {
         x=i;
         break;
      }
   s1=(double)count(a[x].x1,a[x].y1,a[x].x2,a[x].y2,a[x].level,1);
   s2=(double)(a[x].x2-a[x].x1)*(a[x].y2-a[x].y1);
   fprintf(out,"%.3lf\n",100.0*s1/s2);
}
int count(int x1,int y1,int x2,int y2,int level,int t)
{
   if (t>n)
      return((y2-y1)*(x2-x1));
   if (a[t].level<=level)
      return(count(x1,y1,x2,y2,level,t+1));
   if (x1<a[t].x1 && x2>a[t].x1 && a[t].y1<y2 && a[t].y2>y1)
      return(count(x1,y1,a[t].x1,y2,level,t+1)+count(a[t].x1,y1,x2,y2,level,t));
   if (x1<a[t].x2 && x2>a[t].x2 && a[t].y1<y2 && a[t].y2>y1)
      return(count(a[t].x2,y1,x2,y2,level,t+1)+count(x1,y1,a[t].x2,y2,level,t));
   if (y1<a[t].y1 && y2>a[t].y1 && a[t].x1<x2 && a[t].x2>x1)
      return(count(x1,y1,x2,a[t].y1,level,t+1)+count(x1,a[t].y1,x2,y2,level,t));
   if (y1<a[t].y2 && y2>a[t].y2 && a[t].x1<x2 && a[t].x2>x1)
      return(count(x1,a[t].y2,x2,y2,level,t+1));
   if (x1>=a[t].x1 && x2<=a[t].x2 && y1>=a[t].y1 && y2<=a[t].y2)
      return(0);
   return(count(x1,y1,x2,y2,level,t+1));
}
