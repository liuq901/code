#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,*a[4];
   char s[20];
   a[0]=(int *)malloc(sizeof(int));
   a[1]=(int *)malloc(sizeof(int));
   a[2]=(int *)malloc(sizeof(int));
   a[3]=(int *)malloc(sizeof(int));
   *a[0]=*a[1]=*a[2]=*a[3]=0;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%s",s);
      if (s[0]=='w')
         printf("%d\n",*a[s[8]-'a']);
      else if (s[1]==':')
         a[s[0]-'a']=a[s[3]-'a'];
      else if (s[4]>='a' && s[4]<='d')       
         *a[s[0]-'a']=*a[s[4]-'a'];
      else
         *a[s[0]-'a']=s[4]-'0';
   }
   system("pause");
   return(0);
}
