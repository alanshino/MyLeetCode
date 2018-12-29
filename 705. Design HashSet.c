typedef struct MyHashSet{
    int data;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* pinit=calloc(1000001,sizeof(MyHashSet)); //用calloc初始每個元素為0
    return pinit;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    (*(obj+key)).data=1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    (*(obj+key)).data=0;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    if ((*(obj+key)).data==1){
        return 1;
    }else{
        return 0;
    }
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * struct MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 * myHashSetRemove(obj, key);
 * bool param_3 = myHashSetContains(obj, key);
 * myHashSetFree(obj);
 */
