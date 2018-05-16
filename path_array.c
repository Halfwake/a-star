#include "path_array.h"

struct path_array new_array(size_t max_size, struct path_node * buffer) {
  struct path_array array;
  array.max_size = max_size;
  array.size = 0;
  array.buffer = buffer;
  return array;
}

bool array_add(struct path_array * array, struct path_node node) {
  if (array->size == array->max_size) {
    return false;
  }
  array->buffer[array->size] = node;
  array->size = array->size + 1;
  return true;
}

void array_reverse(struct path_array * array) {
  struct path_node temp;
  for (size_t i; i < array->size; i++) {
    temp = array->buffer[i];
    array->buffer[i] = array->buffer[array->size - 1 - i];
    array->buffer[array->size - 1 - i] = temp;
  }
}
