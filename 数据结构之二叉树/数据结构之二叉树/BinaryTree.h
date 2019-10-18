#pragma once
#include <iostream>
#include <queue>

template <class T> class BinaryTree;

//�ӽڵ�
template <class T> 
class TreeNode
{
public:
	TreeNode()
	{
		leftChild = nullptr;
		rightChild = nullptr;
	}
	T data;
	TreeNode <T> *leftChild;
	TreeNode <T> *rightChild;
};

//��
template <class T> 
class BinaryTree
{
public:
	TreeNode <T> *root;//ָ����ڵ�

	void InOrder();//�������
	void InOrder(TreeNode <T> *currentNode);
	void PreOrder(TreeNode <T> *currentNode);//ǰ�����
	void PreOrder();
	void PostOrder();//�������
	void PostOrder(TreeNode <T> *currentNode);
	void levelOrder();//�������
	void Visit(TreeNode <T> *currentNode);
	
};

//���������������-�ڵ�-����������ÿһ���ڵ�
template <class T>
inline void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

//��������ĺ���:�ݹ�
template<class T>
inline void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		InOrder(currentNode->leftChild);
		//��ʾ��ǰ�ڵ�
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}
}



//Visit()ʵ��
template<class T>
inline void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout << currentNode->data<<" ";
}


//ǰ��������ڵ�-������-����������ÿһ���ڵ�
template<class T>
inline void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

//ǰ������ĺ���:�ݹ�
template<class T>
inline void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		//��ʾ��ǰ�ڵ�
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}

//���������������-������-�ڵ㣬��ÿһ���ڵ�
template<class T>
inline void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

//��������ĺ���:�ݹ�
template<class T>
inline void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		//��ʾ��ǰ�ڵ�
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
		Visit(currentNode);
	}
}

//������� :�ö���
template<class T>
inline void BinaryTree<T>::levelOrder()
{
	std::queue <TreeNode <T> * > q;
	TreeNode <T> *currentNode = root;
	while (currentNode)
	{
		Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty()) return;
		currentNode = q.front();
		q.pop();
	}
}

