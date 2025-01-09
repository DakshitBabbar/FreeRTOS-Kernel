#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "remote_config.h"

ConfigStruct_t myConfigStruct = {0};

void initialiseConfigStruct(void)
{
    // file pointer variable to store the value returned by
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("/Users/dakshba/Desktop/work/Playground/hackathon/Lab-Project-FreeRTOS-Tutorials/source/tutorials/tutorial_2/source/rconf.csv", "r");

    //buffer to store a line read from the file
    char line[MAX_LINE_LENGTH];

    //buffers to store the key and value read from a line
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    printf("Parsing the Key value pairs from the file into struct:\n");
    printf("----------------\n");

    // Read the file line by line
    while (fgets(line, sizeof(line), fptr)) 
    {
        // Remove the newline character, if any
        // line[strcspn(line, "\n")] = '\0';

        // Parse the line into key and value
        sscanf(line, "%[^,],%s", key, value);  // Split at the comma
        
        if(strcmp(key, "delayTimeMs") == 0)
        {
            myConfig->delayTimeMs = atoi(value);
        }
        else if(strcmp(key, "enableLogging") == 0)
        {
            myConfig->enableLogging = atoi(value);
        }
    }

    // Close the file
    fclose(fptr);
}
