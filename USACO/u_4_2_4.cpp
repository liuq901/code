/*
ID: liuq9011
LANG: C++
TASK: cowcycle
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int f,r,f1,f2,r1,r2;
int s1[26],s2[26],ans1[26],ans2[26];
double min;
double a[260],b[260];
int main()
{
   in=fopen("cowcycle.in","r");
   out=fopen("cowcycle.out","w");
   void search(int,int);
   int i;
   fscanf(in,"%d%d",&f,&r);
   fscanf(in,"%d%d%d%d",&f1,&f2,&r1,&r2);
   min=20000000;
   search(1,f1);
   for (i=1;i<=f-1;i++)
      fprintf(out,"%d ",ans1[i]);
   fprintf(out,"%d\n",ans1[f]);
   for (i=1;i<=r-1;i++)
      fprintf(out,"%d ",ans2[i]);
   fprintf(out,"%d\n",ans2[r]);
   fclose(in),fclose(out);
   return(0);
}
void search(int x,int y)
{
   void find(int,int);
   int i;
   if (x==f+1)
   {
      find(1,r1);
      return;
   }
   for (i=y;i<=f2-f+x;i++)
   {
      s1[x]=i;
      search(x+1,i+1);
   }
}
void find(int x,int y)
{
   void count();
   int i;
   if (x==r+1)
   {
      if (s1[f]*s2[r]<3*s1[1]*s2[1])
         return;
      count();
      return;
   }
   for (i=y;i<=r2-r+x;i++)
   {
      s2[x]=i;
      find(x+1,i+1);
   }
}
void count()
{
   int i,j,k,l;
   double sum,ave,vf,sumf,p;
   k=0;
   sum=vf=sumf=0;
   for (i=1;i<=f;i++)
      for (j=1;j<=r;j++)
      {
         p=(double)s1[i]/s2[j];
         k++;
         l=k;
         while (a[l-1]>=p)
         {
            a[l]=a[l-1];
            l--;
         }
         a[l]=p;
      }
   for (i=1;i<=f*r-1;i++)
   {
      b[i]=a[i+1]-a[i];
      sum+=b[i];
      sumf+=b[i]*b[i];
   }
   ave=sum/(f*r-1);
   vf=sumf-sum*ave;
   if (vf<min)
   {
      min=vf;
      memcpy(ans1+1,s1+1,sizeof(int)*f);
      memcpy(ans2+1,s2+1,sizeof(int)*r);
   }
}
