#include <stdio.h>
#include <stdlib.h>

int main(){
        int b;
        do{
printf("How many grades are there?:");
scanf("%d",&b);
  }while(b>0);
   float * grades = (float *)calloc(b,sizeof(float));
   if(grades==NULL){
    printf("error");
    return 1;
   }

for(int i=1;i<=b;i++){
    printf("ocenka %d e:",i);
    scanf("%f",&grades[i]);
}
int choice;
do{
printf("What do you want?: 1-da vidish sredniq uspeh 2-to add a new grade 3-to delete a grade 4-exit:");
scanf("%d",&choice);
}while(choice<1||choice>4);
switch(choice){
case 1:
    float * averageGrade = (float *)malloc(sizeof(float));
    float sum=0;
    for(int i=0;i<=b;i++){
        sum=sum+grades[i];
    }
    *averageGrade=sum/b;
    printf("srednata e:%f",*averageGrade);
    free(averageGrade);
    break;
case 2:
     grades = (float *)realloc(grades, (b + 3)*sizeof(float));
      if (grades == NULL) {
    printf("error\n");
    return 1;
  }
 for (int i = b; i < b+1; i++) {
    printf("Please enter value for new newgrades[%d]:", i+1);
    scanf("%f", &grades[i]);
  }
  break;
case 3:
if(b>1){
    b=b-1;
    printf("The last grade is deleted");
}else{
    printf("error");
}
break;
case 4:
printf("you exited from the programm");
break;
}
    return 0;
}
