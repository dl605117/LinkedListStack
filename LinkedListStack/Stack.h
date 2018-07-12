#pragma once

class Stack
{
private:
	class Node
	{
	public:
		Node( int val, Node* next )
			:
			val( val ),
			next( next )
		{
		}
		Node( const Node& src )
			:
			val( val )
		{
			if ( src.next != nullptr )
			{
				next = new Node( *src.next );
			}
		}
		int GetVal() const
		{
			return val;
		}
		Node* Disconnect()
		{
			auto temp = next;
			next = nullptr;
			return temp;
		}
		int CountNodes() const
		{
			if ( next != nullptr )
			{
				return next->CountNodes() + 1;
			}
			return 1;
		}
	private:
		Node* next = nullptr;
		int val;
	};
public:
	Stack() = default;
	Stack( const Stack& src );
	Stack& operator=( const Stack& src );
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	Node* root = nullptr;
};