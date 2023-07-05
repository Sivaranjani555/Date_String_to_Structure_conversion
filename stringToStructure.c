#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct my_date_t
{
    uint8_t date;      
    uint8_t month;      
    uint16_t year;      
} my_date_t;

typedef enum status_t
{
    // Function has successfully converted the string to structure 
    SUCCESS, 
    // Function is given NULL pointers to work with 
    NULL_PTR, 
    //Incorrect values for date or month or year 
    INCORRECT           
} status_t;

status_t string_to_date_converter(char* input_String, my_date_t* result_date)
{
    if (input_String == NULL || result_date == NULL)
        return NULL_PTR;

    char* token = strtok(input_String, "/");
    if (token == NULL)
        return INCORRECT;

    result_date->date = atoi(token);
    if (result_date->date < 1 || result_date->date > 31)
        return INCORRECT;

    token = strtok(NULL, "/");
    if (token == NULL)
        return INCORRECT;

    result_date->month = atoi(token);
    if (result_date->month < 1 || result_date->month > 12)
        return INCORRECT;

    token = strtok(NULL, "/");
    if (token == NULL)
        return INCORRECT;

    result_date->year = atoi(token);
    if (result_date->year < 0)
        return INCORRECT;

    return SUCCESS;
}

int main()
{
    printf("Enter input as a format of : DD/MM/YYYY\n");
    char input_String[20];
    scanf("%s", input_String);
    my_date_t result_date;

    status_t status = string_to_date_converter(input_String, &result_date);
    
    if (status == SUCCESS)
    {
        printf("Date: %d\n", result_date.date);
        printf("Month: %d\n", result_date.month);
        printf("Year: %d\n", result_date.year);
    }
    else if (status == NULL_PTR)
    {
        printf("Error: NULL pointers\n");
    }
    else if (status == INCORRECT)
    {
        printf("Error: Incorrect values for date, month, or year\n");
    }

    return 0;
}