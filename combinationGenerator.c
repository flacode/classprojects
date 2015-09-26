/*contains function definitions for generating combinations*/
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "combinationGenerator.h"//header file containing the function prototypes to generate combination
/*defining constants used in generating combinations of letters*/
#define LEN 1
#define LEN1 2
#define LEN2 3
/*defining constants and arrays*/
char str[LEN+1];
char str1[LEN1+1];
char str2[LEN2+1];
int startnumber[10];
int endnumber[10];
char startletter[10];
char endletter[10];
int selection, option, suboption, range, numbermain, numbersub, i, numberend, optionend;
FILE*fout;//pointer to file combinations.doc
/*function to display and prompt the user on the main menu*/
void mainmenu(){
	printf("\nPlease enter your selection\n1. Start with\n2. Followed by\n3. End with\nYour selection:");
	scanf("%d", &selection);
	if(selection == 1){
	optionmenu();
}                
    else{
    	printf("ERROR");
    	mainmenu();
    }                   
}
/*function to prompt user for options*/
void optionmenu(){
	printf("\nChoose an option that suits you\n1.Letters \n2.Numbers\n3.Back \nYour Option:");
	scanf("%d", &option);
	if(option == 1){
	    printf("How many?");
	    scanf("%d", &numbermain);
	    printf("Enter %d letter(s)", numbermain);
		for(i=1; i<=numbermain; i++){
	    	scanf("%s", &startletter[i]);	
	   }	   
	}
	else if(option == 2){
		printf("How many?");
	    scanf("%d", &numbermain);
		printf("Enter %d number(s)", numbermain); 
		for(i=1; i<=numbermain; i++){
	    	scanf("%d", &startnumber[i]);	
	   }
	    	}
	else if (option == 3){
		mainmenu();
	}
	else {
		printf("ERROR");
		optionmenu();
	}

}
/*function to display and prompt the user on the sub menu*/
void submenu(){
	printf("\nMENU\n");
    printf("Please enter your selection\n2. Followed by\n3. End with\n4. Back\nYour selection:");
	scanf("%d", &selection);
	if (selection == 2){
		optionsubmenu();
	}
	else if(selection == 3){
    	endmenu();
	}
	else if(selection == 4){
        optionmenu();
	}
	else{
		printf("ERROR");
		submenu();
	}
}
/*function to display and prompt the user for options on the sub menu*/
void optionsubmenu(){
	printf("\nChoose an option that suits you\n1.Letters \n2.Numbers\n3.Back\nYour Option:");
	scanf("%d", &suboption);
	if(suboption == 1){
	printf("1. 1 letter\n2. 2 letters\n3. 3 letters\nHow many?:");
	scanf("%d", &numbersub);
}
	else if(suboption == 2){
	printf("1. 1 number\n2. 2 numbers\n3. 3 numbers\nHow many?:");
	scanf("%d", &numbersub);
}
	else if (suboption == 3){
	submenu();
	}
	else {
		printf("ERROR");
		optionsubmenu();
	}
submenu();
}
/*function to generate and print generated pattern of alphabetical letters*/
void iterate(char*str, int i, int len){
	char c;
	if(i < (len-1)){
		for(c='A'; c<='Z'; ++c){
			str[i]=c;
			iterate(str, i+1, len);
		}
	}
	else {
		for(c='A'; c<='Z'; ++c){
            str[i]=c;
			printstart();
			fprintf(fout, "%s", str);	
			printend();
}
	}
	}
/*function to display and prompt the user for options*/
void endmenu(){
	printf("\nChoose an option that suits you\n1.Letters \n2.Numbers\n3.Back\nYour Option:");
	scanf("%d", &optionend);
		if(optionend == 1){
		printf("How many?");
	    scanf("%d", &numberend);
	    printf("Enter %d letter(s)", numberend);
		for(i=1; i<=numberend; i++){
	    	scanf("%s", &endletter[i]);	
	   }	   
	}
	else if(optionend == 2){
	    printf("How many?");
	    scanf("%d", &numberend);
		printf("Enter %d number(s)", numberend); 
		for(i=1; i<=numberend; i++){
	    	scanf("%d", &endnumber[i]);	
	   }
}
        else if(optionend == 3){
         submenu();
         }
	else {
		printf("ERROR");
		endmenu();
	}
}
/*function to print starting letters or numbers from the client to a file*/
void printstart(){
	if(option == 1){
		 for(i=1; i<=numbermain; i++){
	    	fprintf(fout, "%c", toupper(startletter[i]));	
         }
  }
	else if(option == 2){
		for(i=1; i<=numbermain; i++){
	    	fprintf(fout, "%d", startnumber[i]);	
        }        
}
}
/*function to print ending letters or numbers from the client to a file*/
void printend(){
	if(optionend == 1){
		 for(i=1; i<=numberend; i++){
	    	fprintf(fout, "%c", toupper(endletter[i]));	
         }
         fprintf(fout, "\n");
  }
	else if(optionend == 2){
		for(i=1; i<=numberend; i++){
	    	fprintf(fout, "%d", endnumber[i]);	
        }        
        fprintf(fout, "\n");
}
}
/*function to print the entire generated combination to a file*/
void printc(){
	if(suboption == 1){
		if (numbersub == 1){
	      iterate(str, 0, LEN);
	}
     	else if(numbersub == 2){
	    iterate(str1, 0, LEN1);
		}
		else if(numbersub == 3){
	    iterate(str2, 0, LEN2);
}
	}
	else if(suboption == 2){
		if (numbersub == 1){
	        for(range=0; range<10; range++ ){
	        printstart();
	        fprintf(fout, "%d", range);
	        printend();
	    }
	}
     	else if(numbersub == 2){
	        for (range=0; range<100; range++){
	        printstart();
	        fprintf(fout, "%.2d", range);
	        printend();
	    }
	    }
		else if(numbersub == 3){
			for(range=0; range<1000; range++){
			printstart();
			fprintf(fout, "%.3d", range);
			printend();
		}
	}
	}
}
