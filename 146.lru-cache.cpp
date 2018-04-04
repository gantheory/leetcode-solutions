class Node {
 public:
  int key;
  int val;
  Node* prv;
  Node* nxt;

  Node(int k, int v) : key(k), val(v) {}
};
class LRUCache {
 public:
  Node* head;
  Node* end;
  int c;
  unordered_map<int, Node*> mp;

  LRUCache(int capacity) : c(capacity) {
    head = new Node(0, 0);
    end = new Node(0, 0);
    head->nxt = end;
    end->prv = head;
  }

  void insertNode(Node* a, Node* b, Node* c) {
    a->nxt = b, b->nxt = c, c->prv = b, b->prv = a;
  }

  void deleteNode(Node* now) {
    now->nxt->prv = now->prv, now->prv->nxt = now->nxt;
  }

  int get(int key) {
    if (!mp.count(key)) return -1;
    Node* now = mp[key];
    deleteNode(now);
    insertNode(end->prv, now, end);
    return now->val;
  }

  void put(int key, int value) {
    if (mp.count(key)) {
      Node* now = mp[key];
      now->val = value;
      deleteNode(now);
      insertNode(end->prv, now, end);
    } else {
      if ((int)mp.size() == c) {
        Node* now = head->nxt;
        deleteNode(now);
        mp.erase(now->key);
        delete now;
      }
      Node* now = new Node(key, value);
      insertNode(end->prv, now, end);
      mp[key] = now;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
