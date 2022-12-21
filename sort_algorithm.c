#include <stdio.h>
int Partition(int array[], int p, int r)
{
    int pivot = array[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[r];
    array[r] = temp;

    return (i + 1);
}

void QuickSort(int array[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = Partition(array, p, r);
        QuickSort(array, p, q - 1);
        QuickSort(array, q + 1, r);
    }
}

void merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        M[j] = array[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

void heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {

        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i >= 0; i--)
    {

        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
    }
}

void main()
{
    int array[30];
    int orig_array[30];
    int n;
    int choice;

    printf("\nEnter the size of the Array: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the Array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &orig_array[i]);
    }

    do
    {
        printf("\n------ Algorithm List ------ ");
        printf("\n1). Bubble Sort");
        printf("\n2). Selection Sort");
        printf("\n3). Insertion Sort");
        printf("\n4). Quick Sort");
        printf("\n5). Merge Sort");
        printf("\n6). Heap Sort");
        printf("\n7). Exit");

        printf("\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                array[i] = orig_array[i];
            }

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            printf("\nThe Elements in the Array(Bubble Sort)\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", array[i]);
            }

            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                array[i] = orig_array[i];
            }

            for (int i = 0; i < n - 1; i++)
            {
                int pos = i;

                for (int j = i + 1; j < n; j++)
                {
                    if (array[j] < array[pos])
                    {
                        pos = j;
                    }
                }

                if (i != pos)
                {
                    int temp = array[pos];
                    array[pos] = array[i];
                    array[i] = temp;
                }
            }

            printf("\nThe Elements in the Array(Selection Sort)\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", array[i]);
            }

            break;

        case 3:
            for (int i = 0; i < n; i++)
            {
                array[i] = orig_array[i];
            }

            for (int i = 1; i < n; i++)
            {
                int temp = array[i];
                int j = i - 1;

                while (j >= 0 && temp <= array[j])
                {
                    array[j + 1] = array[j];
                    j = j - 1;
                }
                array[j + 1] = temp;
            }
            printf("\nThe Elements in the Array(Insertion Sort)\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", array[i]);
            }

            break;

        case 4:
            for (int i = 0; i < n; i++)
            {
                array[i] = orig_array[i];
            }

            QuickSort(array, 0, n - 1);

            printf("\nThe Elements in the Array(Quick Sort)\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", array[i]);
            }

            break;

        case 5:
            for (int i = 0; i < n; i++)
            {
                array[i] = orig_array[i];
            }

            mergeSort(array, 0, n - 1);

            printf("\nThe Elements in the Array(Merge Sort)\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", array[i]);
            }

            break;

        case 6:
            for (int i = 0; i < n; i++)
            {
                array[i] = orig_array[i];
            }

            heapSort(array, n);

            printf("\nThe Elements in the Array(Heap Sort)\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", array[i]);
            }

            break;
        }
    }

    while (choice != 7);
    
}
