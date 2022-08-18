#include <stdio.h>
#include <time.h>

void subscriptOnly()
{
    // Define a large 2-D array
    int array[100][100];

    // Iterate through each element
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            // Each element is accessed, no operation
            array[i][j];
        }
    }
}

void usingPointers()
{
    // Define a large 2-D array
    int array[100][100];

    // Iterate through each element
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            // Each element is accessed, no operation
            *(*(array+i)+j);
        }
    }

}

void main()
{
    clock_t start, end;
    double timeTaken;

    // For subscript only function
    // Start clock
    start = clock();
    // Run first function several times
    for(int i = 0; i < 100000; i++)
    {
        subscriptOnly();
    }
    // Stop clock
    end = clock();
    // Calculate time used
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken using only subscript references: %f seconds\n", timeTaken);

    // For pointer function
    // Start clock
    start = clock();
    // Run first function several times
    for(int i = 0; i < 100000; i++)
    {
        usingPointers();
    }
    // Stop clock
    end = clock();
    // Calculate time used
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken using pointer references: %f seconds\n", timeTaken);

}