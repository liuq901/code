#include <cstdio>
#include <cstdlib>
const int move[5][3]={{0},{0,2,3},{0,1,4},{0,1,4},{0,2,3}};
const int move2[5][3]={{0},{0,1,4},{0,2,3},{0,2,3},{0,1,4}};
struct ticeberg
{
   int x1,y1,x2,y2;
};
struct tstate
{
   int ibid,bor;
};
int step,n,q1,q2,srcx,srcy,tarx,tary,time;
int f[4001][5];
struct ticeberg a[4001];
struct tstate a1[1001],a2[1001];
int main()
{
   void initialize(),firstexpand(),mainexpand(),outfailed();
   initialize();
   firstexpand();
   mainexpand();
   outfailed();
   system("pause");
   return(0);
}
void initialize()
{
   int b,i;
   b=1;
   scanf("%d",&n);
   scanf("%d%d",&srcx,&srcy);
   scanf("%d%d",&tarx,&tary);
   for (i=1;i<=n;i++)
      scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
   a[n+1].x1=tarx,a[n+1].x2=a[n+1].x1;
   a[n+1].y1=tary,a[n+1].y2=a[n+1].y1;
}
void firstexpand()
{
   void expandsrc(int,int *,int *);
   int i,b,next1,next2;
   step=1;
   next1=next2=0;
   q1=q2=0;
   for (i=1;i<=2;i++)
   {
      expandsrc(i,&next1,&next2);
      b=5-move2[i][1];
      if (next1!=0)
      {
         q1++;
         a1[q1].ibid=next1;
         a1[q1].bor=b;
         f[next1][b]=1;
      }
      b=5-move2[i][2];
      if (next2!=0)
      {
         q1++;
         a1[q1].ibid=next2;
         a1[q1].bor=b;
         f[next2][b]=1;
      }
   }
}
void expandsrc(int p,int *p1,int *p2)
{
   int i,j,m1,m2;
   *p1=*p2=0;
   j=0;
   if (p==1 || p==4)
   {
      m1=-200000;
      m2=200000;
      for (i=1;i<=n+1;i++)
      {
         if (a[i].x1<=srcx && a[i].x2>=srcx)
            if (a[i].y2+1<srcy && a[i].y2+1>m1)
            {
               m1=a[i].y2;
               *p1=i;
            }
         if (a[i].x1<=srcx && a[i].x2>=srcx)
            if (a[i].y1-1>srcy && a[i].y1-1<m2)
            {
               m2=a[i].y1;
               *p2=i;
            }
      }
   }
   else
   {
      m1=-200000;
      m2=200000;
      for (i=1;i<=n+1;i++)
      {
         if (a[i].y1<=srcy && a[i].y2>=srcy)
            if (a[i].x2+1<srcx && a[i].x2+1>m1)
            {
               m1=a[i].x2;
               *p1=i;
            }
         if (a[i].y1<=srcy && a[i].y2>=srcy)
            if (a[i].x1-1>srcx && a[i].x1-1<m2)
            {
               m2=a[i].x1;
               *p2=i;
            }
      }
   }
   if (*p1==n+1 || *p2==n+1)
   {
      printf("1\n");
      system("pause");
      exit(0);
   }
}
void mainexpand()
{
   void expand(int,int,int *,int *);
   int i,j,b,next1,next2;
   while (1)
   {
      step++;
      for (i=1;i<=q1;i++)
      {
         expand(a1[i].ibid,a1[i].bor,&next1,&next2);
         b=5-move[a1[i].bor][1];
         if (next1!=0)
            if (!f[next1][b])
            {
               q2++;
               a2[q2].ibid=next1;
               a2[q2].bor=b;
               f[next1][b]=1;
            }
         b=5-move[a1[i].bor][2];
         if (next2!=0)
            if (!f[next2][b])
            {
               q2++;
               a2[q2].ibid=next2;
               a2[q2].bor=b;
               f[next2][b]=1;
            }
      }
      if (q2==0)
         break;
      for (i=1;i<=q2;i++)
         a1[i]=a2[i];
      q1=q2;
      q2=0;
   }
}
void expand(int id,int q,int *p1,int *p2)
{
   void print();
   int i,x,y,m1,m2;
   *p1=*p2=0;
   switch (q)
   {
   case 1:
      x=a[id].x1;
      y=a[id].y1-1;
      break;
   case 4:
      x=a[id].x2;
      y=a[id].y2+1;
      break;
   case 3:
      x=a[id].x2+1;
      y=a[id].y2;
      break;
   case 2:
      x=a[id].x1-1;
      y=a[id].y1;
      break;
   }
   if (q==2 || q==3)
   {
      m1=-200000;
      m2=200000;
      for (i=1;i<=n+1;i++)
      {
         if (a[i].x1<=x && a[i].x2>=x)
            if (a[i].y2+1<y && a[i].y2+1>m1)
            {
               m1=a[i].y2;
               *p1=i;
            }
         if (a[i].x1<=x && a[i].x2>=x)
            if (a[i].y1-1>y && a[i].y1-1<m2)
            {
               m2=a[i].y1;
               *p2=i;
            }
      }
   }
   else
   {
      m1=-200000;
      m2=200000;
      for (i=1;i<=n+1;i++)
      {
         if (a[i].y1<=y && a[i].y2>=y)
            if (a[i].x2+1<x && a[i].x2+1>m1)
            {
               m1=a[i].x2;
               *p1=i;
            }
         if (a[i].y1<=y && a[i].y2>=y)
            if (a[i].x1-1>x && a[i].x1-1<m2)
            {
               m2=a[i].x1;
               *p2=i;
            }
      }
   }
   if (*p1==n+1 || *p2==n+1)
      print();
}
void print()
{
   printf("%d\n",step);
   system("pause");
   exit(0);
}
void outfailed()
{
   printf("0\n");
}
