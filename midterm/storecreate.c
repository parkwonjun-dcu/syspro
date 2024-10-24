#include <stdio.h> 
#include <stdlib.h>
#include "item.h"
int main(int argc, char* argv[])  
{ 
   struct item item;
   FILE *fp;

   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n",argv[0]);
      exit(1); 
   }

   fp = fopen(argv[1], "wb");
   printf(" %-9s %-7s %-4s %-4d %-4d \n", "ID", "Name", "category","expired_date", "stock ");

   while (scanf("%d %s %s %d %d", &item.id, &item.name, &item.category, &item.expired_date , &item.stock) == 5) 
      fwrite(&item, sizeof(item), 1, fp);

   fclose(fp);
   exit(0);
} 

