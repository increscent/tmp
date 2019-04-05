#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int index_of(int* arr, int len, int item)
{
    int high = len-1;
    int low = 0;
    int mid;

    while (high > low)
    {
        mid = (high+low) / 2;

        if (arr[mid] < item)
            low = mid+1;
        else
            high = mid;
    }

    return (arr[low] == item) ? low : -1;
}

void swap(int* arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

typedef struct {
    int low;
    int high;
} queue;

void q_push(queue* q, int* q_end, queue item, int q_size)
{
    q[*q_end] = item;
    *q_end = (*q_end + 1) % q_size;
}

queue q_pop(queue* q, int* q_start, int q_size)
{
    queue item = q[*q_start];
    *q_start = (*q_start + 1) % q_size;
    return item;
}

void q_sort2(int* arr, int len)
{
    queue* q = malloc(sizeof(queue)*len);

    int q_start = 0;
    int q_end = 0;
    int i, m;

    queue item = {.low = 0, .high = len-1};
    q_push(q, &q_end, item, len);

    while (q_end != q_start)
    {
        item = q_pop(q, &q_start, len);

        if (item.low >= item.high)
            continue;

        swap(arr, item.low, random()%(item.high-item.low)+item.low);

        m = item.low;

        for (i = item.low+1; i <= item.high; i++)
        {
            if (arr[i] < arr[item.low])
                swap(arr, i, item.low);
        }

        swap(arr, item.low, m);

        queue item1 = {.low = item.low, .high = m-1};
        queue item2 = {.low = m+1, .high = item.high};
        q_push(q, &q_end, item1, len);
        q_push(q, &q_end, item2, len);
    }
}

int sorted(int* arr, int len)
{
    int i;
    for (i = 1; i < len; i++)
        if (arr[i] < arr[i-1])
            return 0;

    return 1;
}

void q_sort(int* arr, int low, int high)
{
    int i, m;
    if (low >= high)
        return;

    swap(arr, low, random()%(high-low)+low);

    m = low;

    for (i = low+1; i <= high; i++)
    {
        if (arr[i] < arr[low])
            swap(arr, i, low);
    }

    swap(arr, low, m);

    q_sort(arr, low, m-1);
    q_sort(arr, m+1, high);
}

void print_arr(int* arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char** argv)
{
    srandom(clock());
    int size = 10;
    if (argc > 1)
        size = atoi(argv[1]);

    int* arr = malloc(sizeof(int)*size);
    int i;
    for (i = 0; i < size; i++)
        arr[i] = random()%100000;

//    print_arr(arr, size);
    
    printf("array constructed\n");

    q_sort2(arr, size);
    
    printf("array sorted\n");

//    print_arr(arr, size);

    i = random()%size;
    //i = size-1;

    int index = index_of(arr, size, arr[i]);

    if (arr[i] != arr[index])
        printf("bad index: %d != %d\n", index, i);
    else
        printf("good index: %d == %d\n", index, i);

    printf("sorted: %d\n", sorted(arr, size));

    free(arr);

    return 0;
}
