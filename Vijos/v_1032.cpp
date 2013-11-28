#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[8][101];
int i,p,q,l,t,r;
char s[260]="";
int main()
{
   void mult(),plus(),noa();
   scanf("%s",&s);
   q=strlen(s);
   for (i=q+1;i>=1;i--)
      s[i]=s[i-1];
   if (q>100)
      p=100;
   else
      p=q;
   for (i=1;i<=p;i++)
      b[2][i]=s[q-i+1]-'0';
   for (i=1;i<=100;i++)
      b[1][i]=b[7][i]=b[2][i];
   b[6][1]=b[4][1]=b[3][1]=1;
   scanf("%d",&r);
   mult();
   do
   {
      t=0;
      l++;
      while (b[2][l]!=b[7][l])
      {
         t++;
         if (t>10)
            noa();
         mult();
         plus();
      }
      for (i=1;i<=100;i++)
      {
         b[1][i]=b[3][i];
         b[6][i]=b[4][i];
      }         
   }while(l!=r);
   t=100;
   while (b[4][t]==0)
   {
      t--;
   }
   for (i=t;i>=1;i--)
      printf("%d",b[4][i]);
   printf("\n");
   system("pause");
   return(0);
}
void mult()
{
   int i,j;
   memset(b[5],0,sizeof(b[5]));
   for (i=1;i<=500;i++)
      for (j=1;j<=100-i+1;j++)
         b[5][i+j-1]=b[5][i+j-1]+b[1][i]*b[2][j];
   for (i=1;i<=99;i++)
   {
      b[5][i+1]=b[5][i+1]+b[5][i]/10;
      b[5][i]%=10;
   }
   b[5][100]%=10;
   for (i=1;i<=100;i++)
      b[2][i]=b[5][i];
   memset(b[5],0,sizeof(b[5]));
   for (i=1;i<=100;i++)
      for (j=1;j<=101-i;j++)
         b[5][i+j-1]=b[5][i+j-1]+b[1][i]*b[3][j];
   for (i=1;i<=99;i++)
   {
      b[5][i+1]=b[5][i+1]+b[5][i]/10;
      b[5][i]%=10;
   }
   b[5][100]%=10;
   for (i=1;i<=100;i++)
      b[3][i]=b[5][i];
}
void plus()
{
   int i;
   for (i=1;i<=99;i++)
   {
      b[4][i]=b[4][i]+b[6][i];
      b[4][i+1]=b[4][i+1]+b[4][i]/10;
      b[4][i]%=10;
   }
}
void noa()
{
   printf("-1\n");
   system("pause");
   exit(0);
}
