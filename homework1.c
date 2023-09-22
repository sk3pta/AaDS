/* Copyright 2023 Gasan Emirgamzaev emirgamzaevsan@gmail.com */

/*"On my computer can do about 5,000,000 calls a second, independent of the size
of n, so time complexity is O(1)." -- StackOverFlow*/


#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aads.h"


// Task 1
// ---------------------------------------------------------------------------

size_t fibonacci(size_t n) { // O(n)

  size_t res = 0;
  size_t a = 0;
  size_t b = 1;

  if (n == 1)
    return 1;
  if (n == 0)
    return 0;

  for (size_t x = 2; x <= n; ++x) {
    res = a + b;
    a = b;
    b = res;
  }

  return res;
}

size_t fibonacci_recursive(size_t n) {
  if (n == 1)
    return 1;
  if (n == 0)
    return 0;

  return (fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2));
  return 0;
}
//---------------------------------------------------------------------------------

// Task 2.-------------------------------------------------------------------------
// Массив отсортирован (невозрастающий). Можно идти по массиву, проверяя, нет ли
// повторяющихся дальше. [67,5,4,4,2,1]
size_t countArrayUniques_taskA(int *array,
                               size_t arraySize) { // O(хз) мб O(n) ?
  size_t count = 0;

  for (size_t x = 0; (int)x < arraySize; ++x) {
    while (x < arraySize - 1 && array[x] == array[x + 1])
      ++x;
    // ++x; Если различные это просто кол-во, не считая повторений, а не
    // неповторяющиеся
    ++count;
  }

  return count;
}

size_t countArrayUniques_taskB(int *array, size_t arraySize, int k) {
  size_t count = 0;
  int *helpArray = (int *)malloc(
      (k + 1) * sizeof(int)); // вспомогательный массив от[0,k] включительно
  memset(helpArray, 0,
         sizeof(int) * (k + 1)); // заполняем массив нулями. Complexity O(n)

  // например, если helpArray[67] = 2, значит, что в array число 67 встречается
  // два раза
  for (size_t x = 0; x < arraySize; ++x) {
    helpArray[array[x]]++;
  }

  for (size_t x = 0; x < arraySize; ++x) {
    if (helpArray[array[x]] != 0) {
      helpArray[array[x]] = 0;
      ++count;
    };
  }

  free(helpArray);

  return count;
}

//---------------------------------------------------------------------------------

// Task
// 3---------------------------------------------------------------------------------

size_t factorial(unsigned int n) {
  size_t product = 1;
  if (n == 0 || n == 1) {
    return product;
  }

  for (size_t x = 1; x <= n; ++x) {
    product *= x;
  }
  return product;
}

long double NumericSeries(size_t n) {

  long double result = 0.0;
  for (size_t x = 1; x <= n; ++x) {
    result += 1.0 / (factorial(x));
  }
  return result;

  // Или вместо всего return exp(1.0) - 1
}

//---------------------------------------------------------------------------------

// Task4 ------------------------------------------------------------------------


// т.к встречаются все числа от 0 до n по одному разу, возьмем сумму и будет
// вычитаь элементы массива
size_t findLostNumber(int *array, int n) {
  size_t sum = 0;
  
  for (size_t x = 0; x <=n; ++x) {
    sum += x;
  }

  for (size_t x = 0; x < n; ++x) {
    sum -= array[x];
  }
  return sum;
}

// ------------------------------------------------------------------------


// Task5 ------------------------------------------------------------------------21


// 𝑥[𝑖][𝑗] ≤ 𝑥[𝑖][𝑗 + 1], 𝑥[𝑖][𝑗] ≤ 𝑥[𝑖 + 1][𝑗]
// x[i][j] <= x[i][j+1], x[i][j] <= x[i+1][j]
// справа налево возрастают получаетца


// Если текущий меньше a, то все числа слева и выше, меньше. Если текущий больше а, то все числа правее и ниже, больше
bool isInArray(int dim,int (*array)[dim],int a) {
  int row = 0; 
  int col = dim -1; 
  if (a < array[0][0] || a > array[dim -1][dim -1])
    return false;

  
  while (row <= dim -1 && col >= 0) {
    if (array[row][col] < a) {
      row++;
    }
    else if (array[row][col] > a) {
      col--;
    }
    else {
      printf("%d %d \n",row,col);
      return true;
    }
  }

    return false;
    
}

// ------------------------------------------------------------------------

// Task 6  -----------------------------------

/*Каждая горизонтальная строка, вертикальный столбец и квадрат (9 клеток каждый) 
должны заполняться цифрами 1-9, не повторяя никаких чисел в строке, столбце или квадрате.*/

// пусть судоку заполняется, начиная с 1



bool isArrayUnique(const int *array, size_t arraySize) {
  int *helpArray = malloc(sizeof(int) * ( arraySize + 1 ));

  for (size_t x =0; x < arraySize; ++x) {
    helpArray[array[x]]++;
  }

  for (size_t x =1; x < arraySize+1; ++x) {
    if (helpArray[x] != 1 )
    return false;
  }

  return true;
}


bool checkSudoku (size_t dim, int (array[])[dim]) {


  int *helpArray = malloc(sizeof(int) * dim*dim);

  // check row

  for (size_t x = 0; x < dim * dim; ++x) {
      if (!isArrayUnique(array[x],dim*dim))
          return false;
  }


  // check col
  for (size_t x = 0; x < dim*dim; ++x) {
      for (size_t y = 0; y < dim * dim; ++y) {
          helpArray[y] = array[y][x];
      }
      isArrayUnique(helpArray,dim*dim);
  }

  for (size_t x = 0; x < dim*dim; x += 3) {
      for (size_t y = 0; y < dim * dim; y += 3) {




      }
  }



  return false;
  
}


// Task 7



void multiply(int *nums, size_t arraySize, long int *answer) {
    long  int prod = 1;
  for (size_t x = 0; x < arraySize; ++x){
      prod = 1;
      for (size_t j =0; j < arraySize; ++j) {
        
        if (j != x) {
          prod = prod * nums[j];

        }
        

      }
    answer[x] = prod;
   }

}

int main() {


int grid[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

  int array[9] = {1,2,3,4,5,6,7,8,9};
  long *answer = malloc(sizeof(long) * 9);
  multiply(array, 9 , answer);

   
     printf("%d",checkSudoku(3, grid));
  

  free(answer);
}