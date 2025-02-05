#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void reverse_string(char *string) {
  const size_t string_size = strlen(string);
  // + 1 for null terminator
  char *reversed_string = malloc(string_size + 1);
  if (reversed_string == NULL) {
    fprintf(stderr, "error allocating memory\n");
    return;
  }

  for (size_t i = 0; i < string_size; i++) {
    reversed_string[i] = string[string_size - i - 1];
  }
  reversed_string[string_size] = '\0';

  printf("string: %s\n", string);
  printf("reversed: %s\n", reversed_string);

  return;
}

void dynamic_array(int size) {
  int *array = malloc(size * sizeof(int));
  if (array == NULL) {
    fprintf(stderr, "error allocating memory\n");
    return;
  }

  for (int i = 0; i < size; i++) {
    array[i] = i * 2;
  }

  int *p = array;
  for (int i = 0; i < size; i++) {
    printf("%d\n", *p);
    p++;
  }

  // free memory
  free(array);
  // avoid dangling arrays
  array = NULL;
}
int main(void) {
  /* int numbers[] = {1,2,3,4,5}; */
  /* int number_size = sizeof(numbers) / sizeof(numbers[0]); */
  /* printf("size of array: %d\n", number_size); */
  /* sum_array(numbers, number_size); */

  /* char *string = "hello world"; */
  /* reverse_string(string); */

  dynamic_array(5);
}
