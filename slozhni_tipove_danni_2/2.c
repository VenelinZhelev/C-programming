#include<stdio.h>
#include<string.h>

typedef struct Node {
  char name[20];
  struct Node * father;
  struct Node * mother;
  struct Node * marriedto;
} Fam_Member;

int main(){
    Fam_Member az;
    Fam_Member mother;
    strcpy(az.name, "Venelin");
    strcpy(mother.name, "Veselina");
    az.father = NULL;
    az.mother = &mother;
    az.marriedto = NULL;

    mother.father = NULL;
    mother.mother = NULL;
    mother.marriedto = NULL;
    return 0;
}