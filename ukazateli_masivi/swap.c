 #include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2=temp;
}

void sort(int * p, int len)
{
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        if(*(p+i) < *(p+j))
        {
            swap((p+i),(p+j));
        }
    }
}



int main()
{
    int arr[5] = {2,6,1,10,3};
    sort(arr,5);
    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}