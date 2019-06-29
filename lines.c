/**
* <p>Title: CSC 217 Project 3: "Lines"</p>
* <p>Description: This project takes number of lines from standard input
or from a file and also takes some arguments from main method parameters
and then display those lines on the standard output. If those arguments are
invalid the program will display message in standard error.</p>
* <p>Due 18 Dec 2017 11:59 pm</p>
* @author Jagandeep Singh (N00838342@students.ncc.edu)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100

int main(int argc, char **argv)
{
   FILE *fptr = fopen(argv[argc-1],"r"); //file pointer to store the file to open
   char temp[MAXLINE]; //variable to store the temp string
   int num; //int to print the line number.If the line number matches this number it will print.

   //loops to deal with the duplicates in argv array
   for (int j = 1; j < argc-2; j++)
     for (int k = j + 1; k < argc-1; k++)
         if (strcmp(argv[j],argv[k]) == 0) //if duplicates found
             argv[k] = "0"; // change one of them to 0 so it wont display anything.

   int array[50]; //array of length 50 to store all the line numbers to display.
   int k = 0; // int to track the array indeces.
   int count = 0; //counter to count the total number of lines to display
   int total = 0; //counter to count the total number of lines in file or std input

  if(argc == 1) // if no command line is provided print error message
    fprintf(stderr, "%s Enter the line number(s) and filename.\n",argv[0]);

   if(fptr == NULL) // if fptr is null means no file name was provided and the input is being provided through standard input
   {
     while(fgets(temp,MAXLINE,stdin) != NULL) // while loop to count total number of lines in stdin.
       total++; // incrementing the total int.

     for(int i = 1;i < argc; i++) // for loop to go through all the command lines arguments.
     {
       if((strlen(argv[i]) >= 3) && ((argv[i][1]=='-') ||  (argv[i][2]=='-') || (argv[i][3]=='-')) ) // condition to check if any argument is in form of int-int
       {
         int down = atoi(strtok(argv[i],"-")); // store the int before "-" in down
         int up =  atoi(strtok(NULL,"-")); // store the int after "-" in up
         for(int j = down; j <= up; j++){ // loop to add all numbers from down to up in the array
           array[k++] = j; // add numbers in array
           count++; // incrementing count(number of lines to display)
         }
       }  else if((strlen(argv[i]) >= 2) && (argv[i][0] == '-')) // condition to check if any argument is in form of -int.
         {
           int number = atoi(strtok(argv[i],"-")); // store the int after "-" in number
           for(int j = 1; j <= number;j++){ // loop to add all the numbers in the array.
             array[k++] = j; // add numbers in array
             count++; // incrementing count(number of lines to display)
           }
         } else if((strlen(argv[i]) >= 2) && (argv[i][strlen(argv[i])-1] == '-') ) // condition to check if any argument is in form of int-.
          {
            int number = atoi(strtok(argv[i],"-")); // store the int before "-" in number.
            for(int j = number;j <= total; j++){ // loop to add all the numbers in the array.
              array[k++] = j; // add numbers in array.
              count++; // incrementing count(number of lines to display.)
            }
          }
         else{
          array[k++] = atoi(argv[i]); //if the argument is just a number then just store it in the array.
          count++; // incrementing count.
        }
     }

     for(int i = 0; i < count; i++){ // for loop to go through the array to display all the lines.
       num = 1; // start num from one.
       rewind(stdin); // restart the pointer from the start of the input for each iteration of the loop.
     while(fgets(temp,MAXLINE,stdin) != NULL) // loop to read the lines and keep reading until the end.
     {
       if(num == array[i]){ // condition to check if that line to display
         printf("%s",temp);// print the lines
         break; //when the line is found break the loop
       }
      num++; // incrementing num
     }
    if(array[i] > total) // condition to check if the number
      fprintf(stderr, "%s: No line %d\n",argv[0] , array[i]); //print the error message in stderr
  }
}
  else //if filename was provided
  {
    while(fgets(temp,MAXLINE,fptr) != NULL) // while loop to count total number of lines in the file.
      total++; // incrementing the total int.

    for(int i = 1;i<argc-1;i++) // for loop to go through all the command lines arguments.
    {
      if((strlen(argv[i]) >= 3) && ((argv[i][1]=='-') ||  (argv[i][2]=='-') || (argv[i][3]=='-')) ) // condition to check if any argument is in form of int-int
      {
        int down = atoi(strtok(argv[i],"-")); // store the int before "-" in down
        int up =  atoi(strtok(NULL,"-")); // store the int after "-" in up
        for(int j = down; j <= up; j++) { // loop to add all numbers from down to up in the array
          array[k++] = j; // add numbers in array
          count++; // incrementing count(number of lines to display)
        }
      }
        else if((strlen(argv[i]) >= 2) && (argv[i][0] == '-')) // condition to check if any argument is in form of -int.
        {
          int number = atoi(strtok(argv[i],"-")); // store the int after "-" in number
          for(int j = 1; j <= number;j++){ // loop to add all the numbers in the array.
            array[k++] = j; // add numbers in array
            count++; // incrementing count(number of lines to display)
          }
        }
         else if((strlen(argv[i]) >= 2) && (argv[i][(strlen(argv[i]))-1] == '-') ) // condition to check if any argument is in form of int-.
         {
           int number = atoi(strtok(argv[i],"-")); // store the int before "-" in number.
           for(int j = number;j <= total; j++){ // loop to add all the numbers in the array.
             array[k++] = j; // add numbers in array.
             count++; // incrementing count(number of lines to display.)
          }
        }
        else{
         array[k++] = atoi(argv[i]); //if the argument is just a number then just store it in the array.
         count++; // incrementing count.
       }
    }
    for(int i = 0; i < count; i++){ // for loop to go through the array to display all the lines.
    num = 1; // start num from one.
    rewind(fptr); // restart the pointer from the start of the input for each iteration of the loop.
    while(fgets(temp,MAXLINE,fptr) != NULL) // loop to read the lines and keep reading until the end.
    {
      if(num == array[i]){ // condition to check if that line to display
        printf("%s",temp);// print the lines
        break; //when the line is found break the loop
      }
     num++; // incrementing num
    }

  if(array[i] > total) // condition to check if the number
     fprintf(stderr, "%s: No line %d\n",argv[0] , array[i]); //print the error message in stderr
   }
}
  return 0;
}
