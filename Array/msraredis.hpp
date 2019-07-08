#define BASE 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int size = 0;
int cap = BASE;
int left = BASE / 2 - 1;  // target index
int right = BASE / 2;
int* array;
int* temp;
int init() {
  array = (int*)malloc(sizeof(int) * BASE);
  if (!array) {
    printf("out of memory\n");
    return -1;
  }
  memset(array, 0, cap);
  return 0;
}
int rpush(int val) {
  if (size == 0) {
    array[right++] = val;
    size++;
    return 0;
  } else if (right != (left + 1) && size != cap) {
    array[right] = val;
    right = (right + 1) % cap;
    size++;
    return 0;
  } else {
    // extend array
    cap *= 2;
    //溢出
    if (cap == 0) {
      printf("out of capacity\n");
      return -1;
    }
    int* temp = (int*)malloc(sizeof(int) * (cap));
    if (!temp) {
      printf("out of memory\n");
      return -1;
    }
    memset(temp, 0, cap);
    // rearrange array
    if (right == left + 1) {
      int i = cap / 4, j = size - left - 1, k = 0;
      while (k < j) {
        temp[i++] = array[left + 1 + k];
        k++;
      }
      i = cap / 4 + size - left - 1, j = right, k = 0;
      while (k < j) {
        temp[i++] = array[k++];
      }

    } else {
      int i = cap / 4, j = 0;
      while (j < size) {
        temp[i++] = array[j++];
      }
    }
    free(array);
    array = temp;
    left = cap / 4 - 1;
    right = cap / 4 * 3;
    array[right++] = val;
    size++;
    return 0;
  }
}
int rpop() {
  if (size > 0) {
    right = right - 1 < 0 ? cap - 1 : right - 1;
    array[right] = 0;
    size--;
    return 0;
  } else {
    left = cap / 2 - 1;
    right = cap / 2;
    return -1;
  }
}
int lpush(int val) {
  if (size == 0) {
    array[left--] = val;
    size++;
    return 0;
  } else if (left != right - 1 && size != cap) {
    array[left] = val;
    left = (cap + left - 1) % cap;
    size++;
    return 0;
  } else {
    cap *= 2;
    if (cap == 0) {
      printf("out of capacity\n");
      return -1;
    }
    int* temp = (int*)malloc(sizeof(int) * (cap));
    if (!temp) {
      printf("out of memory\n");
      return -1;
    }
    memset(temp, 0, cap);
    // rearrange array
    if (right == left + 1) {
      int i = cap / 4, k = left + 1;
      for (size_t j = 0; j < size; j++) {
        temp[i + j] = array[k];
        k = (k + 1) % size;
      }
    } else {
      int i = cap / 4, j = 0;
      while (j < size) {
        temp[i++] = array[j++];
      }
    }
    free(array);
    array = temp;
    left = cap / 4 - 1;
    right = cap / 4 * 3;
    array[left--] = val;
    size++;
    return 0;
  }
}
int lpop() {
  if (size > 0) {
    left = left + 1 == cap ? 0 : left + 1;
    array[left] = 0;
    size--;
    return 0;
  } else {
    left = cap / 2 - 1;
    right = cap / 2;
    return -1;
  }
}
int print() {
  for (size_t i = 0; i < cap; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
int main(int argc, char const* argv[]) {
  int input = 0;
  int val = 1;
  // int test[10] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  int i = 10;
  init();
  while (i) {
    printf("plz input 1:rpush 2:rpop 3:lpush 4:lpop 0:print\n");
    scanf("%d", &input);
    // input = test[i];
    if (input == 1) {
      rpush(val++);
    } else if (input == 2) {
      rpop();
    } else if (input == 3) {
      lpush(val++);
    } else if (input == 4) {
      lpop();
    } else {
    }
    print();
  }

  return 0;
}
