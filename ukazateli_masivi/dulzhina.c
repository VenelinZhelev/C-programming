#include <stdio.h>
#include <string.h>

int len(char *arr)
{
    int len = 0;
    for (;*arr != '\0';arr++)
    {
        len++;
    }
    return len;
}

int main()
{
    char arr[] = "Vasko";
    printf("%d\n", len(arr));
    return 0;
}