#ifndef _TEAM11_PATH_ARRAY
#define _TEAM11_PATH_ARRAY

#include <stdint.h>

#include "path_node.h"

struct path_array {
  size_t max_size;
  size_t size;
  struct path_node * buffer;
};

/*
 * Create a new array.
 * @param size The max size of the array.
 * @param buffer The buffer to store values in the array. Must be size long.
 * @return A new array.
 */
struct path_array new_array(size_t max_size, struct path_node * buffer);

/*
 * Add an item to the given array.
 * @param array The array to add to.
 * @param node The node to add.
 * @return True on success. False if array was already full.
 */
bool array_add(struct path_array * array, struct path_node node);

/*
 * Reverse an array in place.
 * @param array The array to reverse.
 */
void array_reverse(struct path_array * array);

#endif
