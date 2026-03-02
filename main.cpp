#include <iostream>
template < class T >
T* merge(const T* const* a, size_t sa, size_t* sai, T* c)
{
  size_t k = 0;
  for (size_t i = 0; i < sa; ++i) {
    k += sai[i];
  }

  while (k > 0) {
    T maxNum = 0; //оператор присваивания
    for (size_t i = 0; i < sa; ++i) {
      if (sai[i] > 0) {
        maxNum = a[i][sai[i] - 1]; //оператор копирующего присваивания
        break;
      }
    }

    size_t indMax = 0;
    for (size_t i = 1; i < sa; ++i) {
      if (sai[i] > 0) {
        if (a[i][sai[i] - 1] > maxNum) {
          maxNum = a[i][sai[i] - 1];
          indMax = i;
        }
      }
    }

    c[k - 1] = maxNum;
    k--;
    sai[indMax]--;
  }
  return c;
}

// #include <iostream>

// int main()
// {
//   int arr1[] = {1, 3};
//   int arr2[] = {2};
//   int arr3[] = {0, 4};

//   const int* a[] = {arr1, arr2, arr3};
//   size_t sai[] = {2, 1, 2};
//   size_t sa = 3;

//   int result[5];

//   merge(a, sa, sai, result);

//   for (size_t i = 0; i < 5; ++i) {
//     std::cout << result[i] << " ";
//   }

//   return 0;
// }
#include <iostream>

int main()
{
  int arr1[] = {1, 5, 9, 13, 17, 21, 25};
  int arr2[] = {2, 6, 10, 14, 18, 22};
  int arr3[] = {3, 7, 11, 15, 19, 23, 27, 30};
  int arr4[] = {4, 8, 12, 16, 20, 24, 28, 32, 36};

  const int* a[] = {arr1, arr2, arr3, arr4};
  size_t sai[] = {7, 6, 8, 9};
  size_t sa = 4;

  int result[30];

  merge(a, sa, sai, result);

  for (size_t i = 0; i < 30; ++i) {
    std::cout << result[i] << " ";
  }

  return 0;
}
