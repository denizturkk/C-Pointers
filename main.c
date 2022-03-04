#include <stdio.h>
#include <string.h>
#define x 10

// creator Deniz Turk
// 8/08/2021


// WORKING WITH POINTERS ON 2 DIMENSIONAL ARRAYS

int main() {


    //we are creating a 2 dimensional array 3 elements of each.
    //since the RAM has a 1 dimensional architecture this 2d array is stored as a 3-3 like (2,4,6,8,10,12) in one dimensional
    int array[2][3]= {{2,4,6},{8,10,12}};

    int fcounter=0;
    int scounter =0;

    /*
    when we are working with 2 dimensional array like that, expression of "array" is not a pointer to integer
    in reality "array" is a pointer that point a 1 dimensional array 3 elements of each.
    so we could define this pointer as ----->>>>>> int (*array)[3];
    */



    //FIRST WAY TO PRINT INFOS  --> USING ARRAY EXPRESIONS

    printf("---------- USING ARRAY EXPRESIONS ---------- \n\n");
    for(fcounter; fcounter<2 ;fcounter++)
    {
        for(scounter;scounter<3;scounter++)
        {

            printf("address of the %d.%d = %d ",fcounter,scounter,(array[fcounter]+scounter));
            printf("\t the value that is stored in this address  %d \n",*(array[fcounter]+scounter));

        }

            printf("\n");
            scounter=0;

    }

    // we will try to do same applications  as we did but this time
    //using pointers, this is why we are restarting our variables with 0
    fcounter=0;
    scounter =0;

    printf("\n");

    //SECOND WAY TO PRINT --> USING POINTER EXPRESIONS

    printf("---------- USING POINTER EXPRESIONS ---------- \n\n");
    for(fcounter; fcounter<2 ;fcounter++)
    {
        for(scounter;scounter<3;scounter++)
        {

            printf("address of the %d.%d = %d ",fcounter,scounter,*(array+fcounter)+scounter );
            printf("\t the value that is stored in this address  %d \n",*(*(array+fcounter)+scounter));

        }

            printf("\n");
            scounter=0;
    }



         // PART 1
         printf("0.0 a %d \n",array[0]);     //difference between array and *array is that while array returns us the address
         printf("0.0 a %d \n",array);       //that point an array 3 elements of each, *array returns us the address of the int.
         printf("0.0 a %d \n",*array);      //this is why  array+1 returns us address+12 bytes while *array+1 return us address+4 byte
         printf("0.0 v %d \n",**array);     //we can see the difference printing the address array+1 and *array+1
         printf("0.0 v %d \n",*array[0]);   //we assume that we are working with int array in a typical architecture

         printf("\n");

         //PART2
         printf("1.0 a %d \n",array[1]);
         printf("1.0 a %d \n",*(array+1));
         printf("1.0 a %d \n", (array+1));
         printf("1.0 v %d \n",**(array+1));
         printf("1.0 v %d \n",*array[1]);

         printf("\n");

         //PART3
         printf("0.2 a %d \n",array[0]+2);
         printf("0.2 a %d \n",*array+2);
         printf("0.2 v %d \n",*(array[0]+2));
         printf("0.2 v %d \n",*(*array+2));

         printf("\n");

         //PART4
         printf("1.1 a %d \n",array[1]+1);
         printf("1.1 a %d \n",*(array+1)+1);
         printf("1.1 v %d \n",*(array[1]+1));
         printf("1.1 v %d \n",*(*(array+1)+1));

         printf("\n");

         //PART5
         printf("1.1 v + value of x variable      = %d \n",*(*(array+1)+1)+x);
         printf("1.1 v + value of x variable      = %d \n",*(array[1]+1)+x );
         printf("0.2 v + value of x variable + 10 = %d \n",*(*array+2)+x+10 );
         printf("0.2 v + value of x variable + 10 = %d \n",*(array[0]+2)+x+10 );

    /*
        PART 1
        array[0]  == this expression gives us the address of the first array also the address of the multi d. array 0.0.a
        array     == this expression gives us the address of the first array also the address of the multi d. array 0.0.a
       *array     == this expression gives us the address of the first array also the address of the multi d. array 0.0 a
       **array    == this expression gives us the value which is stored in the first address of the first array     0.0 v
       *array[0]  == this expression gives us the value which is stored in the first address of the first array     0.0 v

        PART2
         array[1] == this expression gives us the address of the second array 1.0 a
        (array+1) == this expression gives us the address of the second array 1.0 a
       *(array+1) == this expression gives us the address of the second array 1.0 a
      **(array+1) == this expression gives us the value which is stored in the starting of the second array's address 1.0 v
        *array[1] == this expression gives us the value which is stored in the starting of the second array's address 1.0 v

        PART3
       array[0]+2 == this expression gives us the address of 0.2 a
         *array+2 == this expression gives us the address of 0.2 a
    *(array[0]+2) == this expression gives us the value   of 0.2 v
      *(*array+2) == this expression gives us the value   of 0.2 v

        PART4
       array[1]+1 == this expression gives us the address of 1.1 a
     *(array+1)+1 == this expression gives us the address of 1.1 a
    *(array[1]+1) == this expression gives us the value   of 1.1 v
  *(*(array+1)+1) == this expression gives us the value   of 1.1 v


    */

  return 0;

}


