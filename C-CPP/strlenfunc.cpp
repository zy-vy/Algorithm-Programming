#include <stdio.h>
int stringLenght1 (char *string){
    if (*string=='\0')
        return 0;
    else
        return 1 + stringLenght1 (string + 1);
}

int stringLenght2 (char string[],int index){
    if (string[index]=='\0')
        return 0;
    else
        return 1 + stringLenght2 (string,index + 1);
}
int main(){
    char string[100];
    scanf ("%s",&string);

    printf ("string lenght 1: %d\n",stringLenght1(&string[0]));
    printf ("string lenght 2: %d\n",stringLenght2(string,0));

    return 0;
}
