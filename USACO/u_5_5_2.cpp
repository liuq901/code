/*
ID: liuq9011
LANG: C++
TASK: hidden
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int l,k,s[200001];
int main()
{
   in=fopen("hidden.in","r");
   out=fopen("hidden.out","w");
   void init(),work();
   init();
   work();
   fprintf(out,"%d\n",k-1);
   fclose(in),fclose(out);
   return(0);
}
void init()
{
   int i,n,t;
   char ch,min;
   fscanf(in,"%d%*c",&l);
   min=126;
   n=l;
   t=0;
   while (1)
   {
      if (n==0)
         break;
      if (n>=72)
      {
         for (i=1;i<=72;i++)
         {
            t++;
            fscanf(in,"%c",&ch);
            if (ch<min)
            {
               min=ch;
               k=t;
            }
            s[t]=ch;
            s[t+l]=ch;
         }
         n-=72;
         fscanf(in,"%*c");
      }
      else
      {
         for (i=1;i<=n;i++)
         {
            t++;
            fscanf(in,"%c",&ch);
            s[t]=ch;
            s[t+l]=ch;
            if (ch<min)
            {
               min=ch;
               k=t;
            }
         }
         break;
      }
   }
}
void work()
{
   int i,j,t;
   i=1;
   while (1)
   {
      if (i>l)
         break;
      if (i==k)
      {
         i++;
         continue;
      }
      j=k;
      t=i;
      while (s[t]==s[j])
      {
         t++;
         j++;
      }
      if (s[t]<s[j] && t<=2*l && j<=2*l)
      {
         k=i;
         i=t;
      }
      else
         i=t+1;
   }
}
