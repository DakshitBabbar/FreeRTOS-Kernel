#

#include <stdbool.h>

#define MAX_LINE_LENGTH 256  // Maximum length of a line in the CSV file
#define MAX_KEY_LENGTH 128  // Maximum length of a key
#define MAX_VALUE_LENGTH 128  // Maximum length of a value

typedef struct ConfigStruct{
    int delayTimeMs;
    int enableLogging;
} ConfigStruct_t;

extern ConfigStruct_t myConfigStruct;

#define myConfig ( &myConfigStruct )

#ifndef DELAY_TIME_MS
    #define DELAY_TIME_MS ( myConfig->delayTimeMs )
#endif

#ifndef ENABLE_LOGGING
    #define ENABLE_LOGGING ( myConfig->enableLogging )
#endif

void initialiseConfigStruct(void);
