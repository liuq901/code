#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[]={1,2,4,8,16,32,64,128,256,512,1024};
int main()
{
   char a[1000];
   int m,l;
   scanf("%s%d",a,&m);
   l=strlen(a);
   long long n=0;
   for (int i=0;i<m;i++)
   {
      if (l-m+i<0)
         continue;
      n=n*10+a[l-m+i]-'0';
   }
   printf("%I64d\n",(n*3+1)%c[m]);
   system("pause");
   return(0);
}
