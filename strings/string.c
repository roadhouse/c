#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop_using_pointer(char *s) {
  printf("basic loop using pointer arithmetic\n");
  while(*s != '\0') {
    printf("%c\n", *s);
    s++;
  }
  printf("\n");
}

void detect_char_using_strstr(char *s, char *needle) {
  printf("detect substring %c\n", *needle);
  char *match;
  char *original=s;
  while((match = strstr(s, needle)) != NULL) {
    int position = match - original;
    printf("found %c at position %d\n", *needle, position);  
    s = match + 1;
  }
  printf("\n");
}

void replace_string(char *string, char *substring, char *replacement) {
  size_t string_size = strlen(string);
  size_t substring_size = strlen(substring);
  size_t replacement_size = strlen(replacement);

  //calulate the number of occurrences
  char *ptr = string;
  int occurrences = 0;
  while ((ptr = strstr(ptr, substring)) != NULL) {
    occurrences++;
    ptr += substring_size;
  }
  printf("occurrences: %d\n", occurrences);

  //calculate the size of the new string
  size_t total_size_of_occurrences = substring_size * occurrences;
  size_t total_size_of_replacement = replacement_size * occurrences;
  size_t total_size_of_string_without_occurrences = string_size - total_size_of_occurrences;
  size_t total_size_of_new_string = total_size_of_string_without_occurrences + total_size_of_replacement;
  printf("total size of original string: %ld\n", string_size);
  printf("total size of occurrences: %ld\n", total_size_of_occurrences);
  printf("total size of replacement: %ld\n", total_size_of_replacement);
  printf("total size of original string without occurrences: %ld\n", total_size_of_string_without_occurrences);
  printf("total size of new string: %ld\n", total_size_of_new_string);

  //allocate new string, +1 because the string is null terminated
  char *new_string = (char *)malloc(total_size_of_new_string + 1);

  char *final = new_string;
  char *original_start = string;
  for (int i = 0; i < occurrences; i++) {
    char *current = strstr(original_start, substring);
    size_t chunk_length = current - original_start;

    //copy the part before the substring
    memcpy(final, original_start, chunk_length);
    final += chunk_length;
    //copy the replacement
    memcpy(final, replacement, replacement_size);
    final += replacement_size;

    //move to the next substring in the original string
    original_start = current + substring_size;
  }

  //move the remaining part of the original string
  size_t remaining_size = string_size - (original_start - string);
  memcpy(final, original_start, remaining_size);
  final += remaining_size;
  //null terminate the new string
  *final = '\0';

  printf("original string: %s\n", string);
  printf("substring: %s\n", substring);
  printf("replacement: %s\n", replacement);
  printf("final string: %s\n", new_string);
}

int main() {
  char *s = "hello world";

  loop_using_pointer(s);
  detect_char_using_strstr(s, "l");
  replace_string(s, "l", "666");

  return 0;
}
