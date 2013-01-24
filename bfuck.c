#include <stdio.h>
#include <stdlib.h>

#define MDUMP 30000
#define elif  else if

int translate(char[MDUMP],int,int);

int main(int argc,int argv[])
{
 char dump[MDUMP];
 char *ptr;
 int line;
 //for(line=0;line<MDUMP;line++) dump[line]='0';
 line=0;
 fflush(stdin);
 printf("?}");
 scanf("%s",dump);
 ptr=dump;
 while(*ptr!='\0')
 {
  line++;ptr++;
 }
 translate(dump,0,++line);
 return 0;
}

int translate(char dump[MDUMP],int start,int mem)
{
 char *ptr;
 int line=mem,cline=start,tmp;
 ptr=dump;
  while(ptr[cline]!='\0')
 {
  if  (ptr[cline]=='+') ptr[line]++;
  elif(ptr[cline]=='-') ptr[line]--;
  elif(ptr[cline]=='>') line++;
  elif(ptr[cline]=='<') line--;
  elif(ptr[cline]=='[') 
            {
            while(ptr[line]>0)
               {
               tmp=translate(dump,cline+1,mem);
               ptr[line]--;
               }
            cline=tmp;
            }
  elif(ptr[cline]==']') return cline;
  elif(ptr[cline]=='.') putchar(ptr[line]);
  cline++;
 }
 puts("");
 return cline;
}
