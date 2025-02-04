#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_pointer(int *number) {
  printf("param value from function: %d\n", *number);
  *number = 9;
  printf("param value from function after: %d\n", *number);
  printf("param address from function: %p\n", &number);
  return;
}

void sum_array(int numbers[], int size) {
  int *p = numbers;
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += *p;
    printf("value in position %d: %d,sum: %d\n", i, *p, sum);
    p++;
  }
  return;
}

void basic() {
  int a = 3;
  int *pa = &a; 
  printf("pointer value: %d\n", a);
  printf("pointer address: %p\n", &pa);
  *pa = 4;
  printf("pointer value after: %d\n", a);
  printf("pointer address after: %p\n", &pa);

  int *pb = pa;
  printf("pointer value: %d\n", *pb);
  printf("pointer address: %p\n", &pb);

  int *pc;
  pc = pa;
  printf("pointer value: %d\n", *pc);
  printf("pointer address: %p\n", &pc);

  print_pointer(&a);
  printf("pointer value after in main: %d\n", a);
}

int main(void) {
  int numbers[] = {1,2,3,4,5};
  int number_size = sizeof(numbers) / sizeof(numbers[0]);
  printf("size of array: %d\n", number_size);
  /* sum_array(numbers, number_size); */
  print_pointer(&numbers[0]);
}
