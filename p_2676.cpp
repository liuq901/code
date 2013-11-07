#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int l,r,u,d,x,y;
};
struct data p[236521];
int sum[325],ans[730];
char b[10][10];
int main()
{
   void build();
   int search();
   int i,j,k,t;
   scanf("%d%*c",&t);
   for (i=1;i<=t;i++)
   {
      for (j=1;j<=9;j++)
      {
         for (k=1;k<=9;k++)
            scanf("%c",&b[j][k]);
         scanf("%*c");
      }
      build();
      ans[0]=0;
      if (search())
         continue;
      for (j=1;j<=9;j++)
      {
         for (k=1;k<=9;k++)
            printf("%c",b[j][k]);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
void build()
{
   int count(int,int);
   int i,j,k,l,t,tmp;
   int z[10],q[325],c[10][10],d[10][10],f[10][10];
   t=-1;
   memset(c,0,sizeof(c));
   memset(d,0,sizeof(d));
   memset(f,0,sizeof(f));
   for (i=1;i<=9;i++)
      for (j=1;j<=9;j++)
      {
         if (b[i][j]=='0')
            continue;
         k=b[i][j]-'0';
         c[i][k]=1;
         d[j][k]=1;
         f[(i-1)/3*3+(j-1)/3+1][k]=1;
      }
   for (i=1;i<=324;i++)
   {
      p[i].l=i-1;
      p[i].r=i+1;
      sum[i]=0;
      p[i].x=0;
      p[i].y=i;
      q[i]=i;
   }
   p[0].r=1;
   p[0].l=324;
   p[324].r=0;
   t=0;
   for (i=1;i<=9;i++)
      for (j=1;j<=9;j++)
         for (k=1;k<=9;k++)
         {
            t++;
            if (b[i][j]!='0' && b[i][j]-'0'!=k)
               continue;
            if (b[i][j]=='0' && (c[i][k] || d[j][k] || f[(i-1)/3*3+(j-1)/3+1][k]))
               continue;
            z[1]=(i-1)*9+k;
            z[2]=(j-1)*9+k+81;
            z[3]=((i-1)/3*3+(j-1)/3)*9+k+162;
            z[4]=(i-1)*9+j+243;
            for (l=1;l<=4;l++)
            {
               sum[z[l]]++;
               tmp=count(t,z[l]);
               p[tmp].x=t;
               p[tmp].y=z[l];
               if (l!=1)
               {
                  p[tmp].l=count(t,z[l-1]);
                  p[count(t,z[l-1])].r=tmp;
               }
               p[tmp].u=q[z[l]];
               p[q[z[l]]].d=tmp;
               q[z[l]]=tmp;
            }
            p[count(t,z[1])].l=count(t,z[4]);
            p[count(t,z[4])].r=count(t,z[1]);
         }
   for (i=1;i<=324;i++)
   {
      p[i].u=q[i];
      p[q[i]].d=i;
   }
}
int count(int x,int y)
{
   return(x*324+y);
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
   i=p[0].r;
   while (i!=0)
   {
      if (sum[p[i].y]<min)
      {
         min=sum[p[i].y];
         t=i;
      }
      i=p[i].r;
   }
   del(t);
   i=p[t].d;
   while (i!=t)
   {
      ans[0]++;
      ans[ans[0]]=p[i].x;
      j=p[i].r;
      while (j!=i)
      {
         del(p[j].y);
         j=p[j].r;
      }
      if (search())
         return(1);
      ans[0]--;
      j=p[i].l;
      while (j!=i)
      {
         renew(p[j].y);
         j=p[j].l;
      }
      i=p[i].d;
   }
   renew(t);
   return(0);
}
void print()
{
   int i,x,y;
   int s[90];
   for (i=1;i<=ans[0];i++)
   {
      x=(ans[i]-1)/9;
      y=ans[i]%9;
      if (y==0)
         y=9;
      s[x+1]=y;
   }
   for (i=1;i<=81;i++)
   {
      printf("%d",s[i]);
      if (i%9==0)
         printf("\n");
   }
}
void del(int t)
{
   int i,j;
   p[p[t].r].l=p[t].l;
   p[p[t].l].r=p[t].r;
   i=p[t].d;
   while (i!=t)
   {
      j=p[i].r;
      while (j!=i)
      {
         sum[p[j].y]--;
         p[p[j].u].d=p[j].d;
         p[p[j].d].u=p[j].u;
         j=p[j].r;
      }
      i=p[i].d;
   }
}
void renew(int t)
{
   int i,j;
   i=p[t].u;
   while (i!=t)
   {
      j=p[i].l;
      while (j!=i)
      {
         sum[p[j].y]++;
         p[p[j].u].d=j;
         p[p[j].d].u=j;
         j=p[j].l;
      }
      i=p[i].u;
   }
   p[p[t].r].l=t;
   p[p[t].l].r=t;
}
