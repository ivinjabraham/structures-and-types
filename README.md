# Common Data Structures, in C

# Linked List

This Linked List has two major design goals:
- To have a straightforward and easy-to-use API for users
- To have a robust and "production-ready" implementation under the hood.

## Data Structures

### `Node`

Represents a node in a linked list.

- **Properties**
    - `data`: int; data stored in the node.
    - `next`: Node\*; pointer to the next node.

### `LinkedList`

Represents the linked list.

- **Properties**
    - `head`: Node\*; pointer to the first node in the list.

## Functions
