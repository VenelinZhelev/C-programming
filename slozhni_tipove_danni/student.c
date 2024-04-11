#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGHT 15

typedef struct {
char name[MAX_LENGHT];
int number;
float avg;
}Student;

int main(void)
{
  int student_num = 0;
  Student *students = NULL;
  int choice;
  do
    {
      printf("\n Menu:");
      printf("\n 1. Adding a student.");
      printf("\n 2. Printing the list of students.");
      printf("\n 3.Exit");
      printf("\n Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
        {
          case 1: printf("\n Enter the name of the student: ");
          char name[MAX_LENGHT];
          scanf("%s", name);
          
          printf("\n Enter the number of the student in class: ");
          int number;
          scanf("%d",&number);
          
          printf("\n Enter the average of the student: ");
          float avg;
          scanf("%f",&avg);

          students = (Student *)realloc(students, (student_num + 1) * sizeof(Student));
          if(students == NULL)
          {
            printf("\n Error allocating memory.");
            return 1;
          }
          strcpy(students[student_num].name, name);
          students[student_num].number = number;
          students[student_num].avg = avg;
          student_num++;
          printf("\n The student was added!");
          break;

          case 2: if(student_num == 0)
          {
            printf("\n There aren't any students in the list.");
          }
          else
          {
            printf("\n The list of students is: ");
            for(int i = 0;i<student_num;i++)
              {
                printf("\nName: %s\n Number: %d\n Average: %.2f\n", students[i].name, students[i].number, students[i].avg);
              }
          }
          break;
          case 3: printf("\n Exiting the program.");
          break;
          
          default: printf("\n Invalid choice.");break;
        }
      
    }
    while(choice!=3);
  free(students);
  return 0;
}