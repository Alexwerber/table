#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int N = 50;
const int Nstr = 256;

struct object
{
   char name[15];
   char type[6];
   int memory;
   int num_of_components;
   char type_of_components[6];
};

struct table
{
   object elem[N];
   int n;
};

void build_table(table &t, char str[Nstr])
{
   char sep[] = {' ', ';', ','};
   char *p, *k;
   t.n = 0;

   if(p = strstr(str, "int"))
   {
      k = strtok(p, sep);
      while(k != NULL)
      {
         k = strtok(NULL, sep);
         strcpy(t.elem[t.n].type, "int");
         strcpy(t.elem[t.n].name, k);
         t.elem[t.n].memory = 4;
         t.n++;
      }     
   }

   if(strstr(str, "short"));


}

void read(table &t)   // Считывание данных из файла
{
   FILE *f = fopen("PROG.txt", "r");
   char str[Nstr];

   if(f == NULL)
      printf("Файл не найден\n");
   else
      while(fgets(str, Nstr, f))
      { 
         build_table(t, str);
      }
   fclose(f);
}

int main()
{
   table t;

   read(t);

   for(int i = 0; i < t.n; i++)
   {
      printf("i = %d\nname - %s\ntype - %s\nmemory - %d\n", i, t.elem[i].name, t.elem[i].type, t.elem[i].memory);
   }
}