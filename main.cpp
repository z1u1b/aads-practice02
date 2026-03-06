/*
Проблемы неявного интерфейса:
1) Оператор перемещения
2) Оператор копирующего присваивания
3) Оператор сравнения

Проблемы явного интерфейса:
1) Память для T* с выделяется вне функции

*/

#include <iostream>
template < class T >
T* merge(const T* const* a, size_t sa, const size_t* sai, T* c)
{
  size_t* new_sai = nullptr;
  try {
    new_sai = new size_t[sa];
  } catch (...) {
    throw;
  }
  size_t k = 0;
  for (size_t i = 0; i < sa; ++i) {
    k += sai[i];
    new_sai[i] = sai[i];
  }
  while (k > 0) {
    T maxNum = 0; // оператор перемещения
    try {
      for (size_t i = 0; i < sa; ++i) {
        if (new_sai[i] > 0) {
          maxNum = a[i][new_sai[i] - 1]; // оператор копирующего присваивания
          break;
        }
      }
    } catch (...) {
      delete[] new_sai;
      throw;
    }

    size_t indMax = 0;
    try {
      for (size_t i = 1; i < sa; ++i) {
        if (new_sai[i] > 0) {
          if (a[i][new_sai[i] - 1] > maxNum) // оператор сравнения
          {
            maxNum = a[i][new_sai[i] - 1]; // оператор копирующего присваивания
            indMax = i;
          }
        }
      }
    } catch (...) {
      delete[] new_sai;
    }

    try {
      c[k - 1] = maxNum; // оператор копирующего присваивания
    } catch (...) {
      delete[] new_sai;
    }

    k--;
    new_sai[indMax]--;
  }
  delete[] new_sai;
  return c;
}

#include <iostream>

int main()
{
  int arr1[] = {1, 5, 9, 13, 17, 21, 25};
  int arr2[] = {2, 6, 10, 14, 18, 22};
  int arr3[] = {3, 7, 11, 15, 19, 23, 27, 30};
  int arr4[] = {4, 8, 12, 16, 20, 24, 28, 32, 36};

  const int* a[] = {arr1, arr2, arr3, arr4};
  const size_t sai[] = {7, 6, 8, 9};
  size_t sa = 4;

  int result[30];

  merge(a, sa, sai, result);

  for (size_t i = 0; i < 30; ++i) {
    std::cout << result[i] << " ";
  }
}
