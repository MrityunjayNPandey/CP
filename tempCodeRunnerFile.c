
#include <stdio.h>
#include <stdlib.h>

int read_array(int** ar)
{
    int i, length;
    scanf("%d", &length);
    *ar = (int*)malloc(length * sizeof(int));
    for(i = 0; i < length; i++)
    {
        scanf("%d", &(*ar)[i]);
    }
    return length;
}

void display_array(int* pointer, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        printf("arr[%d] = %d \n", i, *(pointer + i));
    }
}

int find_biggest_pos(int* pointer, int length)
{
    int i, biggest = *(pointer + 0), pos;
    for(i = 0; i < length; i++)
    {
        if(*(pointer + i) > biggest)
        {
            biggest = *(pointer + i);
            pos = i;
        }
    }
    return pos;
}

int find_smallest_pos(int* pointer, int length)
{
    int i, smallest = *(pointer + 0), pos;
    for(i = 0; i < length; i++)
    {
        if(*(pointer + i) < smallest)
        {
            smallest = *(pointer + i);
            pos = i;
        }
    }
    return pos;
}

void interchange_pos(int* pointer, int length, int pos1, int pos2)
{
    int temp = *(pointer + pos1);
    *(pointer + pos1) = *(pointer + pos2);
    *(pointer + pos2) = temp;
}

int main()
{
    int* ar, length, biggest, smallest;
    printf("Enter the length of the array: ");
    length = read_array(&ar);
    display_array(ar, length);
    biggest = find_biggest_pos(ar, length);
    smallest = find_smallest_pos(ar, length);
    interchange_pos(ar, length, biggest, smallest);
    printf("Modified array: \n");
    display_array(ar, length);
    return 0;
}