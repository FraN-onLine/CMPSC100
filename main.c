#include <stdio.h> //input output
#include <stdlib.h> //standard library for screen clearing
#include <string.h> //string commands like strcmp and strcpy
#include <ctype.h> //pang toupper lang (check while statement)
#include <time.h> //temporary addition, ewan ko kung gusto niyo mag rand
// yung system clear is papalitin to cls pag sa dev c++

struct studentinfo {
    char surname[50];
    char lowercased_surname[50]; 
    char firstname[50];
    char middlename[50];
    char sex[10];
    char studentid[50];
    int age;
    char birthday[50];
    char email[50];
    char info[100];
    char compsci[100];
    char motto[200];
    int answered; //flag for answered
    char attend[50];
};//struct data type, lahat na maiinitialize pag ginamit ang struct

//void is no return type. "*" ay pointer if magagalaw ang "student" magagalaw ang data ng studentdata ng main
void StudentData(struct studentinfo *student) {
      student[0] = (struct studentinfo)  {"Meow", "meow", "meow", "meow", "M", "23-696969",18, "6 9, 2005", "6969@gmail.com", "69", "69", "69.",1,"Attendance Not Checked"};
}; //list of students in CS1-A including relevant information (omitted for privacy reasons

int main() {
struct studentinfo studentdata[47]; //struct initialization as studentdata

StudentData(studentdata); //function calling and initialization

    int function; //choice of one of the presented "functions" of the systems
    int attcheck = 0; //checks if attendance has been taken today, if 0, takes attendance, if 1, displays taken attendance (serves as a flag if attendance was already taken)
    char surname[100]; //surname malamang
    int present = 0; //good student
    int absent = 0; //bad student
    int totalenrolled = 0; //all students
    int indatabase = 0; //checks if student is in CS1-A
    int loopdatabase = 0; //how many loops

   srand(time(NULL));
    int rando; //random number generates from 0(Acidera) to 46(Verdadero)
    int randamt; //regarding randomizer, temporary test lang
    int flagg[46];
 
  
    do {
       system("cls"); //change to cls, cls- windows, clear- linux
      printf("------------------------------------------------------------------\n\n ");
      printf("\tStudent Information and Attendance Monitoring System\n\n\n");
      printf("\t\t[1] Student Database\n\t\t[2] Student Attendance\n\t\t[3] Random Student\n\t\t[4] Terminate Program\n\n------------------------------------------------------------------\n\n");
      
       do {
       printf("\tEnter: ");
       if (scanf("%d", &function) !=1){
         getchar(); //buffer
         function = 0; //input validation for characters(sets function as 0 if the user did not input a int value/ %d)
       }

       if(function < 1 || function > 4) {
         printf("\nInvalid Input. Please select either 1-4\n\n"); //input validation for numbers
       }
      } while(function < 1 || function > 4); //will not proceed if not 1,2,3,4 (maiadjust when tatangallin yung 3)
        
      getchar(); 

      printf("\n\n");
      system("cls"); //change to cls, cls- windows, clear- linux
    switch (function) {

      case 1:
        
          printf("        [Welcome To The Student Information Database]         \n\n\n");
          printf("How many students do you want to search: ");
          scanf("%d", &loopdatabase);
          printf("\n");
        for(int x = 0; x < loopdatabase; x++) {
          printf("Enter a surname/student id to search: ");
          scanf("%s", &surname);

          indatabase = 0;
             for (int i = 0; i < 47; ++i) {
               //goes through all 47 students checking if input is the same as string 
              if (strcmp(surname, studentdata[i].surname) == 0||strcmp(surname, studentdata[i].lowercased_surname) == 0||strcmp(surname, studentdata[i].studentid) == 0) {
               printf("\n\nInformation for: %s, %s %s:\n", studentdata[i].surname, studentdata[i].firstname, studentdata[i].middlename);
               printf("Sex: %s\n",studentdata[i].sex);
               printf("Student Number: %s\n", studentdata[i].studentid);
               printf("Email Address: %s\n", studentdata[i].email);
               printf("Attendance Today: %s\n", studentdata[i].attend);
                if(studentdata[i].answered == 1) {
                 printf("Age: %d\n", studentdata[i].age);
                 printf("Birthday: %s\n", studentdata[i].birthday);
                 printf("Self Desciption: %s\n", studentdata[i].info);
                 printf("Why CompSci?: %s\n", studentdata[i].compsci);
                 printf("Motto: %s\n", studentdata[i].motto);
                  //only shows data when answered
                 }
              indatabase = 1;
              break;
             }
            }

      if (!indatabase) {
          printf("Student not found on the CS1-A Database.\n");
      }
           printf("\n-------------------------------------------------------------------\n\n");
        }

          break;

      case 2:

      if (attcheck == 0) {
           printf("                    [Attendance Sheet]            \n\n[P] Present\n[A] Absent\n[N] Not Enrolled\n");
        for ( int i = 0; i < 47; ++i) {
           //goes through all 47 students
          do {
            printf ("\n%d. %s, %s : ",i + 1,studentdata[i].surname, studentdata[i].firstname);
           scanf("%s", &studentdata[i].attend);
           
           studentdata[i].attend[0] = toupper(studentdata[i].attend[0]); //converts lowercase input as uppercase

          if (strcmp(studentdata[i].attend, "P") == 0) {
            strcpy(studentdata[i].attend, "Present");
          present++;
          totalenrolled++; //if present, present counter, enroll counter up
          }
          else if (strcmp(studentdata[i].attend, "A") == 0) {
            strcpy(studentdata[i].attend, "Absent");
          absent++;
          totalenrolled++; //ctrl c ctrl v but absent
          } 
          else if (strcmp(studentdata[i].attend, "N") == 0) {
          strcpy(studentdata[i].attend, "Not Enrolled");
              } 
          else { printf("Please enter either P, A or N\n");}
          } while (strcmp(studentdata[i].attend, "Present") != 0 && strcmp(studentdata[i].attend, "Absent") != 0 && strcmp(studentdata[i].attend, "Not Enrolled") != 0);
        }; //loops if the value is neither present, absent or NE, if one is true, proceed (input validation)

        printf("\nTotal students enrolled in class: %d\n", totalenrolled);
        printf("\nTotal present in class: %d\n", present);
        printf("\nTotal absent in class: %d\n", absent);
        attcheck = 1;

        FILE *attendancefile = fopen("attendance.txt", "w");

        for (int i = 0; i < 47; ++i) {
        fprintf(attendancefile, "%s, %s: %s\n", studentdata[i].surname,studentdata[i].firstname, studentdata[i].attend);
           }
         fclose(attendancefile); //file saving

      } else {
        printf("                    [Attendance Sheet]            \n");
        for ( int i = 0; i < 47; ++i) {
          printf ("\n%d. %s, %s : %s ",i + 1,studentdata[i].surname, studentdata[i].firstname, studentdata[i].attend);
        }
          printf("\n\nTotal students enrolled in class: %d\n", totalenrolled);
          printf("\nTotal present in class: %d\n", present);
          printf("\nTotal absent in class: %d\n", absent);
      }
        printf("\n-------------------------------------------------------------------\n\n");

        break;

      case 3:
         printf("                      [Student Randomizer] \n\n");
        do {
         printf("How many students would you like to randomize? ");
         if (scanf(" %d", &randamt) !=1)
         { getchar(); randamt = 0; }
          if(randamt < 1 || randamt > 47) {
            printf("Please select a number within 1-47\n");
          }
        } while ( randamt < 1 || randamt > 47);
        for ( int i = 0; i < randamt; ++i) {

          do {
        rando = rand() % 47; //modulo opt, gets within 0-46
          } while (flagg[rando] == 1);
          
      printf("Random student: %s, %s\n", studentdata[rando].surname, studentdata[rando].firstname);
          flagg[rando] = 1;
        }
        printf("\n-------------------------------------------------------------------\n\n");
        //try lang ewan ko kung maikeep para sa fina;
      break;

      case 4:
        printf("\nTerminating....\n");
        getchar();
        system("cls");
        
       return 0;

      default:
        system("cls");
        return 0;

      }

    getchar();
     printf("\n[R] Restart Program\nPress any other key to exit....\n");
    } while( toupper(getchar ()) == 'R'); //restarts if R is selected

  system ("cls");
    return 0;
}
