#include <cstdio>
#include <cstdlib>
#include <cstring>
int main() 
{ 
   void root(char *,char *);
   char mid[260]; 
   char lst[260];
   scanf("%s",mid);
   scanf("%s",lst); 
   root(mid,lst); 
   printf("\n");
   system("pause");
   return(0);
}
void root(char *mid,char *lst) 
{ 
   char a,*p,*q;
   if (!*mid) 
      return;   
   p=lst+strlen(lst)-1; 
   printf("%c",*p); 
   q=strchr(mid,*p);         
   *p=0x00; 
   p=q-mid+lst; 
   a=*p; 
   *p=0x00; 
   *q=0x00; 
   root(mid,lst); 
   *p=a; 
   root(q+1,p); 
} 
