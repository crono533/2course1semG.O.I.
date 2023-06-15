#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[13] = "Hello, denis";
    int size_of_str = strlen(str);
    printf("Len of str = %d\n", size_of_str);

    char ptr[6] = "denis";
    int size_of_ptr = strlen(ptr);
    printf("Len of ptr = %d\n", size_of_ptr);

    int table[256];

    for(int i = 0; i < 255; i++)
    {
       table[i] = size_of_ptr;
    }

    for(int i = 0; i < size_of_ptr - 1; i++)
    {
        table[ptr[i]] = size_of_ptr - i - 1;
    }

    for(int i = 0; i < size_of_ptr; i++)
    {
       printf("\n%c - %d\n",ptr[i],table[ptr[i]]);
    }

    int i = size_of_ptr - 1; 
    int j = size_of_ptr - 1;
    int in = 0;
    
    while(i < size_of_str)
    {
        if(j < 0)
            in = i + 1 - size_of_ptr;

        int k = i;
        j = size_of_ptr - 1;

        while(j >= 0)   
        {
            if(str[k] == ptr[j])
            {
                j--;
                k--;
            }else{
                i = i + table[str[i]];
                j = size_of_ptr - 1;
                break;
            }
        }
    }

    if (j >= 0){
        printf("No match\n");
    } else {
        in = i + 1 - size_of_ptr;
        printf("Match:%d",in);
    }

    return 0;
}