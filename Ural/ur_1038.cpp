#include <cstdio>
#include <cstdlib>
#include <cctype>
int main()
{
   bool ispunct(char);
   int ans,flag;
   ans=flag=0;
   char ch;
   while (scanf("%c",&ch)!=EOF)
      if (!flag)
      {
         if (islower(ch))
            ans++;
         if (isalpha(ch))
            flag=1;
      }
      else if (flag==1)
      {
         if (isupper(ch))
            ans++;
         if (!isalpha(ch))
            if (ispunct(ch))
               flag=0;
            else
               flag=2;
      }
      else
      {
         if (isalpha(ch))
            flag=1;
         if (ispunct(ch))
            flag=0;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool ispunct(char ch)
{
   return(ch=='?' || ch=='!' || ch=='.');
   
}
