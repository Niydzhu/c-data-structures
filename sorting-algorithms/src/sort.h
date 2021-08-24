/**
 * @file    sort.h
 * @brief   Sorting algorithms on arrays.
 * @date    2021-08-07
 *
 */

/* ------------------------------------------------------------------------- */
/*                                Definitions                                */
/* ------------------------------------------------------------------------- */

/**
 * @typedef elt_t
 * @brief Element type
 */
typedef int elt_t;



/* ------------------------------------------------------------------------- */
/*                                Prototypes                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Sorts an array using the bubble sort.
 * @param array Pointer on the array to sort
 * @param arrayLength Length of the array
 */
void bubbleSort(elt_t* array, int arrayLength);

/**
 * @brief Sorts an array using the insertion sort.
 * @param array Pointer on the array to sort
 * @param arrayLength Length of the array
 */
void insertionSort(elt_t* array, int arrayLength);

/**
 * @brief Sorts an array using the selection sort.
 * @param array Pointer on the array to sort
 * @param arrayLength Length of the array
 */
void selectionSort(elt_t* array, int arrayLength);

/**
 * @brief Sorts an array using the quick sort.
 * @param array Pointer on the array to sort
 * @param arrayLength Length of the array
 */
void quickSort(elt_t* array, int arrayLength);

/**
 * @brief Sorts an array using the merge sort.
 * @param array Pointer on the array to sort
 * @param arrayLength Length of the array
 */
void mergeSort(elt_t* array, int arrayLength);
