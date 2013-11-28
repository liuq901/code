#include <cstdio>
#include <cstdlib>
#include <cstring>
const char a[]="ABCDEFGHJKLMNPQRSTUVXYWZIO";
char s[20];
bool f[250];
int main()
{
   while (scanf("%s",s)==1)
   {
      memset(f,0,sizeof(f));
      int sum=0;
      for (int i=0;i<8;i++)
         sum+=(s[i]-'0')*(8-i);
      int num=s[8]-'0';
      if (!num)
         num=10;
      for (int i=10;i<=35;i++)
      {
         int now=sum+i/10+i%10*9;
         if (now%10+num==10)
            f[a[i-10]]=true;
      }
      for (char ch='A';ch<='Z';ch++)
         if (f[ch])
            printf("%c",ch);
      printf("\n");
   }
   system("pause");
   return(0);
}
