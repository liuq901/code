#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int l,r,u,d,x,y;
};
struct data p[18000];
int sum[1025],ans[257];
char b[20][20];
int main()
{
   void build();
   int search();
   int i,j;
   while (1)
   {
      for (i=1;i<=16;i++)
      {
         for (j=1;j<=16;j++)
            scanf("%c",&b[i][j]);
         scanf("%*c");
      }
      build();
      ans[0]=0;
      search();
      if (scanf("%*c")==EOF)
         break;
   }
   system("pause");
   return(0);
}
void build()
{
   int i,j,k,l,t,tmp,num;
   int z[10],q[1025],c[20][20],d[20][20],f[20][20];
   t=-1;
   memset(c,0,sizeof(c));
   memset(d,0,sizeof(d));
   memset(f,0,sizeof(f));
   for (i=1;i<=16;i++)
      for (j=1;j<=16;j++)
      {
         if (b[i][j]=='-')
            continue;
         k=b[i][j]-'A'+1;
         c[i][k]=1;
         d[j][k]=1;
         f[(i-1)/4*4+(j-1)/4+1][k]=1;
      }
   for (i=1;i<=1024;i++)
   {
      p[i].l=i-1;
      p[i].r=i+1;
      sum[i]=0;
      p[i].x=0;
      p[i].y=i;
      q[i]=i;
   }
   p[0].r=1;
   p[0].l=1024;
   p[1024].r=0;
   num=1024;
   t=0;
   for (i=1;i<=16;i++)
      for (j=1;j<=16;j++)
         for (k=1;k<=16;k++)
         {
            t++;
            if (b[i][j]!='-' && b[i][j]-'A'+1!=k)
               continue;
            if (b[i][j]=='-' && (c[i][k] || d[j][k] || f[(i-1)/4*4+(j-1)/4+1][k]))
               continue;
            z[1]=(i-1)*16+k;
            z[2]=(j-1)*16+k+256;
            z[3]=((i-1)/4*4+(j-1)/4)*16+k+512;
            z[4]=(i-1)*16+j+768;
            for (l=1;l<=4;l++)
            {
               sum[z[l]]++;
               tmp=num+l;
               p[tmp].x=t;
               p[tmp].y=z[l];
               if (l!=1)
               {
                  p[tmp].l=num+l-1;
                  p[num+l-1].r=tmp;
               }
               p[tmp].u=q[z[l]];
               p[q[z[l]]].d=tmp;
               q[z[l]]=tmp;
            }
            p[num+1].l=num+4;
            p[num+4].r=num+1;
            num+=4;
         }
   for (i=1;i<=1024;i++)
   {
      p[i].u=q[i];
      p[q[i]].d=i;
   }
}
int search()
{
   void print(),del(int),renew(int);
   int i,j,t,min;
   if (p[0].r==0)
   {
      print();
      return(1);
   }
   min=20000000;
   for (i=p[0].r;i;i=p[i].r)
      if (sum[p[i].y]<=min)
      {
         min=sum[p[i].y];
         t=i;
      }
   del(t);
   for (i=p[t].d;i!=t;i=p[i].d)
   {
      ans[0]++;
      ans[ans[0]]=p[i].x;
      for (j=p[i].r;j!=i;j=p[j].r)
         del(p[j].y);
      if (search())
         return(1);
      ans[0]--;
      for (j=p[i].l;j!=i;j=p[j].l)
         renew(p[j].y);
   }
   renew(t);
   return(0);
}
void print()
{
   int i,x,y;
   int s[260];
   for (i=1;i<=ans[0];i++)
   {
      x=(ans[i]-1)/16;
      y=ans[i]%16;
      if (y==0)
         y=16;
      s[x+1]=y;
   }
   for (i=1;i<=256;i++)
   {
      printf("%c",s[i]+'A'-1);
      if (i%16==0)
         printf("\n");
   }
   printf("\n");
}
void del(int t)
{
   int i,j;
   p[p[t].r].l=p[t].l;
   p[p[t].l].r=p[t].r;
   for (i=p[t].d;i!=t;i=p[i].d)
      for (j=p[i].r;j!=i;j=p[j].r)
      {
         sum[p[j].y]--;
         p[p[j].u].d=p[j].d;
         p[p[j].d].u=p[j].u;
      }
}
void renew(int t)
{
   int i,j;
   p[p[t].r].l=t;
   p[p[t].l].r=t;
   for (i=p[t].u;i!=t;i=p[i].u)
      for (j=p[i].l;j!=i;j=p[j].l)
      {
         sum[p[j].y]++;
         p[p[j].u].d=j;
         p[p[j].d].u=j;
      }
}
