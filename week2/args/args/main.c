//
//  main.c
//  args
//
//  Created by Aurélien Ammeloot on 09/02/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double add(double *nums, int size)
{
    double result = 0.0;
    int index;
    for(index = 0; index < size; index++)
    {
        result += nums[index];
    }
    return result;
}

double subtract(double *nums, int size)
{
    return 0.0;
}

double multiply(double *nums, int size)
{
    return 0.0;
}

double divide(double *nums, int size)
{
    // ATTENTION need to deal with division by zero
    
    return 0.0;
}

int main(int argc, const char * argv[])
{
    // Index for the loop
    int index;
    const char *verb;
    double *numbers;
    double currentNum, result;
    
    // Analyse the command line arguments
    if(argc < 4) // Insufficient arguments
    {
        printf("Error: insufficent number of arguments.\n");
        exit(2);
    }
    else
    {
        // Sufficient arguments
        verb = argv[1];
        
        // Allocate the numbers array with the correct amount of doubles
        // Careful with memory leaks
        numbers = (double*)malloc((argc - 2) * sizeof(double));
        
        // Collect the remaining strings and convert them to doubles
        for (index = 2; index < argc; index++)
        {
            // Take the argument at index and convert to a double
            currentNum = atof(argv[index]);
            numbers[index - 2] = currentNum;
        }
        
        // if / else if / else
        // Potential exit if the verbs are not correct
        
        if(strcmp(verb, "add") == 0  || strcmp(verb, "addition") == 0)
        {
            result = add(numbers, argc-2);
            printf("%lf\n", result);
        }
    }
    
    
    
    free(numbers);
    exit(0);
}
