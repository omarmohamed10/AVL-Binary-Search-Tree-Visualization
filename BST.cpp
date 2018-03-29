#include "BST.h"
BST::BST()
       {
           root = NULL;
       }
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int BST::getBalance( Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
int BST::max(int a, int b)
{
    return (a > b)? a : b;
}
Node *BST::minValueNode(Node* node)
{
     Node* current = node;


    while (current->left != NULL)
        current = current->left;

    return current;
}
void BST::inorder(Node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->key<<"  ";
    inorder (tree->right);
}


void BST::preorder(Node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->key<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}


void BST::postorder(Node *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->key<<"  ";
}

void BST::init(QGraphicsScene* scene, QGraphicsView* view){
    this->_root = NULL;
    this->_scene = scene;
    this->_view = view;
}
Node *BST::rr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

Node *BST::ll_rotation(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


Node *BST::lr_rotation(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

Node *BST::rl_rotation(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

Node *BST::balance(Node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

int BST::height(Node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
Node *BST::insert(Node*root  ,int value)
{
    if (root == NULL)
    {
        root = new Node;
        root->key = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->key)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->key)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }

    return root;
}

Node *BST::insert(int value){
    return this->insert(this->root, value);
}

int BST::diff(Node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}



Node* BST::findElem(int val, Node* p){
    if(p != NULL){
        if(val == p->key) return p;

        if(val < p->key){
            return findElem(val, p->left);
        }else{
            return findElem(val, p->right);
        }
    }else{
        return NULL;
    }
}

Node* BST::findElem(int val){
    return this->findElem(val, this->_root);
}

Node* BST::findSuccessor(int val){
    Node* startNode = this->findElem(val);
    Node* parent = startNode;

    startNode = startNode->right;
    while(startNode != NULL && startNode->left != NULL){
        parent = startNode;
        startNode = startNode->left;
    }

    return startNode;
}



Node* BST::deleteNode( Node* root, int key)
{

   if (root == NULL)
       return root;

   if ( key < root->key )
       root->left = deleteNode(root->left, key);

   else if( key > root->key )
       root->right = deleteNode(root->right, key);


   else
   {
       if( (root->left == NULL) || (root->right == NULL) )
       {
            Node *temp = root->left ? root->left :
                                            root->right;

           if (temp == NULL)
           {
               temp = root;
               root = NULL;
           }
            *root = *temp;
           free(temp);
       }
       else
       {

            Node* temp = minValueNode(root->right);

           root->key = temp->key;


           root->right = deleteNode(root->right, temp->key);
       }
   }


   if (root == NULL)
     return root;


   root->height = 1 + max(height(root->left),
                          height(root->right));

   int balance = getBalance(root);

   if (balance > 1 && getBalance(root->left) >= 0)  // left left case
       return rr_rotation(root);


   if (balance > 1 && getBalance(root->left) < 0)   // left right case
   {
       root->left =  ll_rotation(root->left);
       return rr_rotation(root);
   }

   if (balance < -1 && getBalance(root->right) <= 0)  // right right case
       return ll_rotation(root);


   if (balance < -1 && getBalance(root->right) > 0)  // right left case
   {
       root->right = rr_rotation(root->right);
       return ll_rotation(root);
   }

   return root;
}

Node* BST::deleteNode(int key){
    return this->deleteNode(root , key);
}

int BST::countLevels(Node* p){
        int h1 = 0, h2 = 0;

        if(p == NULL) return 0;

        if(p->left){
            h1 = countLevels(p->left);
        }

        if(p->right){
            h2 = countLevels(p->right);
        }

        return(max(h1,h2)+1);
}

int BST::countLevels(){
    return this->countLevels(this->_root);
}

int BST::countNodes(Node* p){
      if(p == NULL){
            return 0;
      }else{
            return (countNodes(p->left) + countNodes(p->right)+1);
      }
}

int BST::countNodes(){
    return this->countNodes(this->_root);
}

int BST::countLeftNodes(Node* p) {
    if(p == NULL){
          return 0;
    }else{
        return (countLeftNodes(p->left) + countLeftNodes(p->right)) + (p->left != NULL && p->right == NULL)? 1 : 0;
    }
}

int BST::countLeftNodes(){
    return this->countLeftNodes(this->_root);
}

void BST::_graphWalk(Node* p, QTextStream *stream) {
    if (p != NULL){
        *stream << "\t\t" << "n" << p->key << "[label=\"" << p->key <<"\"];" << endl;

        if(p->left != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->left->key << ";" << endl;
            this->_graphWalk(p->left, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "leftNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "leftNull" << endl;
        }

        if(p->right != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->right->key << ";" << endl;
            this->_graphWalk(p->right, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "rightNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "rightNull" << endl;
        }
    }
}

QByteArray BST::_prepareGraph(){
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;
    stream << "\tsubgraph cluster17{" << endl;

    this->_graphWalk(this->root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;
}

void BST::show(){
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(1000)){
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);

    this->_scene->addPixmap(pixmap);
    this->_view->show();
}
