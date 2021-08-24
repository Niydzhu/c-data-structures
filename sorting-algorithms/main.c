/* ------------------------------------------------------------------------- */
/*                                 Includes                                  */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "./src/sort.h"



/* ------------------------------------------------------------------------- */
/*                             Global variables                              */
/* ------------------------------------------------------------------------- */

#define ARRAY_LENGTH 10
#define MAX_RANDOM_VALUE 50



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

void printArray(const char* before, elt_t* array, int arrayLength, const char* after);
void printElement(elt_t element);
void copyArray(elt_t* array1, elt_t* array2, int arrayLength);
bool isSorted(elt_t* array, int arrayLength);
void insertRandomElements(elt_t* array, int arrayLength);



/* ------------------------------------------------------------------------- */
/*                               Main function                               */
/* ------------------------------------------------------------------------- */

int main()
{
    elt_t unsortedArray[ARRAY_LENGTH];
    elt_t testArray[ARRAY_LENGTH];

    // Insert random values in the unsorted array and print it's values
    srand(time(NULL));
    insertRandomElements(unsortedArray, ARRAY_LENGTH);
    printArray("Unsorted array [", unsortedArray, ARRAY_LENGTH, "]\n\n");

    /*
        For each sorting algorithm, copy the unsorted array into
        the test array, sort it, then verify if the array is sorted
        and finally print the sorted values.
    */
    // Bubble sort
    copyArray(testArray, unsortedArray, ARRAY_LENGTH);
    bubbleSort(testArray, ARRAY_LENGTH);
    printf("Bubble sort : %s", isSorted(testArray, ARRAY_LENGTH) ? "OK" : "FAIL");
    printArray(" [", testArray, ARRAY_LENGTH, "]\n");

    // Insertion sort
    copyArray(testArray, unsortedArray, ARRAY_LENGTH);
    insertionSort(testArray, ARRAY_LENGTH);
    printf("Insertion sort : %s", isSorted(testArray, ARRAY_LENGTH) ? "OK" : "FAIL");
    printArray(" [", testArray, ARRAY_LENGTH, "]\n");

    // Selection sort
    copyArray(testArray, unsortedArray, ARRAY_LENGTH);
    selectionSort(testArray, ARRAY_LENGTH);
    printf("Selection sort : %s", isSorted(testArray, ARRAY_LENGTH) ? "OK" : "FAIL");
    printArray(" [", testArray, ARRAY_LENGTH, "]\n");

    // Quick sort
    copyArray(testArray, unsortedArray, ARRAY_LENGTH);
    quickSort(testArray, ARRAY_LENGTH);
    printf("Quick sort : %s", isSorted(testArray, ARRAY_LENGTH) ? "OK" : "FAIL");
    printArray(" [", testArray, ARRAY_LENGTH, "]\n");

    // Merge sort
    copyArray(testArray, unsortedArray, ARRAY_LENGTH);
    mergeSort(testArray, ARRAY_LENGTH);
    printf("Merge sort : %s", isSorted(testArray, ARRAY_LENGTH) ? "OK" : "FAIL");
    printArray(" [", testArray, ARRAY_LENGTH, "]\n");

    return 0;
}



/* ------------------------------------------------------------------------- */
/*                                Functions                                  */
/* ------------------------------------------------------------------------- */

/**
 * @brief Prints the values of an array.
 * @param before String to print before the array
 * @param array Pointer on the array
 * @param arrayLength Length of the array
 * @param after String to print after the array
 */
void printArray(const char* before, elt_t* array, int arrayLength, const char* after)
{
    printf("%s", before);
    for (int i = 0; i < arrayLength; i++) {
        printElement(array[i]);
        if (i < arrayLength - 1)
            printf(" ");
    }
    printf("%s", after);
}



/**
 * @brief Prints an element.
 * @param element The element
 */
void printElement(elt_t element)
{
    printf("%d", element);
}



/**
 * @brief Copies each element of the first array to the second one.
 * @param array1 Pointer on the first array
 * @param array2 Pointer on the second array
 * @param arrayLength Length of the second array
 */
void copyArray(elt_t* array1, elt_t* array2, int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        _assignElements(&array1[i], &array2[i]);
}



/**
 * @brief Determines if an array is sorted.
 * @param array Pointer on the array
 * @param arrayLength Length of the array
 * @return True if the array is sorted, false if not.
 */
bool isSorted(elt_t* array, int arrayLength)
{
    for (int i = 1; i < arrayLength; i++)
        if (_compareElements(array[i], array[i - 1]) < 0)
            return false;
    return true;
}



/**
 * @brief Inserts elements with random values in an array.
 * @param array Pointer on the array
 * @param arrayLength Length of the array
 */
void insertRandomElements(elt_t* array, int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        array[i] = rand() % MAX_RANDOM_VALUE;
}
