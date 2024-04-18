#include <stdio.h>
#include <string.h>

typedef struct participant
{
    char name[15];
    char fat_name[15];
    char surname[15];
    char email[25];
    int tel_number;
} Participant;

typedef enum bool {
  false = 0,
  true = 1
} Bool;

typedef struct reply
{
    Participant person;
    Bool answer;
} Reply;


typedef struct cause
{
    char name[10];
    char desc[30];
    struct 
    {
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minutes;
        } timeOfTheDay;
    } time;
    Reply replies[100];
} Cause;

void print_participant(Participant person)
{
    printf("Name: %s\n", person.name);
    printf("Fathers name: %s\n", person.fat_name);
    printf("Surname: %s\n", person.surname);
    printf("Email: %s\n", person.email);
    printf("Telephone number: %d\n", person.tel_number);
}

void print_cause(Cause ninja)
{
    printf("Name: %s\n", ninja.name);
    printf("Description: %s\n", ninja.desc);
    printf("Day: %d\n", ninja.time.day);
    printf("Month: %d\n", ninja.time.month);
    printf("Year: %d\n", ninja.time.year);
    printf("Hour: %d\n", ninja.time.timeOfTheDay.hour);
    printf("Minute: %d\n", ninja.time.timeOfTheDay.minutes);
    printf("\nParticipants: \n");
    int len = sizeof(ninja.replies) / sizeof(ninja.replies[0]);
    for(int i=0; i<1; i++)
    {
        print_participant(ninja.replies[i].person);
        if(ninja.replies[i].answer == 1)
            printf("This participant will take a part in this cause");
        else
            printf("This participant will won't take a part in this cause");
        printf("\n");
    }
}

int main()
{
    Cause ninja ={.name ="Az", .desc="krasavec"};
    ninja.time.day = 1;
    ninja.time.month = 1;
    ninja.time.year = 1;
    ninja.time.timeOfTheDay.hour = 12;
    ninja.time.timeOfTheDay.minutes = 30;

    strcpy(ninja.replies[0].person.name, "Papi");
    strcpy(ninja.replies[0].person.fat_name, "Hans");
    strcpy(ninja.replies[0].person.surname, "____");
    strcpy(ninja.replies[0].person.email, "papi@papi.gov");
    ninja.replies[0].person.tel_number = 112;
    ninja.replies[0].answer = 1;

    Cause ninja2 ={.name="Ti", .desc="hubavec"};
    ninja2.time.day = 31;
    ninja2.time.month = 12;
    ninja2.time.year = 2024;
    ninja2.time.timeOfTheDay.hour = 23;
    ninja2.time.timeOfTheDay.minutes = 59;

    strcpy(ninja2.replies[0].person.name, "Atanas");
    strcpy(ninja2.replies[0].person.fat_name, "Ananas");
    strcpy(ninja2.replies[0].person.surname, "Atanosov");
    strcpy(ninja2.replies[0].person.email, "naseto@ananas.atanosov");
    ninja2.replies[0].person.tel_number = 911;
    ninja2.replies[0].answer = 0;
    
    print_cause(ninja);

    print_cause(ninja2);

    return 0;
}