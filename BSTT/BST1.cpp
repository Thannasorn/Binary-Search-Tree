#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class BinarySearchTree;

template <class Comparable>
class BinaryNode {
Comparable element;
BinaryNode *left;
BinaryNode *right;
BinaryNode(const Comparable & theElement, BinaryNode *lt, 
BinaryNode *rt) :
element(theElement), left(lt), right(rt) {}

friend class BinarySearchTree <Comparable>;
};

template <class Comparable>
class BinarySearchTree
{
public:
explicit BinarySearchTree(const Comparable & notFound);
BinarySearchTree(const BinarySearchTree & rhs);
//~BinarySearchTree();

const Comparable & findMin() const;
const Comparable & findMax() const;
const Comparable & find(const Comparable & x) const;

bool isEmpty() const;
void printTree() const;
void printPre()const;
void printPost()const;
void makeEmpty();

void insert(const Comparable & x);
void remove(const Comparable & x);

const BinarySearchTree & operator=(const BinarySearchTree & rhs);





private:
BinaryNode< Comparable > *root;
Comparable ITEM_NOT_FOUND;
const Comparable & elementAt(BinaryNode< Comparable> *t) const;
void insert(const Comparable & x, BinaryNode< Comparable> * & t) 
const;
void remove(const Comparable & x, BinaryNode< Comparable> * & t) 
const;

BinaryNode<Comparable> * findMin
(BinaryNode<Comparable> *t) const;
BinaryNode<Comparable> * findMax
(BinaryNode<Comparable> *t) const;
BinaryNode<Comparable> * find(const Comparable & x,
BinaryNode<Comparable> *t)const;

void makeEmpty(BinaryNode< Comparable> * & t) const;
void printTree(BinaryNode< Comparable> *t) const;
void printPre(BinaryNode< Comparable> *t)const;
void printPost(BinaryNode< Comparable> *t)const;

BinaryNode<Comparable> * clone(BinaryNode<Comparable> *t) const;
};

template <class Comparable>
BinarySearchTree<Comparable> ::BinarySearchTree(const Comparable & notFound)
{
root = NULL;
ITEM_NOT_FOUND = notFound;
};

template <class Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
return root == NULL;
}






