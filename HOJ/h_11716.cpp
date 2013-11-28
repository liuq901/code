#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p[2][8]={{0,1,0,1,1,0,1,1},{0,1,1,1,1,0,0,1}};
int main()
{
   char s[1010];
   while (scanf("%s",s)!=EOF)
   {
      int a[1010],b[1010]={0},c[1010]={0};
      int l=strlen(s);
      for (int i=1;i<=l;i++)
         a[i]=s[i-1]-'0';
      for (int i=1;i<=l;i++)
         for (int j=1;j<=7;j++)
         {
            b[i+j-1]+=a[i]*p[0][j];
            c[i+j-1]+=a[i]*p[1][j];
         }
      static int id=0;
      printf("Case %d: ",++id);
      for (int i=1;i<=l+6;i++)
         printf("%d%d",b[i]&1,c[i]&1);
      printf("\n");
   }
   system("pause");
   return(0);
}
