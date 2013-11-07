/*
ID: liuq9011
LANG: C++
TASK: lamps
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,c,s,f[10],ans[10000][10],*a[10000],b[10000];
int main()
{
   in=fopen("lamps.in","r");
   out=fopen("lamps.out","w");
   void check(int,int,int,int);
   void sort(int,int);
   int i,j,x,w1,w2,w3,w4;
   fscanf(in,"%d",&n);
   fscanf(in,"%d",&c);
   memset(f,0,sizeof(f));
   while (1)
   {
      fscanf(in,"%d",&x);
      if (x==-1)
         break;
      f[(x-1)%6]=1;
   }
   while (1)
   {
      fscanf(in,"%d",&x);
      if (x==-1)
         break;
      f[(x-1)%6]=-1;
   }
   s=0;
   for (w1=0;w1<=1;w1++)
      for (w2=0;w2<=1;w2++)
         for (w3=0;w3<=1;w3++)
            for (w4=0;w4<=1;w4++)
               check(w1,w2,w3,w4);
   sort(1,s);
   for (i=1;i<=s;i++)
   {
      for (j=1;j<=n;j++)
         fprintf(out,"%d",a[i][(j-1)%6]);
      fprintf(out,"\n");
   }
   if (s==0)
      fprintf(out,"IMPOSSIBLE\n");
   fclose(in),fclose(out);
}
void check(int w1,int w2,int w3,int w4)
{
   int i,bo,t;
   int flag[10];
   if (w1+w2+w3+w4>c)
      return;
   if ((w1+w2+w3+w4)%2!=c%2)
      return;
   flag[0]=flag[1]=flag[2]=flag[3]=flag[4]=flag[5]=1;
   for (i=0;i<=5;i++)
   {
      if (w1)
         flag[i]*=-1;
      if (w2 && i%2==0)
         flag[i]*=-1;
      if (w3 && i%2==1)
         flag[i]*=-1;
      if (w4 && i%3==0)
         flag[i]*=-1;
   }
   bo=1;
   for (i=0;i<=5;i++)
   {
      if (!f[i])
         continue;
      if (flag[i]!=f[i])
      {
         bo=0;
         break;
      }
   }
   if (!bo)
      return;
   s++;
   a[s]=ans[s];
   t=0;
   for (i=0;i<=5;i++)
   {
      if (flag[i]==1)
         a[s][i]=1;
      else
         a[s][i]=0;
      t=t*10+a[s][i];
   }
   b[s]=t;
}
void sort(int l,int r)
{
   int i,j,x,t,*tt;
   i=l;
   j=r;
   x=b[(l+r)/2];
   while (i<=j)
   {
      while (b[i]<x)
         i++;
      while (b[j]>x)
         j--;
      if (i<=j)
      {
         t=b[i],b[i]=b[j],b[j]=t;
         tt=a[i],a[i]=a[j],a[j]=tt;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
