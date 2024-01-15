// From "To malloc or not to malloc? Creating vs initializing"
// https://youtu.be/-ISdOVeRizg?si=V0LVXWRtyUjMNrEO




#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct
{
    char data[256];
    unsigned int length;
} MyString;




typedef enum
{
    SUCCESS,
    FAILURE,
} ReturnCode;




ReturnCode init_string(MyString *string, const char *data, unsigned int len)
{
    if(string == NULL || data == NULL) return FAILURE;
    if(len >= 256) return FAILURE;

    string->length = len;
    memcpy(string->data, data, len);
    string->data[len] = '\0';

    return SUCCESS;
}




int main()
{
    MyString string;
    init_string(&string, "Hello world", 11);
    printf("'%s' is %d characters long\n", string.data, string.length);

    MyString *string2 = malloc(sizeof(MyString));
    init_string(string2, "Goodbye world", 13);
    printf("'%s' is %d characters long\n", string2->data, string2->length);
    free(string2);
}