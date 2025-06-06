class Node:
    def __init__(self, key, value):
        self.key = key        # store the key (needed for removal from hashmap)
        self.value = value    # store the value
        self.prev = None      # pointer to previous node
        self.next = None      # pointer to next node

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.cache = {}  # maps key -> node

        # Dummy head and tail to avoid edge checks
        self.head = Node(0, 0)  # least recently used
        self.tail = Node(0, 0)  # most recently used
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node):
        """Remove node from the linked list."""
        prev = node.prev
        nxt = node.next
        prev.next = nxt
        nxt.prev = prev

    def _add_to_tail(self, node):
        """Add node right before the tail (most recently used)."""
        prev = self.tail.prev
        prev.next = node
        node.prev = prev
        node.next = self.tail
        self.tail.prev = node

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.cache:
            node = self.cache[key]
            self._remove(node)
            self._add_to_tail(node)
            return node.value
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.cache:
            self._remove(self.cache[key])
        
        node = Node(key, value)
        self.cache[key] = node
        self._add_to_tail(node)

        if len(self.cache) > self.capacity:
            # Remove LRU from head
            lru = self.head.next
            self._remove(lru)
            del self.cache[lru.key]
