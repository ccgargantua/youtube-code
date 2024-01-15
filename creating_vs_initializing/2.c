// From "To malloc or not to malloc? Creating vs initializing"
// https://youtu.be/-ISdOVeRizg?si=V0LVXWRtyUjMNrEO




// In the video, I mistakenly included <stdbool.h>
// That has been omitted here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct
{
    char *data;
    unsigned int length;
} MyString;




// In the video, I mistakenly copied over ReturnCode enum,
// even though it was not used. It has been omitted.




// Now we return a pointer to allocated memory
MyString *create_string(const char *data, unsigned int len)
{
    // No return codes :(
    if(data == NULL) return NULL;

    MyString *string = malloc(sizeof(MyString));
    string->length = len;
    string->data = malloc(len+1);

    memcpy(string->data, data, len);
    string->data[len] = '\0';

    return string;
}




// Usually you see a function for freeing
// the memory
void destroy_string(MyString *string)
{
    if(string == NULL) return;

    free(string->data);
    free(string);
}




int main()
{
    MyString *string = create_string("Hello world\n", 11);
    printf("'%s' is %d characters long\n", string->data, string->length);
    destroy_string(string);
    return 0;
}