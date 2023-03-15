/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

unsigned char find_mean(unsigned char insert[]);
unsigned char find_maximum(unsigned char insert[]);
unsigned char find_minimum(unsigned char insert[]);


void print_statistics(unsigned char insert[]){
    printf("Mean: %d\n", find_mean(insert));
    // printf("Median: %d", find_median(insert));
    printf("Max: %d\n", find_maximum(insert));
    printf("Min: %d\n", find_minimum(insert));
}

void print_array(unsigned char insert[]){
  for (int i = 0; i < SIZE; i++){
    printf("%d ", insert[i]);
    if (i%10==0 && i>0){
      printf("\n");
    }
  }
}

void find_median(){
  
}

unsigned char find_mean(unsigned char insert[]){
  static unsigned char _buf = 0;
  for(int i=0 ; i<SIZE; i++){
      _buf += insert[i];
  }
  return (_buf/SIZE);
}

unsigned char find_maximum(unsigned char insert[]){
  unsigned char _buf = 0;
  int count = 0;
    for(int i=0 ; i<SIZE; i++){
        _buf = insert[i];
        for(int j=0; j<SIZE; j++){
            if (_buf >= insert[j]){
                count++;
            }
            if (count ==SIZE){
              return _buf;
            }

            if (j == (SIZE -1)){
              count = 0;
            }

        }
    }
}

unsigned char find_minimum(unsigned char insert[]){
  unsigned char _buf = 0;
  int count = 0;
    for(int i=0 ; i<SIZE; i++){
        _buf = insert[i];
        for(int j=0; j<SIZE; j++){
            if (_buf <= insert[j]){
                count++;
            }
            if (count == SIZE){
              return _buf;
            }

            if (j == (SIZE-1)){
              count = 0;
            }

        }
    }
}

unsigned char sort_array(unsigned char insert[]){
    // unsigned char new_test[SIZE] = {0};
    // new_test[0] = find_minimum(insert);
    // new_test[SIZE] = find_maximum(insert);
    // unsigned char _buf = 0;

    // for (int i = 0; i<SIZE; i++){
    //     _buf = insert[i];
        
    // }

    int k, i, flag;
    unsigned char temp;
    for ( k=1;k<SIZE; k++)
    {
      flag =0;
      for (i=0; i< SIZE-k; i++)
      {
        if (insert[i]>insert[i+1])
        {
          temp=insert[i];
          insert[i]=insert[i+1];
        };
        insert[i+1]=temp;
        flag=1;
      }
      if(flag==0)
      break;
    }
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  // signed char i = test[0];
  // printf("%i", (signed char)test[0]); // convert unsigned to signed, but must be same type
  sort_array(test);
  print_array(test);
  // print_statistics(test);
}

/* Add other Implementation File Code Here */
