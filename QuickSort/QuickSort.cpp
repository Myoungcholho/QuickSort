// QuickSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

void quick(int arr[], int start, int end)
{

    if (start >= end) return;
    int pivot = start;
    int L = pivot + 1;
    int R = end;
    int temp;

    while (L <= R)
    {
        while (arr[L] < arr[pivot] && L < R) {  // 피봇보다 크고/L이 R과 같게되면 멈춤
            ++L;                                
        }
        while (arr[R] > arr[pivot] && R >= L) { // 피봇보다 작고 R이 L보다 한개 작으면 멈춤
            --R;
        }

        if (L >= R) { // 근데 L == R 이라 L은 연산 안하는데 R이 만족해서 안움직이는 경우가 있음, 그래서 >= 로 하고 break하기
            break;
        }// 엇갈리고 R이 1개 더작으면 반복 종료

        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
    }

    temp = arr[pivot];
    arr[pivot] = arr[R];
    arr[R] = temp;

    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick(arr, start, R - 1);
    quick(arr, R + 1, end);
}

int main()
{
    int arr[10] = { 19,5,2,43,20,80,67,29,70,60 };
    //int arr[5] = { 10, 2 , 19, 4,20 };
    int size = sizeof(arr) / sizeof(*arr);

    quick(arr, 0, size-1);



    printf("%d", arr[2]);
}


