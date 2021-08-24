/* ------------------------------------------------------------------------- */
/*                          Include the header file                          */
/* ------------------------------------------------------------------------- */

#include "sort.h"



/* ------------------------------------------------------------------------- */
/*                        Local functions prototypes                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Swaps the values of 2 elements.
 * @param elt1 Pointer on an element
 * @param elt2 Pointer on an element
 */
void _swapElements(elt_t* elt1, elt_t* elt2);

/**
 * @brief Assigns the value of the second element to the first element.
 * @param elt1 Pointer on an element
 * @param elt2 Pointer on an element
 */
void _assignElements(elt_t* elt1, elt_t* elt2);

/**
 * @brief Compare the value of 2 elements.
 * @param elt1 The first element
 * @param elt2 The second element
 * @return An integer greater than 0 if the first element
 * is greater than the second. An integer fewer than 0 if the first element
 * is smaller than the second. 0 if both elements are equal.
 */
int _compareElements(elt_t elt1, elt_t elt2);

/**
 * @brief Sorts an array using the quick sort.
 * @param array Pointer on the array to sort
 * @param first Index of the start of the array to sort
 * @param last Index of the end of the array to sort
 */
void _quickSort(elt_t* array, int first, int last);

/**
 * @brief Sorts an array using the merge sort.
 * @param array Pointer on the array to sort
 * @param first Index of the start of the array to sort
 * @param last Index of the end of the array to sort
 */
void _mergeSort(elt_t* array, int first, int last);

/**
 * @brief
 * @param array Pointer on the array
 * @param first Index of the start of the array
 * @param first Index of the middle of the array
 * @param last Index of the end of the array
 */
void _merge(elt_t* array, int first, int middle, int last);



/* ------------------------------------------------------------------------- */
/*                           Functions definitions                           */
/* ------------------------------------------------------------------------- */

void _swapElements(elt_t* elt1, elt_t* elt2)
{
    elt_t temp;
    _assignElements(&temp, elt1);
    _assignElements(elt1, elt2);
    _assignElements(elt2, &temp);
}



void _assignElements(elt_t* elt1, elt_t* elt2)
{
    *elt1 = *elt2;
}



int _compareElements(elt_t elt1, elt_t elt2)
{
    return elt1 - elt2;
}



void bubbleSort(elt_t* array, int arrayLength)
{
    for (int i = arrayLength - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (_compareElements(array[j + 1], array[j]) < 0)
                _swapElements(&array[j + 1], &array[j]);
}



void insertionSort(elt_t* array, int arrayLength)
{
    elt_t temp;
    for (int i = 1; i < arrayLength; i++) {
        _assignElements(&temp, &array[i]);
        int j = i;
        while (j > 0 && _compareElements(array[j - 1], temp) > 0) {
            _swapElements(&array[j], &array[j - 1]);
            j--;
        }
        _assignElements(&array[j], &temp);
    }
}



void selectionSort(elt_t* array, int arrayLength)
{
    for (int i = 0; i < arrayLength - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arrayLength; j++)
            if (_compareElements(array[j], array[min]) < 0)
                min = j;
        if (min != i)
            _swapElements(&array[i], &array[min]);
    }
}



void quickSort(elt_t* array, int arrayLength)
{
    _quickSort(array, 0, arrayLength - 1);
}



void _quickSort(elt_t* array, int first, int last)
{
    if (first < last) {
        int i, j, pivot;

        i = pivot = first;
        j = last;

        while (i < j) {
            while (_compareElements(array[i], array[pivot]) <= 0 && i < last)
                i++;
            while (_compareElements(array[j], array[pivot]) > 0)
                j--;
            if (i < j)
                _swapElements(&array[i], &array[j]);
        }
        _swapElements(&array[pivot], &array[j]);

        _quickSort(array, first, j - 1);
        _quickSort(array, j + 1, last);
    }
}



void mergeSort(elt_t* array, int arrayLength)
{
    _mergeSort(array, 0, arrayLength - 1);
}



void _mergeSort(elt_t* array, int first, int last)
{
    if (first < last) {
        // Finding middle element
        int middle = first + (last - first) / 2;

        // Recursively sorting both the halves
        _mergeSort(array, first, middle);
        _mergeSort(array, middle + 1, last);

        // Merge the array
        _merge(array, first, middle, last);
    }
}



void _merge(elt_t* array, int first, int middle, int last)
{
    int i, j, k;
    int n1 = middle - first + 1;
    int n2 = last - middle;
    elt_t temp1[n1], temp2[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        _assignElements(&temp1[i], &array[first + i]);
    for (j = 0; j < n2; j++)
        _assignElements(&temp2[j], &array[middle + 1 + j]);

    // Merge the temp arrays
    i = j = 0;
    k = first;
    while (i < n1 && j < n2) {
        if (_compareElements(temp1[i], temp2[j]) <= 0) {
            _assignElements(&array[k], &temp1[i]);
            i++;
        }
        else {
            _assignElements(&array[k], &temp2[j]);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of temp1[]
    while (i < n1) {
        _assignElements(&array[k], &temp1[i]);
        i++; k++;
    }

    // Copy the remaining elements of temp2[]
    while (j < n2) {
        _assignElements(&array[k], &temp2[j]);
        j++; k++;
    }
}
