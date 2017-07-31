#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combinationAssignment.h"//header file containing the function prototypes to assign combinations
char combinationvalue[20];
char name[30];
char entry;
FILE*fp;//pointer to a file assignment.doc
FILE*fin;//pointer to file combinations.doc
/*function to assign names to generated list*/
void assignment(){   
   if( fin == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
/*reads input from a file and outputs in the other*/
   while((fgets(combinationvalue, 20, (FILE*)fin)) != NULL){
   	printf("\nDO YOU WISH TO ASSIGN %sY-Yes\nN-NO\nPress any key to exit\n", combinationvalue);
   	scanf("%s", &entry);
   	if(entry=='y'||entry=='Y'){
   	printf("Enter the name:");
   	scanf("%s", name);
   	fprintf(fp, "%s \t\t\tis taken by %s\n", combinationvalue, name);
   }
   else if(entry=='n'||entry=='N'){
   	fprintf(fp, "%s \t\t\tFREE\n", combinationvalue);
   	continue;
   }
   else{
     while((fgets(combinationvalue, 20, (FILE*)fin)) != NULL){
           fprintf(fp, "%s \t\t\tFREE\n", combinationvalue);
}
   	break;
   }
   fprintf(fp, "%s \t\t\tFREE\n", combinationvalue);
}
}
