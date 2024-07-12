#include "Binarysearchtree.h"

Binarysearchtree::~Binarysearchtree()
{
	// root : 노드들 삭제 필요
}

void Binarysearchtree::Insert(int key)
{
    Node* newNode = new Node(key);

    if (_root == nullptr)
    {
        _root = newNode;
        return;
    }

    Node* node = _root;
    Node* parent = nullptr;

    // 자리찾기, 부모찾기
    while (true)
    {
        if (node == nullptr)
            break;

        parent = node;
        if (key < node->key)
        {

            node = node->left;
        }
        else
        {
            node = node->right;

        }

    }

    newNode->parent = parent;
    if (key < parent->key)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}

void Binarysearchtree::Printree(Node* node)
{
	//cout << node->key << endl;
	
	// Tree의 전위순회 : 부모 - 왼쪽 자식들 - 오른쪽 자식들 
	// Tree의 중위순회 : 왼쪽 자식들 - 부모 - 오른쪽 자식들
	// Tree의 후위순회 : 왼쪽 자식들 - 오른쪽 자식들 - 부모
	if (node == nullptr) 
		return;


	//for (int i = 0; i < ; i++)
	//{
	//	cout << node->key << endl;
	//}

    cout << node->key << endl;
	Printree(node->left);
	Printree(node->right);
	
}

Node* Binarysearchtree::search(Node* node, int key)
{
    if (node == nullptr)
        return nullptr;

    if (node->key == key)
        return node;

    if (key < node->key)
    {
        return search(node->left, key);
    }
    else
    {
        return search(node->right, key);
    }
    

	return nullptr;
}

Node* Binarysearchtree::Min(Node* node)
{


   /* if (node->parent->left->key > node->parent->left->key)
    {
        cout << node->parent->left->key << endl;
    }
    */

    if( node == nullptr)
        return nullptr;

    if (node->left != nullptr)
        return Min(node->left);


    return node;
}

Node* Binarysearchtree::Max(Node* node)
{
    if (node == nullptr)
        return nullptr;

    if (node->right != nullptr)
        return Max(node->right);

	return node;
}

Node* Binarysearchtree::Previous(Node* node) // 부모의 이전값
{
    if (node == nullptr)
        return nullptr;

    if (node->left == nullptr)
        return node;

 /*   if (node-> left->right < node->parent)
    {
        return Previous(node->left);
    }*/

   /* else
    {
       
    }*/
    //_root->
	return Max(node->left);
}

Node* Binarysearchtree::Next(Node* node)
{
    if (node == nullptr)
        return nullptr;

    if (node->right == nullptr)
        return node;

	return Min(node->right);
}

void Binarysearchtree::Delete(Node* node)
{
    if (node == nullptr)
        return;

    if (node->left == nullptr)
    {
        Replace(node, node->right);
    }
    else if(node->right == nullptr)
    {
        Replace(node, node->left);
    }
    else
    {
        Node* prev = Previous(node);
        node->key = prev->key;
        node->data = prev->data;

        Delete(prev);
    }
}

void Binarysearchtree::Replace(Node* node1, Node* node2)
{
    if (node1->parent == nullptr)
    {
        _root = node2;
    }
    else if (node1 == node1->parent->left)
    {
        node1->parent->left = node2;
    }
    else
    {
        node1->parent->right = node2;
    }

    if (node2 != nullptr)
        node2->parent = node1->parent;

        delete node1;
        
}
