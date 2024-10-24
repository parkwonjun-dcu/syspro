#include <stdio.h> 
#include "item.h"

int main(int argc, char* argv[]) 
{ 
	int choice;
   struct item item; 
	 FILE *fp;
   if (argc != 2) { 
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, "Error Open File\n");
      return 2;
   }
   printf("0: List of all goods, 1: list of available goods");
   scanf("%d" , &choice);
   	if ( choice == 0) {
   printf("-----------------------------------\n");
   printf("%10s %6s %6s %6s %6s\n", "ID", "Name", "Category",  "date","stock");
   printf("-----------------------------------\n");

   while (fread(&item, sizeof(item), 1, fp) > 0)
      if (item.id != 0)
         printf("%10d %6s %6s %6d %6d \n", item.id,  item.name,  item.category, item.expired_date, item.stock);

   printf("-----------------------------------\n");
	}

	else if (choice == 1) {	
   printf("-----------------------------------\n");
   printf("%10s %6s %6s %6s %6s\n", "ID", "Name", "Category",  "date","stock");
   printf("-----------------------------------\n");

        while (fread(&item, sizeof(item), 2, fp) > 0)
        if (item.id != 0)
          printf("%10d %6s %6s %6d %6d \n", item.id,  item.name,  item.category, item.expired_date, item.stock);
 
     printf("-----------------------------------\n");
       
  	}
   fclose(fp);
   return 0;
}


