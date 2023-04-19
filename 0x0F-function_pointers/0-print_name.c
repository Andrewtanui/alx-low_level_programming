#include <stdio.h>

void print_name(char *name, void (*f)(char *)) {
  f(name);
}

void print_normal(char *name) {
  printf("Name: %s\n", name);
}

void print_reversed(char *name) {
  printf("Reversed name: ");
  for (int i = strlen(name) - 1; i >= 0; i--) {
    printf("%c", name[i]);
  }
  printf("\n");
}

int main() {
  char *name = "John Doe";

  printf("Printing name normally:\n");
  print_name(name, print_normal);

  printf("Printing name reversed:\n");
  print_name(name, print_reversed);

  return 0;
}
