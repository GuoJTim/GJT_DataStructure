#include "BinaryTreeSearch.h"


template <class T>
BinaryTreeSearch<T>::BinaryTreeSearch():BinaryTree<T>(){
	
}

template <class T>
BinaryTreeSearch<T>::BinaryTreeSearch(const BinaryTreeSearch<T>& s):BinaryTree<T>(s){
	
}

template <class T>
TreeNode<T>* BinaryTreeSearch<T>::MINIMUM(TreeNode<T>* node){
	while(node->left != nullptr) node = node->left;
	return node;
}

template <class T>
TreeNode<T>* BinaryTreeSearch<T>::MAXIMUM(TreeNode<T>* node){
	while(node->right != nullptr) node = node->right;
	return node;
}


template <class T>
TreeNode<T>* BinaryTreeSearch<T>::Search(T data){
	return Search(BinaryTree<T>::root,data);
}

template <class T>
TreeNode<T>* BinaryTreeSearch<T>::Search(TreeNode<T>* node,T data){
	if(node == nullptr || data == node->data) return node;
	if (data < node->data) return Search(node->left,data);
	else return Search(node->right,data);
}

template <class T>
void BinaryTreeSearch<T>::Successor(TreeNode<T>* node){
	if (node->right != nullptr) return MINIMUM(node->right);
	TreeNode<T>* y = node->parent;
	while (y != nullptr && node == y->right){
		node = y;
		y = y.parent;
	}
	return y;
}

template <class T>
void BinaryTreeSearch<T>::Predecessor(TreeNode<T>* node){
	if (node->left != nullptr) return MAXIMUM(node->left);
	TreeNode<T>* y = node->parent;
	
	while (node != nullptr && node == y->left){
		node = y;
		y = y.parent;
	}
	return y;
}

template <class T>
void BinaryTreeSearch<T>::Insert(TreeNode<T>* z){
	BinaryTree<T>::size++;
	TreeNode<T>* y = nullptr;
	TreeNode<T>* x = BinaryTree<T>::root;
	while (x != nullptr){
		y = x;
		if (z->data < x->data) x = x->left;
		else x = x->right;
	}
	z->parent = y;
	if (y == nullptr) {
		BinaryTree<T>::root = z;
	}else if (z->data < y->data) y->left = z;
	else y->right = z;
}

template <class T>
void BinaryTreeSearch<T>::Transplant(TreeNode<T>* u,TreeNode<T>* v){
	if(u->parent == nullptr) BinaryTree<T>::root = v;
	else if(u->parent->left == u) u->parent->left = v;
	else u->parent->right = v;
	if (v != nullptr) v->parent = u->parent;
}

template <class T>
void BinaryTreeSearch<T>::Delete(TreeNode<T>* z){
	BinaryTree<T>::size--;
	if (z->left == nullptr) Transplant(z,z->right);
	else if (z->right == nullptr) Transplant(z,z->left);
	else {
		TreeNode<T> *y = MINIMUM(z->right);
		if (y->parent != z){
			Transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
}





template <class K,class V>
Dictionary<K,V>::Dictionary():BinaryTreeSearch<std::pair<K,V>>(){
	
}

template <class K,class V>
Dictionary<K,V>::Dictionary(const Dictionary<K,V>& s):BinaryTreeSearch<std::pair<K,V>>(s){
	
}

template <class K,class V>
bool Dictionary<K,V>::IsEmpty() const{
	return BinaryTree<std::pair<K,V>>::root == nullptr;
}

template <class K,class V>
void Dictionary<K,V>::Insert(const std::pair<K,V>& thePair){
	BinaryTree<pair<K,V>>::size++;
	TreeNode<pair<K,V>> *p = BinaryTree<std::pair<K,V>>::root, *pp = nullptr;
	while(p!= nullptr){
		pp = p;
		if (thePair.first < p->data.first) p = p->left;
		else if(thePair.first > p->data.first) p = p->right;
		else{//duplicate, update associate element
			p->data.second = thePair.second;
			return;
		}
	}
	p = new TreeNode<pair<K,V>>(thePair);
	if(BinaryTree<std::pair<K,V>>::root != nullptr){
		if (thePair.first < pp->data.first) pp->left = p;
		else pp->right = p;
		p->parent = pp;
	}else {
		BinaryTree<std::pair<K,V>>::root = p;
		p->parent = nullptr;
	}
}

template <class K,class V>
void Dictionary<K,V>::Delete(const K& k){
	TreeNode<pair<K,V>> *element = Search(k);
	if (element == nullptr) return;
	BinaryTreeSearch<pair<K,V>>::Delete(element);
}


template <class K,class V>
TreeNode<pair<K,V>>* Dictionary<K,V>::Search(K data){
	return Search(BinaryTreeSearch<pair<K,V>>::root,data);
}

template <class K,class V>
TreeNode<pair<K,V>>* Dictionary<K,V>::Search(TreeNode<pair<K,V>>* node,K data){
	if(node == nullptr || data == node->data.first) return node;
	if (data < node->data.first) return Search(node->left,data);
	else return Search(node->right,data);
}




template <class K,class V>
pair<K,V>* Dictionary<K,V>::Get(const K&k){
	return Get(BinaryTree<std::pair<K,V>>::root,k);
}

template <class K,class V>
pair<K,V>* Dictionary<K,V>::Get(TreeNode<std::pair<K,V>>* p,const K &k){
	if (p == nullptr) return nullptr;
	if (k < p->data.first) return Get(p->left,k);
	if (k > p->data.first) return Get(p->right,k);
	return &p->data;
}

