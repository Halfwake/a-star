#ifndef _TEAM11_NODE_DICT_SET
#define _TEAM11_NODE_DICT_SET

#include <stdint.h>

#include "path_node.h"

struct path_node_dict {
  size_t size;
  struct path_node * key_buffer;
  struct path_node * val_buffer;
  bool * valid_buffer;
};

/*
 * Create a new dictionary object.
 * @param size The max amount of key value pairs.
 * @param key_buffer A buffer of nodes as long as the size argument.
 * @param val_buffer A buffer of nodes as long as the size argument.
 * @param valid_buffer A buffer of booleans as long as the size argument.
 * @return A new dictionary object.
 */
struct path_node_dict new_node_dict(size_t size, struct path_node * key_buffer, struct path_node * val_buffer, bool * valid_buffer);

/*
 * Set a key value pair in the dictionary.
 * @param The dictionary to modify.
 * @param key The key to use.
 * @param val The value to use.
 * @return True on success. False if could not add.
 */
bool node_dict_set(struct path_node_dict * dict, struct path_node key, struct path_node val);

/*
 * Get a value from a key value pair in the dictionary.
 * @param dict The dictionary to search.
 * @param key The key to find.
 * @param val Where the corresponding value will be placed if it can be found.
 * @return True if value was found. False if otherwise.
 */
bool node_dict_get(struct path_node_dict * dict, struct path_node key, struct path_node * val);

#endif
