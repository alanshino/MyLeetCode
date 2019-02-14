typedef struct {
    int data;
    int index;                                             // 標註當前佇列的位置
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *pqueue=malloc(sizeof(MyQueue)*maxSize);
    pqueue->index=0;
    //(pqueue+1)->index=0;
    return pqueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    (obj+(obj->index))->data=x;
    obj->index+=1;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int temp=obj->data,i=0;                                          // 取出第一個位置的值
    for (i=0;i<(obj->index-1);i++){                                  // 後面的值依序補上
        (obj+i)->data=(obj+i+1)->data;
    }
    obj->index-=1;                                                   // 總佇列數減1
    return temp;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->data;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->index==0)?1:0;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

 /**
 typedef struct
{
	int *stack;
	int begin, end;
	int maxSize;
}MyQueue;

MyQueue *myQueueCreate(int maxSize)
{
	MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue->begin = 0;
	queue->end = 0;
	queue->maxSize = maxSize;
    queue->stack = (int*)malloc(sizeof(int) * queue->maxSize);

    return queue;
}
void myQueuePush(MyQueue *queue, int x)
{
	if(queue->end == queue->maxSize){
		for(int i = queue->begin; i < queue->end; i++)
			queue->stack[i - queue->begin] = queue->stack[i];
		queue->begin = 0;
		queue->end -= queue->begin;
	}
	queue->stack[queue->end++] = x;
}
int myQueuePop(MyQueue *queue)
{
	int temp = queue->stack[queue->begin];
	queue->begin++;
	return temp;
}
int myQueuePeek(MyQueue *queue)
{
	return queue->stack[queue->begin];
}
bool myQueueEmpty(MyQueue *queue)
{
	return queue->begin == queue->end;
}
void myQueueFree(MyQueue *queue)
{
	free(queue->stack);
	free(queue);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

 /**
 typedef struct {
    int readIdx;
    int writeIdx;
    int *arr;
    int size;
} MyQueue;

// Initialize your data structure here.
MyQueue* myQueueCreate(int maxSize) {
	// create the struct
    MyQueue *obj = malloc(sizeof(MyQueue));
    obj->readIdx = 0;
    obj->writeIdx = 0;
    obj->size = maxSize;
    // dynamicly alloc maxSize + 1
	obj->arr = malloc( (maxSize + 1) * sizeof(int) );
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	if ( (obj->writeIdx + 1) % obj->size == obj->readIdx) {
		return;
	}
    obj->arr[obj->writeIdx] = x;
    obj->writeIdx = (obj->writeIdx + 1) % obj->size;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if ( obj->readIdx == obj->writeIdx ) {
		return -1;
	}
    int e = obj->arr[obj->readIdx];
    obj->readIdx = (obj->readIdx + 1) % obj->size;
    return e;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if ( obj->readIdx == obj->writeIdx ) {
		return -1;
	}
    int e = obj->arr[obj->readIdx];
    return e;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if ( obj->readIdx == obj->writeIdx ) {
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

/** Python
class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack_in = []
        self.stack_out = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.stack_in.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        return self.stack_out.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if self.stack_out:
            return self.stack_out[-1]
        else:
            return self.stack_in[0]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.stack_out)==0 and len(self.stack_in)==0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
*/

/** Java
class MyQueue {
    private final Stack<Integer> pushStack;
    private final Stack<Integer> popStack;


    /** Initialize your data structure here. */
    public MyQueue() {
        pushStack = new Stack<>();
        popStack = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        pushStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.peek());
                pushStack.pop();
            }
        }

        int ret = popStack.peek();
        popStack.pop();
        return ret;
    }

    /** Get the front element. */
    public int peek() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.peek());
                pushStack.pop();
            }
        }

        return popStack.peek();

    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return pushStack.empty() && popStack.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */

 /** Java
class MyQueue {
    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();

    /** Initialize your data structure here. */
    public MyQueue() {

    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        while(!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        stack1.push(x);
        while(!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return stack1.pop();
    }

    /** Get the front element. */
    public int peek() {
        return stack1.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
 /** Python
 class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = list()
        self.top = None

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.stack.append(x)
        if not self.top:
            self.top = x

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        tmp = list()
        while len(self.stack) > 1:
            tmp.append(self.stack.pop())
        ans = self.stack.pop()
        first = True
        while tmp:
            val = tmp.pop()
            if first:
                self.top = val
                first = False
            self.stack.append(val)
        if self.empty():
            self.top = None
        return ans

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        return self.top

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.stack) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
*/
