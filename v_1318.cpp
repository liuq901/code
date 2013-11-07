#include <cstdio>
#include <cstdlib>
int main() 
{ 
   int process(char *,int,int); 
   char first[27]; 
   int i,begin,end,length; 
   scanf("%d%d%d",&begin,&end,&length); 
   getchar(); 
   for (i=0;i<length;i++) 
   scanf("%c",&first[i]); 
   first[length]='\0'; 
   for (i=1;process(first,end,length) && i<=5;i++)
      printf("%s\n",first); 
   system("pause");
   return(0);
} 
int process (char *a,int end,int length) 
{ 
   int i,sth=0; 
   char *p=a+length-1; 
   char max='a'+end-1; 
   for (;;p--,max--) 
   {   
      if (*p<max) 
      { 
         *p=*p+1; 
         for (i=1;*(p+i);i++) 
            *(p+i)=*p+i; 
         sth=1; 
         break; 
      } 
      if (p==a) 
         break; 
   } 
   return(sth); 
}
