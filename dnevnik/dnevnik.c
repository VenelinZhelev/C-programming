#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int sub;
  int stud = 0;
  do {
    printf("How many subjects are there:");
    scanf("%d", &sub);
  } while (sub < 1);
  char **pp = (char **)malloc(sizeof(char *) * sub);
  if (pp == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }
  for (int i = 0; i < sub; i++) {
    pp[i] = (char *)malloc(sizeof(char) * 15);
    if (pp[i] == NULL) {
      printf("Error allocating memory\n");
      return 1;
    }
    scanf("%s", pp[i]);
  }
  int op;
do{
  printf("Choose an option: 1-Add a student 2-Print the record book 3-exit:");
  scanf("%d",&op);
}while(op<1||op>3);
char **students = NULL;
  int studentCount = 0;

  float **marks = NULL;

switch(op){
case 1: 

  // Adding a student
  studentCount++;
  students = (char **)realloc(students, sizeof(char *) * studentCount);
  if (students == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  students[studentCount - 1] = (char *)malloc(sizeof(char) * 15);
  scanf("%s", students[studentCount - 1]);

  marks = (float **)realloc(marks, sizeof(float *) * studentCount);
  if (marks == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }
  marks[studentCount - 1] = (float *)malloc(sizeof(float) * sub);
  for (int i = 0; i < sub; i++) {
    scanf("%f", &marks[studentCount - 1][i]);
  } 
  

  case 2:
  // Printing the record book
  printf("%-15s", "");
  for (int i = 0; i < sub; i++) {
    printf("%-15s ", pp[i]);
  }
  for (int i = 0; i < studentCount; i++) {
    printf("\n%-15s", students[i]);
    for (int j = 0; j < sub; j++) {
      printf("%-15.2f ", marks[i][j]);
    }
  }
break;
  case 3:

printf("You succefuly exit the program and cleaned the space");
  // Freeing the memory
  for (int i = 0; i < sub; i++) {
    free(pp[i]);
  }
  free(pp);

  for (int i = 0; i < studentCount; i++) {
    free(students[i]);
    free(marks[i]);
  }
  free(marks);
  free(students);
  break;
}
  

  
}