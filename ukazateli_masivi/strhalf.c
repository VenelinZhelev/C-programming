#include <stdio.h>
#include <string.h>

void strhalf(char *str, char **doublep) {
    int len = 0;
    for (;*str != '\0';str++)
    {
        len++;
    }
    len = len / 2;
    *doublep = str - len;
}

int main() {
    char str[] = "Ivan";
    char *p;
    strhalf(str, &p);
    printf("%s", p);
    return 0;
}