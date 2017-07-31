#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "combinationGenerator.h"
#include "combinationAssignment.h"
#define LEN 1
#define LEN1 2
#define LEN2 3
char str[LEN+1];
char str1[LEN1+1];
char str2[LEN2+1];
int startnumber[10];
int endnumber[10];
char startletter[10];
char endletter[10];
int selection, option, suboption, range, numbermain, numbersub, i, numberend, optionend;
char combinationvalue[20];
char name[30];
/*pointers to files*/
FILE *fp;
FILE *fout;
FILE*fin;
char entry;
main()
{  
    fout=fopen("combinations.doc", "w+");//opening file for reading and writing
    fp = fopen("assignment.doc","w+");// opening file for writing and reading
    fin=fopen("combinations.doc", "r");//opening file for reading 
    printf("MENU\n");
/*calling functions in the combinationGenerator.c and combinationAssignment.c*/
    mainmenu();
    submenu();
    printc();
    assignment();
/*closing the open files*/
fclose(fout);
fclose(fin);
fclose(fp);
	return 0;

}
