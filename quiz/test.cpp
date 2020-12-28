// Queue reverse_queue(Queue& q) {
//     Stack<int> x; //creates an empty stack of type int
//     while (!q.isEmpty()) {//while queue isnt empty, it adds elements of queue to stack one by one starting from the front of the queue.
//         x.push(q.first());
//         q.dequeue();
//     }
//     while (!x.isEmpty()) {//while stack isnt empty is adds elements of stack to queue one by one starting from the top.
//         q.enqueue(x.top());
//         x.pop();
//     }
// }

struct Pair {
  int x, y;
  Pair(int a=0, int b=0) : x(a), y(b) {}
};

bool linear_search(Pair *A, int n, Pair& target) {
    for (int i = 0; i < n; i++) {
        if ((A+i)->x == target.x && (A+i)->y == target.y) {
            return true;
        }
    }
    return false;
}