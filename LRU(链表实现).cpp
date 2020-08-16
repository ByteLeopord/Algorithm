//双向链表：表头是最近访问的节点 表尾是最早访问的节点
//当容量不足时，总是删除表尾的节点
//添加新节点或操作已存在的节点，都将该节点移动到表头
struct LRUNode{
    int key;
    int val;
    struct LRUNode* pre;
    struct LRUNode* next;
    LRUNode(int k, int v):key(k), val(v), pre(nullptr), next(nullptr){}
};

class LRUCache {
private:
    int capacity_;
    int size;
    unordered_map<int, LRUNode*> hash;
    LRUNode* head;
    LRUNode* tail;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        size = 0;
        head = new LRUNode(-1, -1);
        tail = new LRUNode(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(hash.count(key) == 0){
            return -1;
        }
        LRUNode* node = hash[key];
        movetoHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            hash[key]->val = value;
            return;
        }

        LRUNode* node = new LRUNode(key, value);
        addtoHead(node);
        hash.insert(make_pair(key, node));
        size++;
        if(size > capacity_){
            LRUNode* removenode = removeTail();
            hash.erase(removenode->key);
            size--;
            delete removenode;
        }
    }

    void addtoHead(LRUNode* node){
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    void removeNode(LRUNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void movetoHead(LRUNode* node){
        removeNode(node);
        addtoHead(node);
    }
    LRUNode* removeTail(void){
        LRUNode* node = tail->pre;
        removeNode(node);
        return node;
    }
};
