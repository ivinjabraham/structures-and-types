# Linked List
Looking for new implementations that are more efficient, clever or simply better.  

- Double pointers: Turns out we don't need them cause we use a structure to hold the head of the list.
- Optional tail pointer: Implemented, but it's not optional. Not sure why a pointer worth of memory is worth making optional. This isn't designed to be used in memory intensive scenarios anway.

On reading ref#3, it is clear that adding cache and having 'prev' pointers (doubly linked list) is essential for performance on a reasonable scale. Adding a memory pool, however would make this an overly complex `ArrayList`. Both `ArrayList` and `ArrayBlock` seem interesting to implement.
- ~~Optional~~ Cache
- ~~Memory pool instead of random assignment in heap~~

# References

1. [Basic Linked List](https://towardsdatascience.com/linked-list-implementation-guide-16ed67be18e4): Don't like the pointer args, this requires the caller to reassign rather than simply calling the function.

2. [Problems on Lists](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf): Can maybe try out a few interesting ones when I'm done with the implementation.

3. [Caching in Lists](ttps://arxiv.org/pdf/2306.06942)
