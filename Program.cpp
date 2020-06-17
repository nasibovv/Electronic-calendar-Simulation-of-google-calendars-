#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <calendar.h> //specific header file for this project; for running this project you have to drop a copy of this .h file between lib files of your compiler
#define LEN 256
#define MAXCHAR 1000

/* Vidadi Nasibov 2020 Project: Electronic calendar [Simulation of google calendars]*/

/* Based on calendar.google.com working principle */

/*
IMPORTANT NOTE: In some swith cases, 3 and 5, used {}, brackets, before writing the code. It does not be written by mistake. Sometimes in C, occurs error
which states jump of cases. The reason of it declaring some necessary variables inside switch cases. For overcoming this error, developer should use
brakets, {}, before writting his/her code to case. It allows declared variable to be used only in spefici case, and overcomes jumping error. 

Other main notes were mentioned in the spefici lines, which needs comment
*/

 
int main(int argc, char* argv[]){
    int year,month, day;
    char choice;
    Note note;
 
    while(1) {
      printf("1. Print Calendar of a Month\n");     // Prints a calendar of spefici month and year
      printf("2. Add Note\n");                     // User can add his/her note for spesific date
      printf("3. Check Spesific Note\n");         // User can check his/her not(s) which he/she  previously added
      printf("4. Show All Notes\n");             // User can check all his/her notes
      printf("5. Delete Note\n");               // User can delete his/her note 
      printf("6. Exit\n");                     //  Simple exit option for program 
      
	  printf("Enter your choice: ");
      scanf("\n%c", &choice);
      
      
	  switch(choice) {
	  	
        case '1':
        system("CLS");
        printf("Enter the month (MM): ");
        scanf("%d", &month);
		printf("Enter the year (YYYY): ");  
        scanf("%d", &year);
        system("CLS");                      // this is a system clear function, which helps to have more clean and nice user interface, used several time in code
        calendar(year, month);
        break;
        
        case '2':
        char name[200]; 
   		FILE * fp;
   		int i;
   		fp = fopen ("Notes.txt","a+");
        system("CLS"); 
        
        printf("Enter the day (DD): ");
        scanf("%d", &note.day); 
		fprintf (fp, "%d/", note.day); 
        
        printf("Enter the month (MM): "); 
        scanf("%d", &note.month);
        		fprintf (fp, "%d/",note.month); 
        		
		printf("Enter the year (YYYY): ");  
		scanf("%d", &note.year);
				fprintf (fp, "%d        Note:  ",note.year); 
        
        flush();
        printf("Enter the note: ");
   		scanf("%[^\n]%*c", name);
		fprintf (fp, name,i + 1); 
		fprintf (fp, "\n",i + 1); 
   		fclose (fp);
   
        printf("\n");
        printf("Note added sucessfully!\n");
        printf("You're redirecting to main menu...\n");
  			for (int c = 1; c <= 23007; c++)             /* This block of code gives time-out*/
       			for (int d = 1; d <= 23067; d++)                          /* before next line being executed. It also used for nice interface */
      					 {}
      	system("CLS");
        break;
        
        case '3':
			{
		fp = fopen ("Notes.txt","a+");
		int chosen_day, chosen_month, chosen_year;
		system("CLS");
		printf("Enter the day (DD): ");
        scanf("%d", &chosen_day); 
        
        printf("Enter the month (MM): "); 
        scanf("%d", &chosen_month);
        		
		printf("Enter the year (YYYY): ");  
		scanf("%d", &chosen_year);	
				
		char chosen_date[50];  
	    sprintf(chosen_date, "%d/%d/%d", chosen_day, chosen_month, chosen_year ); // this is a spesific function which helps developer to combine int+int and even string+int.
	    char *target= chosen_date;    // target for SEARCHING inside txt file, among notes
	    
	    
  		gotit = 0;
  		while(fgets(buff, BUFSIZ, fp)) {
    		ptr = strstr(buff, target); 
    		if(ptr) {
    			system("CLS");
    			printf("You have note for requested date!\n\n");
    			
    				fp = fopen ("Notes.txt","a+");
    			     char mystring [200];
    			     char name_file[]= "Notes.txt";
					 char *buff= chosen_date;
    					if (fp == NULL) perror ("Error opening file");
    						else
    							{
        						while( fgets (mystring ,200 , fp) != NULL )
        						{
           			 		if ((ptr = strstr (mystring,buff))!=NULL) //if string is found it returns true and prints
            				printf("%s",mystring);
        				}
    				}
    					printf("\nPress any key for Main Menu. ");
  						scanf("\n%c", &choice);
    					system("CLS");
     						fclose (fp);
      			
				  rewind(fp);
      			gotit = 1;
      			break;
   			 }
  		}
  		fflush(fp);
  		fclose(fp);

  		if(!gotit){
    		printf("\nThere is no notes for requested date!\n");
    		printf("\nYou're redirecting to main menu...\n");
  			for (int c = 1; c <= 20007; c++)
       		for (int d = 1; d <= 23067; d++)
      		{}
      	}
      		system("CLS");
  			gotit = getchar(); 
			}
        break;
        
        
        case '4':
        		system("CLS");
        		char str[MAXCHAR];
        	    fp = fopen("Notes.txt", "a+");
    			if (fp == NULL){
        			printf("Could not open file %s","Notes.txt");
        			return 1;
    			}
    			while (fgets(str, MAXCHAR, fp) != NULL)
       			 	printf("%s", str);
    				fclose(fp);
    				
					printf("\nPress any key for Main Menu. ");
  						scanf("\n%c", &choice);
    					system("CLS");
        		break;
        
        case '5':     // This block serves for deleting data. Algorithm of it, is selecting the line, note, which want to be removed 
	       {                 // Algo creates a new txt file, transports all date except selected, note which wants to be deleted, to the new file
		                        // then renaims the new txt file with the new one and removes the old txt file. 
	    system("CLS");
	    char c;
        int del_line, temp = 1;
        fp1 = fopen(filename, "a+");
        c = getc(fp1);
        while (c != EOF)
        {
          printf("%c", c);
          c = getc(fp1);
        }
        
        rewind(fp1);
        
        printf("\n\n*WARNING* You can only delete one notes at each compile for avoiding unnecessary data lose!");
        printf(" \n\nEnter line number of the line to be deleted, or press 'q' for main menu: ");
        scanf("%d", &del_line);
        
  		char delete_line;
  		delete_line = getchar();
		
		if(delete_line == 'q'){      // user can exit to main menu after he delete his/her note
			system("CLS");
		}
		
		else
		
        fp2 = fopen("copy.c", "a+");
        c = getc(fp1);
        
		
        while (c != EOF) {
          c = getc(fp1);
          if (c == '\n')
          temp++;
          // all lines except the line to be deleted
          if (temp != del_line)
          {
            //copy all lines in file copy.c
            putc(c, fp2);
          }
        }
        //close both the files for prevent any bug.
        fclose(fp1);
        fclose(fp2);
        //deletes original file
        remove(filename);
        //rename the file to original name
        rename("copy.c", filename);
        printf("\n The contents of file after being modified are as  follows:\n");
        fp1 = fopen(filename, "r");
        c = getc(fp1);
        while (c != EOF )  {
            printf("%c", c);
            c = getc(fp1);
        }
        fclose(fp1);
        system("CLS");
	    }
	
        break;
        
        case '6':
        	system("CLS");
        	printf("Thank you, Goodbye!");
        	exit(0);	
        break;
        
        default:
        printf("Not a valid option\n"); //For error checking, preventing other inputs
        break;
      }
    }
    return 0;
}
 

