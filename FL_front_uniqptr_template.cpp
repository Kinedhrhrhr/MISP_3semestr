#include <iostream>
#include <memory>

template <typename T>
class ForwardList
{
     private:
	     struct Node
	     {
		     T data;
		     std::unique_ptr<Node> next;
		     explicit Node(const T& value) : data(value), next(nullptr) {} 
	     };
	     std::unique_ptr<Node> head;
     public:
	     ForwardList() = default;
	     ForwardList(const ForwardList& other) : head(nullptr)
	     {
		     if (!other.head) return;
		     head = std::make_unique<Node>(other.head->data);
		     Node* current = head.get();
		     Node* otherCurrent = other.head->next.get();

		     while(otherCurrent)
		     {
			     current->next = std::make_unique<Node>(otherCurrent->data);
			     current = current->next.get();
			     otherCurrent = otherCurrent->next.get();
		     }
	     }

	     ForwardList& operator=( const ForwardList& other )
	     {
		     if(this!= &other)
		     {
			     ForwardList temp(other);
			     std::swap(head, temp.head);
		     }
		     return *this;
	     }


	     ForwardList(ForwardList&& other) noexcept : head(std::move(other.head))
	     {
		     other.head = nullptr;
	     }	

	     ForwardList& operator=(ForwardList&& other) noexcept
	     {
		     if (this!=&other)
		     {
			     head = std::move(other.head);
			     other.head = nullptr;
		     }
		     return *this;
	     }

	     void PushFront(const T& value)
	     {
		     auto newNode = std::make_unique<Node>(value);
		     newNode->next = std::move(head);
		     head = std::move(newNode);
	     }
	     void PopFront()
	     {
		     if(head)
		     {
			     head = std::move(head->next);
		     }
	     }
	     bool empty() const
	     {
		    return head == nullptr;
	     }
	     const T& front() const
	     {
		    if (!head) throw std::out_of_range(" List is empty");
		    return head->data;
	     }
};

		    
int main()
{
	return 0;
}