//---------------------------------------------------------------------Print Tree---------------------------------------------------------------------------
template <class Comparable>
void BinarySearchTree<Comparable>::printTree() const
{
if (isEmpty())
cout << "Empty tree" << endl;
else
printTree(root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::printPre()const
{
if (isEmpty())
cout << "Empty tree" << endl;
else
printPre(root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::printPost()const
{
if (isEmpty())
cout << "Empty tree" << endl;
else
printPost(root);
}

template <class Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode<Comparable> *t)
const
{
if (t != NULL)
{
printTree(t->left);
cout << " " << t->element << " ";
printTree(t->right);
}
}








template <class Comparable>
void BinarySearchTree<Comparable>::printPre(BinaryNode<Comparable> *t) const
{
if (t != NULL)
{
cout << " " << t->element << " ";
printPre(t->left);
printPre(t->right);
}
}

template <class Comparable>
void BinarySearchTree<Comparable>::printPost(BinaryNode<Comparable> *t)
const
{
if (t != NULL)
{
printPost(t->left);
printPost(t->right);
cout << " " << t->element << " ";
}
}
//------------------------------------------------------------------------------find---------------------------------------------------------------------------------
template <class Comparable>
const Comparable & BinarySearchTree<Comparable> ::find(const 
Comparable & x)
const
{
return elementAt(find(x, root));
};

template <class Comparable>
const Comparable & BinarySearchTree<Comparable> ::findMax() const
{
return elementAt(findMax(root));
};

template <class Comparable>
const Comparable & BinarySearchTree<Comparable> ::findMin() const
{
return elementAt(findMin(root));
};

template <class Comparable>
const Comparable & BinarySearchTree<Comparable> ::elementAt
(BinaryNode<Comparable> *t) const
{
if (t == NULL) return ITEM_NOT_FOUND;
else return t->element;
};

template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::find(const Comparable & x,
BinaryNode<Comparable> *t) const
{
if (t == NULL) return NULL;
else if (x < t->element)
return find(x, t->left);
else if (t->element < x)
return find(x, t->right);
else
cout << "\tFound"<< endl;
cout << "Binary Address is " << t << endl;
return t;
};

template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree <Comparable> ::findMin(BinaryNode<Comparable> * t) 
const
{
if (t == NULL) return NULL;
if (t->left == NULL) return t;
return findMin(t->left);
};

template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree <Comparable> ::findMax(BinaryNode<Comparable> * t) 
const
{
if (t != NULL)
while (t->right != NULL)
t = t->right;
return t;
};



//--------------------------------------------------------------------------------insert--------------------------------------------------------------------------
template <class Comparable> void
BinarySearchTree <Comparable> ::insert(const Comparable & x,
BinaryNode <Comparable> * & t) const
{
if (t == NULL)
t = new BinaryNode<Comparable>(x, NULL, NULL);
else if (x < t->element)
insert(x, t->left);
else if (t->element < x)
insert(x, t->right);
else
; // Duplicate; do nothing
};
template <class Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
insert(x, root);
};
//--------------------------------------------------------------------------------remove--------------------------------------------------------------------------
template <class Comparable> void
BinarySearchTree <Comparable> ::remove(const Comparable & x, 
BinaryNode <Comparable> * & t) const
{
if (t == NULL) {
cout <<"Empty element please insert element again.." <<endl;
return; // Item not found; do nothing
}
if (x < t->element) remove(x, t->left);
else if (t->element < x) remove(x, t->right);
else if (t->left != NULL && t->right != NULL) { // Two children
t->element = findMin(t->right)->element;
remove(t->element, t->right);
}
else {
BinaryNode<Comparable> *oldNode = t;
t = (t->left != NULL) ? t->left : t->right;
delete oldNode;
cout << "Remove Element.." << endl;
}
};
template <class Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
remove(x, root);
};
//----------------------------------------------------------------------------------main-----------------------------------------------------------------------------
int main()
{
BinarySearchTree<int> a(-999);
char menu,menu2,menu3;
int s,c,n;
do
{
system("cls");
cout<<"==============================\n" ;
cout<<"| Main Menu |\n" ;
cout<<"==============================\n" ;
cout<<"| 1. Insert |\n" ;
cout<<"| 2. PrintTree |\n" ;
cout<<"| 3. Remove |\n" ;
cout<<"| 4. Find |\n" ;
cout<<"| 5. Quit |\n" ;
cout<<"==============================\n" ;
cout<<"Enter Choice : ";
cin>>menu;

switch(menu)
{
case '1' :
cout << "Enter Element : ";
cin>>s;
a.insert(s);
system("pause");
break;
case '2' :do{
system("cls");
cout<<"-----------------------\n";
cout<<"| Menu |\n" ;
cout<<"-----------------------\n";
cout<<"| 1. Print Preorder |\n" ;
cout<<"| 2. Print Inorder |\n" ;
cout<<"| 3. Print Postorder |\n" ;
cout<<"| 4. Quit |\n" ;
cout<<"-----------------------\n";
cout<<"Enter Choice : ";
cin>>menu2;
switch(menu2)
{
case '1' :
cout<<endl;
cout<<" Pre-Order "<<endl;
cout<<" -------------------"<<endl;
a.printPre();
cout<<endl;
system("pause");
break;
case '2' :
cout<<endl;
cout<<" In-Order "<<endl;
cout<<" -------------------"<<endl;
a.printTree();
cout << endl;
system("pause");
break;
case '3' :
cout<<" Post-Order "<<endl;
cout<<" -------------------"<<endl;
a.printPost();
cout<<endl;
system("pause");
break;
}
}while(menu2 != '4');
break;
case '3':
cout << "Enter Element : ";
cin>>c;
cout << endl;
a.remove(c);
cout << endl;
system("pause");
break;
case'4' :do{
system("cls");
cout<<"-----------------------\n";
cout<<"| Menu |\n" ;
cout<<"-----------------------\n";
cout<<"| 1. Find Element |\n" ;
cout<<"| 2. Find Max |\n" ;
cout<<"| 3. Find Min |\n" ;
cout<<"| 4. Quit |\n" ;
cout<<"-----------------------\n";
cout<<"Enter Choice : ";
cin>>menu3;
switch(menu3)
{
case '1' :
cout << "Enter Element : ";
cin>>n;
cout<<" Find-Element "<<endl;
cout<<" -------------------"<<endl;
if(a.find(n)==-999)
{
cout << "Not Found" << endl;
}
cout<<endl;
system("pause");
break;
case '2' :
int fm;
cout<<" Find-Max "<<endl;
cout<<" -------------------"<<endl;
fm = a.findMax();
if (fm == -999)
{
cout << "Not Found";
}
else
cout <<"Max data in tree is : " << fm;
cout<<endl;
system("pause");
break;
case '3' :
int fmm;
cout<<" Find-Min "<<endl;
cout<<" -------------------"<<endl;
fmm = a.findMin();
if (fmm == -999)
{
cout << "Not Found";
}
else
cout << "Min data in tree is : " << 
fmm;
cout<<endl;
system("pause");
break;
}
}while( menu != '4');
break;
}
}while( menu != '5');
return (0);
}
