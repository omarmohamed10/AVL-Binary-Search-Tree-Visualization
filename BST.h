#ifndef BST_H
#define BST_H
#include <iostream>
#include <QGraphicsView>
#include <QTextStream>
#include <QProcess>

using namespace std;

struct Node{
    Node *p;
    int key;
    Node *left;
    Node *right;
    int height;
};

class BST
{
    public:

        Node* root;
        int max(int a, int b);
        int getBalance( Node *N);
        Node * minValueNode( Node* node);
        Node* deleteNode(int key);
        void init(QGraphicsScene* scene, QGraphicsView* view);
        int diff(Node *);
        Node* insert(int value);
        Node* balance(Node *temp);
        Node *rr_rotation(Node *);
        Node *ll_rotation(Node *);
        Node *lr_rotation(Node *);
        Node *rl_rotation(Node *);
        int height(Node *);
        void inorder(Node *);
        void preorder(Node *);
        void postorder(Node *);
        BST();
        void show();
        int countNodes();
        int countLevels();
        int countLeftNodes();
        Node* findElem(int val);
    protected:
    private:
        int countNodes(Node* p);
        int countLevels(Node* p);
        int countLeftNodes(Node *p);
        Node* findSuccessor(int val);
        QByteArray _prepareGraph();
        void _graphWalk(Node* p,  QTextStream* stream);
        Node* findElem(int val, Node* p);
        Node* insert(Node*p , int value);
        Node* deleteNode(Node* root, int key);
        Node* _root;
        QGraphicsScene* _scene;
        QGraphicsView* _view;
};

#endif // BST_H
