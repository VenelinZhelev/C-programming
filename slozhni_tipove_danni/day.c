#include<stdio.h>
 enum Weekday{
  SUNDAY = 1,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
};
int main(){
    int a=0;
    printf("Enter the day:");
    do{
        scanf("%d",&a);
    }while(a<1||a>7);
    enum Weekday currentday;
    currentday=a;
    switch (a)
    {
    case MONDAY:
        printf("Monday");
        break;
    case TUESDAY: 
        printf("Tuesday");
        break;
    case WEDNESDAY:
        printf("Wednesday");
        break;
    case THURSDAY:
        printf("Thursday");
        break;
    case FRIDAY:
        printf("Friday");
        break;
    case SATURDAY:
        printf("Saturday");
        break;
    case SUNDAY:
        printf("Sunday");
        break;
    default:
        break;
    }
}