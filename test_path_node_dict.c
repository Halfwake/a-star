#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "path_node.h"
#include "path_node_dict.h"

void assert(int check, char * description) {
  printf("[%s] - %s\n", check ? "T" : "F", description);
}

void test_basic() {
  printf("Test Node Dict Basic\n");
  struct path_node_dict dict;
  size_t size = 8;
  struct path_node key_buffer[8];
  struct path_node val_buffer[8];
  bool valid_buffer[8];

  struct path_node node0 = new_path_node(0, 0);
  struct path_node node1 = new_path_node(1, 1);
  struct path_node node2 = new_path_node(2, 2);
  struct path_node node3 = new_path_node(3, 3);
  struct path_node node4 = new_path_node(4, 4);
  dict = new_node_dict(size, key_buffer, val_buffer, valid_buffer);
  assert(node_dict_set(&dict, node0, node3), "Added correctly.");
  assert(node_dict_set(&dict, node1, node2), "Added correctly.");
  assert(node_dict_set(&dict, node3, node0), "Added correctly.");
  assert(node_dict_set(&dict, node2, node4), "Added correctly.");
  assert(node_dict_set(&dict, node3, node1), "Reset correctly.");

  struct path_node temp;
  assert(node_dict_get(&dict, node0, &temp), "Got correctly.");
  assert(node_equal(temp, node3), "node3 == node3");
  assert(node_dict_get(&dict, node1, &temp), "Got correctly.");
  assert(node_equal(temp, node2), "node2 == node2");
  assert(node_dict_get(&dict, node2, &temp), "Got correctly.");
  assert(node_equal(temp, node4), "temp == 40");
  assert(node_dict_get(&dict, node3, &temp), "Got correctly.");
  assert(node_equal(temp, node1), "temp == 100");
  assert(!node_dict_get(&dict, node4, &temp), "Could not find.");
}

void test_complex() {
  struct path_node_dict dict;
  size_t size = 8;
  struct path_node key_buffer[8];
  struct path_node val_buffer[8];
  bool valid_buffer[8];

  struct path_node node0 = new_path_node(0, 0);
  struct path_node node1 = new_path_node(1, 0);
  struct path_node node2 = new_path_node(0, 1);
  struct path_node node3 = new_path_node(3, 3);
  dict = new_node_dict(size, key_buffer, val_buffer, valid_buffer);
  assert(node_dict_set(&dict, node0, node1), "Added correctly.");
  assert(node_dict_set(&dict, node3, node1), "Added correctly.");
  assert(node_dict_set(&dict, node2, node0), "Added correctly.");

  struct path_node temp;
  assert(node_dict_get(&dict, node0, &temp), "Got correctly.");
  assert(node_equal(temp, node1), "node1 == node1");

  assert(node_dict_get(&dict, node3, &temp), "Got correctly.");
  assert(node_equal(temp, node1), "node1 == node1");

  assert(node_dict_get(&dict, node2, &temp), "Got correctly.");
  assert(node_equal(temp, node0), "node0 == node0");

}

int main() {
  printf("Test Node Dict");
  test_basic();
  return 0;
}
