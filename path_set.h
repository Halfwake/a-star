#ifndef _TEAM11_PATH_SET
#define _TEAM11_PATH_SET

#include <stdint.h>

#include "path_node.h"

/*
 * A set that supports the operations made visible by this file.
 */
struct path_set {
  size_t size;
  struct path_node * node_buffer;
  bool * valid_buffer;
};

/*
 * Create a new set.
 * @param size The max size of the queue.
 * @param node_buffer A buffer of nodes. Must be max_size length. Should never be altered directly.
 * @param valid_buffer A buffer of booleans. Must be max_size length. Should never be altered directly.
 * @return An empty set object.
 */
struct path_set new_set(size_t size, struct path_node * node_buffer, bool * valid_buffer);

/*
 * Check if item is part of a set.
 * @param set The set to check membership from.
 * @param node The node that may or may not be in the set.
 * @return True if the node is a member of the set.
 */
bool set_is_member(struct path_set * set, struct path_node * node);

/*
 * Add an item to a set.
 * @param set The set to add an item to.
 * @param The item to add to the set.
 * @return True if the item was added. False if there was no room.
 */
bool set_add(struct path_set * set, struct path_node * node);

/*
 * Remove an item from the set.
 * @param set The set to remove an item from.
 * @param node The node to remove.
 * @return True if the item was removed. False if the item was never in the set.
 */
bool set_remove(struct path_set * set, struct path_node * node);

/*
 * Check if set is empty.
 * @param set The set to check.
 * @return True if empty.
 */
bool set_is_empty(struct path_set * set);

#endif
