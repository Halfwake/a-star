#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "path_node.h"
#include "path_array.h"

void assert(int check, char * description) {
  printf("[%s] - %s\n", check ? "T" : "F", description);
}

void test_basic() {
  printf("Test Array Basic\n");

  struct path_node node1 = new_path_node(0, 0);
  struct path_node node2 = new_path_node(1, 1);
  struct path_node node3 = new_path_node(2, 2);
  struct path_node node4 = new_path_node(3, 3);

  size_t max_size = 4;
  struct path_node buffer[4];
  struct path_array array = new_array(max_size, buffer);

  assert(array_add(&array, node1), "Add succeed.");
  assert(array_add(&array, node2), "Add succeed.");
  assert(array_add(&array, node3), "Add succeed.");
  assert(array_add(&array, node3), "Add succeed.");
  assert(!array_add(&array, node4), "Add failed.");
}

void test_reverse() {
  printf("Test Array Reverse");
  struct path_node node1 = new_path_node(0, 0);
  struct path_node node2 = new_path_node(1, 1);
  struct path_node node3 = new_path_node(2, 2);
  struct path_node node4 = new_path_node(3, 3);

  size_t max_size = 4;
  struct path_node buffer[4];
  struct path_array array = new_array(max_size, buffer);

  assert(array_add(&array, node1), "Add succeed.");
  assert(array_add(&array, node2), "Add succeed.");
  assert(array_add(&array, node3), "Add succeed.");
  assert(array_add(&array, node3), "Add succeed.");
  assert(!array_add(&array, node4), "Add failed.");

  struct path_node expected[4];
  expected[0] = new_path_node(0, 0);
  expected[1] = new_path_node(1, 1);
  expected[2] = new_path_node(2, 2);
  expected[3] = new_path_node(3, 3);

  for (size_t i = 0; i < array.size; i++) {
    assert(node_equal(array.buffer[i], expected[i]), "Expected Node");
  }

  array_reverse(&array);
  expected[0] = new_path_node(3, 3);
  expected[1] = new_path_node(2, 2);
  expected[2] = new_path_node(1, 1);
  expected[3] = new_path_node(0, 0);  
  for (size_t i = 0; i < array.size; i++) {
    assert(node_equal(array.buffer[i], expected[i]), "Expected Node");
  }  
}

void test_reverse_one() {
  printf("Test Array Reverse One");
  struct path_node node1 = new_path_node(0, 0);

  size_t max_size = 4;
  struct path_node buffer[4];
  struct path_array array = new_array(max_size, buffer);

  assert(array_add(&array, node1), "Add succeed.");

  struct path_node expected[4];
  expected[0] = new_path_node(0, 0);

  for (size_t i = 0; i < array.size; i++) {
    assert(node_equal(array.buffer[i], expected[i]), "Expected Node");
  }
  assert(array.size == 1, "Array is correct size.");

  array_reverse(&array);

  for (size_t i = 0; i < array.size; i++) {
    assert(node_equal(array.buffer[i], expected[i]), "Expected Node");
  }
  assert(array.size == 1, "Array is correct size.");
}

int main() {
  printf("Test Array\n");
  test_basic();
  test_reverse();
  test_reverse_one();
  return 0;
}
