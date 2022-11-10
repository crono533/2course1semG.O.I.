#include <iostream>
#include <ctime>


using namespace std;

void array_print(int array[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ",array[i]);
    printf("\n");
}

int rand_in_range(int min, int max)
{
    if (min == max){
        return min;
    }
    if (min > max){
        int tmp = min;
        min = max;
        max = tmp;
    }
    return rand() % ( max - min + 1 ) + min;
}

void permutation_govno(int array[], int size)
{
    for(int i = size - 2; i >= 0; i--){
        if(array[i]<array[i+1]){
            for(int j = size - 1; j > i; j--){
                if(array[i]<array[j]){
                    swap(array[i],array[j]);
                    printf("Array after swap1:");
                    array_print(array,size);
                    for(int k = i + 1, l = size - 1; k < l; k++, l--){
                        swap(array[k], array[l]);
                        printf("Sorted:");
                        array_print(array,size);
                    }   

                }
            }
        }
    }
}

void permutation_norm(int array[],int size)
{
    int i_max = size-2;
    for( int i = size - 2; i >= 0; i--){
        if(array[i]  < array[i+1]){
            //printf("i = %d\n",i);
            i_max = i;
            break;
        }
    }
    //printf("i_max = %d\n",i_max);
    
    int j_max = size - 1;
    for(int j = size - 1; j > i_max; j--){
        if(array[i_max] < array[j]){
            j_max = j;
            swap(array[i_max],array[j]);
            printf("Array aftar swap: ");
            array_print(array,size);
            break;
        }
    }

    for(int k = i_max + 1, l = size - 1; k < l; k++,l--)
    {
        swap(array[k],array[l]);
        printf("Sorted: ");
        array_print(array,size);
    }
}

int factorial(int i)
{
  if (i==0) return 1;
  else return i*factorial(i-1);
}

int main()
{
    srand((unsigned int) time(NULL));

    printf("Write array size.\n");
    int size_of_array = 6;
    scanf("%d", &size_of_array);

    int array[size_of_array] = {0};

    for(int i = 0; i < size_of_array; i++)
        array[i] = rand_in_range(1,10);
    
    //array[0]=1;
    //array[1]=2;
   //array[2]=3;
    //array[3]=4;
    //array[4]=5;
    //array[5]=6;
    printf("Array: ");   
    array_print(array,size_of_array);

    for(int i = 0; i<factorial(size_of_array); i++){
        permutation_norm(array,size_of_array);
    }

    return 0;
}