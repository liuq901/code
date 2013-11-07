/*
ID: liuq9011
LANG: C++
TASK: gift1
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("gift1.in","r");
   out=fopen("gift1.out","w");
   char name[11][15],p[11],*s[11];
   int i,j,n,x,y,t,k;
   int a[11];
   fscanf(in,"%d%*c",&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%s",name[i]);
      s[i]=name[i];
   }
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%s",p);
      for (j=1;j<=n;j++)
         if (strcmp(s[j],p)==0)
         {
            k=j;
            break;
         }
      fscanf(in,"%d%d%*c",&x,&y);
      if (x!=0 && y!=0)
      {
         x/=y;
         a[k]-=x*y;
         for (j=1;j<=y;j++)
         {
            fscanf(in,"%s",p);
            for (k=1;k<=n;k++)
               if (strcmp(s[k],p)==0)
                  a[k]+=x;
         }
      }  
   }
   for (i=1;i<=n;i++)
      fprintf(out,"%s %d\n",s[i],a[i]);
   fclose(in),fclose(out);
   return(0);
}
