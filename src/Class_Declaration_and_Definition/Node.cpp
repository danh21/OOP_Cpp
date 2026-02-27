#include <bits/stdc++.h>
using namespace std;

class Node
{
    // non-member friend
    friend void setPrev( Node*, Node* );
public:
    Node* succ();
    Node* pred();
    Node();
protected:
    void setNext( Node* );
private:
    Node* prev;
    Node* next;
};

Node::Node() : prev(nullptr), next(nullptr) {}

// member can access private data
void Node::setNext( Node* p ) { next = p; }

// non-member friend, golobal function can access private data
void setPrev( Node* p, Node* n ) { n->prev = p; }

Node* Node::pred() {
    return prev;
}

int main() {
    Node a, b;
    Node* c;
    
   cout << "a: " << &a << "\tb: " << &b << endl;
   
    setPrev(&a, &b);
    cout << ((b.pred() == &a) ? "b->prev = a" : "b->prev != a");
}