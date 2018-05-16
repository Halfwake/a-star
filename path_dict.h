#ifndef _TEAM11_DICT_SET
#define _TEAM11_DICT_SET

#include <stdint.h>

#include "path_node.h"

struct path_dict {
  size_t size;
  struct path_node ** node_buffer;
  uint32_t * cost_buffer;
  bool * valid_buffer;
};

/*
 * Create a new dictionary object.
 * @param size The max amount of key value pairs.
 * @param node_buffer A buffer of nodes as long as the size argument.
 * @param cost_buffer A buffer of costs as long as the size argument.
 * @param valid_buffer A buffer of booleans as long as the size argument.
 * @return A new dictionary object.
 */
struct path_dict new_dict(size_t size, struct path_node ** node_buffer, uint32_t * cost_buffer, bool * valid_buffer);

/*
 * Set a key value pair in the dictionary.
 * @param The dictionary to modify.
 * @param path_node The key to use.
 * @param cost The value to use.
 * @return True on success. False if could not add.
 */
bool dict_set(struct path_dict * dict, struct path_node * key, uint32_t cost);

/*
 * Get a value from a key value pair in the dictionary.
 * @param dict The dictionary to search.
 * @param key The key to find.
 * @param value Where the corresponding value will be placed if it can be found.
 * @return True if value was found. False if otherwise.
 */
bool dict_get(struct path_dict * dict, struct path_node * key, uint32_t * value);

#endif
