#include<stdlib.h>
#include<assert.h>
enum PointerTag
{
	THREAD, //0:����
	LINK      //1:ָ��
};
template<typename T>struct BinaryTreeThdNode
{
	T _data;
	BinaryTreeThdNode<T>*_left;
	BinaryTreeThdNode<T>*_right;
	PointerTag _leftTag;//������������־
	PointerTag _rightTag;//�Һ�����������־
	BinaryTreeThdNode(const T&x = T()) :_data(x), _left(NULL), _right(NULL), _leftTag(LINK), _rightTag(LINK)
	{}
};
template<typename T>class BinaryTreeThd
{
	typedef BinaryTreeThdNode<T> Node;
protected:
	Node*_root;
	Node*_prev;//���浱ǰ����ǰһ���ڵ�
public:
	BinaryTreeThd(const T*a, size_t size, const T& invalid) :_root(NULL), _prev(NULL)
	{
		size_t index = 0;
		_root = _CreateTreeThd(a, size, index, invalid);
	}
	void PrevOrderThread()
	{
		//ǰ��������������
		_PrevOrderThread(_root);
	}
	void PrevOrder()
	{
		//ǰ�����������
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrderThread()
	{
		//����������������
		_InOrderThread(_root);
	}
	void InOrder()
	{
		//�������
		_InOrder(_root);
		cout << endl;
	}
	void PostOrderThread()
	{
		//����������������
		_PostOrderThread(_root);
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout <<endl;
	}
protected:
	Node*_CreateTreeThd(const T*a, size_t size, size_t&index, const T&invalid)
	{
		assert(a);
		Node*root = NULL;
		if (index < size && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTreeThd(a, size, ++index, invalid);
			root->_right = _CreateTreeThd(a, size, ++index, invalid);
		}
		return root;
	}
	void _PrevOrderThread(Node*root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->_left == NULL)
		{
			root->_leftTag = THREAD;
			root->_left = _prev;
		}
		if (_prev&&_prev->_right == NULL)
		{
			_prev->_rightTag = THREAD;
			_prev->_right = root;
		}
		_prev = root;
		if (root->_leftTag == LINK)
		{
			_PrevOrderThread(root->_left);
		}
		if (root->_rightTag == LINK)
		{
			_PrevOrderThread(root->_right);
		}
	}
	void _InOrderThread(Node*root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrderThread(root->_left);//������
		if (root->_left == NULL)//��
		{
			root->_leftTag = THREAD;
			root->_left = _prev;
		}
		if (_prev&&_prev->_right == NULL)
		{
			_prev->_rightTag = THREAD;
			_prev->_right = root;
		}
		_prev = root;
		_InOrderThread(root->_right);
	}
	void _PostOrderThread(Node*root)
	{
		if (root == NULL)
		{
			return;
		}
		_PostOrderThread(root->_left);
		_PostOrderThread(root->_right);
		if (root->_left == NULL)
		{
			root->_leftTag = THREAD;
			root->_left = _prev;
		}
		if (_prev&&_prev->_right == NULL)
		{
			_prev->_rightTag = THREAD;
			_prev->_right = root;
		}
		_prev = root;
	}
	void _PrevOrder(Node*root)
	{
		if (root == NULL)
			return;
		Node*cur = root;
		while (cur)
		{
			while (cur&&cur->_leftTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			cur = cur->_right;
		}
	}
	void _InOrder(Node*root)
	{
		if (root ==NULL)
			return;
		Node*cur = root;
		while (cur)
		{
			while (cur && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
	}
	//���ű�����������������
	//��-��-��
	void _PostOrder(Node*root)
	{
		if (root == NULL)
			return;
		Node*cur = root;
		while (cur)
		{
			while (cur&&cur->_rightTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_right;
			}
			cout << cur->_data << " ";
			//��ǰ��
			while (cur->_left&&cur->_leftTag == THREAD)
			{
				cur = cur->_left;
				cout << cur->_data << " ";
			}
			cur = cur->_left;//��������
		}
	}
};
