#include "Stack.h"

Stack::Stack( const Stack & src )
{
	*this = src;
}

Stack & Stack::operator=( const Stack & src )
{
	if ( !Empty() )
	{
		delete root;
		root = nullptr;
	}

	if ( !src.Empty() )
	{
		root = new Node( *src.root );
	}
	return *this;
}

Stack::~Stack()
{
	delete root;
	root = nullptr;
}

void Stack::Push( int val )
{
	root = new Node( val, root );
}

int Stack::Pop()
{
	if ( !Empty() )
	{
		const int val = root->GetVal();
		auto oldRoot = root;
		root = root->Disconnect();
		delete oldRoot;
		return val;
	}
	return -1;
}

int Stack::Size() const
{
	if ( !Empty() )
	{
		return root->CountNodes();
	}
	return 0;
}

bool Stack::Empty() const
{
	return root == nullptr;
}