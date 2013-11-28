#include <cstdio>
#include <cstdlib>
#include <cstring>
int sg[510];
bool f[510];
int main()
{
   int n;
   scanf("%d",&n);
   if (n<=500)
   {
      sg[0]=0,sg[1]=sg[2]=1,sg[3]=2;
      for (int i=4;i<=n;i++)
      {
         memset(f,0,sizeof(f));
         f[sg[i-2]]=true;
         for (int j=3;j<=i;j++)
            f[sg[j-3]^sg[i-j]]=true;
         for (int j=0;j<=i;j++)
            if (!f[j])
            {
               sg[i]=j;
               break;
            }
      }
      printf("%s\n",sg[n]?"White":"Black");
   }
   else
   {
      n=(n-428)%34;
      if (n==0 || n==4 || n==8 || n==18 || n==22)
         printf("Black\n");
      else
         printf("White\n");
   }
   system("pause");
   return(0);
}
