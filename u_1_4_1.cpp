/*
ID: liuq9011
LANG: C++
TASK: packrec
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int min,a[10][10],f[260][260];
int main()
{
   in=fopen("packrec.in","r");
   out=fopen("packrec.out","w");
   void work(int,int,int,int,int,int,int,int);
   int i,j,s1,s2,s3,s4,b1,b2,b3,b4;
   for (i=1;i<=4;i++)
      fscanf(in,"%d%d",&a[i][1],&a[i][2]);
   min=2000000;
   memset(f,0,sizeof(f));
   for (s1=1;s1<=4;s1++)
      for (s2=1;s2<=4;s2++)
         if (s1!=s2)
            for (s3=1;s3<=4;s3++)
               if (s3!=s1 && s3!=s2)
               {
                  s4=10-s1-s2-s3;
                  for (b1=1;b1<=2;b1++)
                     for (b2=1;b2<=2;b2++)
                        for (b3=1;b3<=2;b3++)
                           for (b4=1;b4<=2;b4++)
                              work(s1,s2,s3,s4,b1,b2,b3,b4);
               }
   fprintf(out,"%d\n",min);
   for (i=1;i<=200;i++)
      for (j=1;j<=200;j++)
         if (f[i][j] && i*j==min)
         {
            fprintf(out,"%d %d\n",i,j);
            f[j][i]=0;
         }
   fclose(in),fclose(out);
   return(0);
}
void work(int s1,int s2,int s3,int s4,int b1,int b2,int b3,int b4)
{
   int max(int,int);
   void check(int,int);
   int w1,w2,w3,w4,h1,h2,h3,h4,w,h;
   w1=a[s1][b1];
   w2=a[s2][b2];
   w3=a[s3][b3];
   w4=a[s4][b4];
   h1=a[s1][3-b1];
   h2=a[s2][3-b2];
   h3=a[s3][3-b3];
   h4=a[s4][3-b4];
   w=w1+w2+w3+w4;
   h=max(h1,max(h2,max(h3,h4)));
   check(w,h);
   w=max(w1+w2+w3,w4);
   h=max(h1,max(h2,h3))+h4;
   check(w,h);
   w=max(w1+w2,w3)+w4;
   h=max(h1+h3,max(h2+h3,h4));
   check(w,h);
   w=w1+w2+max(w3,w4);
   h=max(h1,max(h3+h4,h2));
   check(w,h);
   if (h3>=h2+h4)
      w=max(w1,max(w2+w3,w3+w4));
   else if (h3>h4 && h3<h2+h4)
      w=max(w1+w2,max(w2+w3,w3+w4));
   else if (h4>h3 && h4<h1+h3)
      w=max(w1+w2,max(w1+w4,w3+w4));
   else if (h4>=h1+h3)
      w=max(w2,max(w1+w4,w3+w4));
   else
      w=max(w1+w2,w3+w4);
   h=max(h1+h3,h2+h4);
   check(w,h);
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
void check(int x,int y)
{
   if (x*y<=min)
   {
      min=x*y;
      f[x][y]=f[y][x]=1;
   }
}
