#include "lab.hpp"

void lab2::asig1(){
	std::cout<<"A1:"<<std::endl;
	char a6[] = "you shall not pass";
	std::cout<<"Input: \""<<a6<<"\""<<std::endl;
	for (auto* a = std::end(a6); a >= std::begin(a6); a--){
		std::cout << *a;
	}
	std::cout<<std::endl<<std::endl;
}

void lab2::asig2(){
	std::cout<<"A2:"<<std::endl;
	char a6[] = "you shall not pass";
	std::cout<<"Input: \""<<a6<<"\""<<std::endl;
	int i = 0, length = 0;
	auto* p = a6;   
	while(i[p]!=0){
		*p++;
		length++;
	}
	std::cout<<"Longitud: "<<length<<std::endl<<std::endl;
}

void lab2::asig3(){
	std::cout<<"A3:"<<std::endl;
	lab2::List<float> l1;
	for(float i=10.0; i > 0.0; i--){
		l1.insert(i);
	}
	std::cout<<"Input (Linked list): "; l1.show(); std::cout<<std::endl;
	std::cout<<"Search for MIN: "<< l1.minimum()->key; std::cout<<std::endl;
	std::cout<<"Search for MAX: "<< l1.maximum()->key; std::cout<<std::endl;
	std::cout<<"Search for SUCC of 5.0: "<< l1.successor(5.0)->key; std::cout<<std::endl;
	std::cout<<"Search for PRED of 5.0: "<< l1.predecessor(5.0)->key; std::cout<<std::endl;
	std::cout<<std::endl;
}

void lab2::asig4(){
	std::cout<<"A4:"<<std::endl;
	lab2::List<int> l1;
	for(int i=20; i > 0; i--){
		l1.insert(i%10);
	}
	std::cout<<"Input (Linked list): "; l1.show(); std::cout<<std::endl;
	l1.delete_duplicates();
	std::cout<<"Duplicates removed: "; l1.show(); std::cout<<std::endl;
	std::cout<<"Search for k-th value (k=8): "<< l1[8]; std::cout<<std::endl;
	l1.delete_mid_node();
	std::cout<<"Mid node removed: "; l1.show(); std::cout<<std::endl;
	lab2::TwoLists<int> two_lists = l1.partition_by(5);
	std::cout<<"Partition by 5: "; two_lists.list1.show(); std::cout<<"  ";  two_lists.list2.show();
	std::cout<<std::endl;
	return;
}

template<class T>
const typename lab2::List<T>::Node& lab2::List<T>::search(const T key){               			// Return object address        
	Node* node = head;                          // Point to list head
	while(node != nullptr && node->key != key)  // While list is not empty or value not found
		node = node->next;                      // Pointer reassigment
	return node;
}    

template<class T>
void lab2::List<T>::insert(const T key){
	Node* node = new Node{key};           // Create Node in free storage (dynamic memory)
	sz++;
	if(head == nullptr)
		head = node;
	else{
		head->prev = node;
		node->next = head; 
		head = node;
	}
} 

template<class T>
void lab2::List<T>::erase(const T key) {
	Node* node = search(key);                // Get reference, if any, to object to delete
	if(node != nullptr){
		Node* pred = node->prev;
		Node* succ = node->next;
		if(pred != nullptr)
			pred->next = node->next;
		else
			head = node->next;

		if(succ != nullptr)
			succ->prev = node->pred;
		sz--;
	}
	delete node;                                // What if node is nullptr
}

template<class T>
int lab2::List<T>::size() {
	return sz;
}

template<class T>
void lab2::List<T>::show(){ 
	Node* node = head;
	std::cout<<"[ ";
	while( node != nullptr) {
		std::cout << node->key << ", ";
		node = node->next;
	}
	std::cout<<"]";
}


template<class T>
std::ostream& lab2::List<T>::operator<<(std::ostream& os){ 
	Node* node = head;                          
	while(node != nullptr){
		os << node->key << ", "; 
		node = node->next; 
	}
	os << "\n"; 
	return os; 	
}


template<class T>
const typename lab2::List<T>::Node* lab2::List<T>::minimum(){
	Node* min_node = head;
	Node* node = head->next;
	while(node != nullptr){
		if(min_node->key > node->key)
			min_node = node;
		node = node->next;
	}
	return min_node;
}

template<class T>
const typename lab2::List<T>::Node* lab2::List<T>::maximum(){
	Node* max_node = head;
	Node* node = head->next;
	while(node != nullptr){
		if(max_node->key < node->key)
			max_node = node;
		node = node->next;
	}
	return max_node;
}

template<class T>
const typename lab2::List<T>::Node* lab2::List<T>::successor(const T key){
	Node* node = head;
	while(node != nullptr){
		if(node->key == key)
			return node->next;
		node = node->next;
	}
	return nullptr;
}

template<class T>
const typename lab2::List<T>::Node* lab2::List<T>::predecessor(const T key){
	Node* node = head;
	while(node != nullptr){
		if(node->key == key)
			return node->prev;
		node = node->next;
	}
	return nullptr;
}


template<class T>
T lab2::List<T>::operator[](int k){ 
	Node* node = head;
	int index = 0;
	while(node != nullptr){
		if(index == k)
			return node->key;
		index++;
		node = node->next;
	}
	return T{};
}

template<class T>
void lab2::List<T>::delete_duplicates(){
	Node *node1, *node2, *tmp; 
    node1 = head; 
    while (node1 != nullptr && node1->next != nullptr) { 
        node2 = node1; 
        while (node2->next != nullptr) 
        { 
            if (node1->key == node2->next->key){ 
                tmp = node2->next; 
                node2->next = node2->next->next; 
                delete(tmp); sz--;
            } 
            else
                node2 = node2->next; 
        } 
        node1 = node1->next; 
    } 
}

template<class T>
void lab2::List<T>::delete_mid_node(){
	Node *node = head, *tmp;
	int i_mid = sz/2;
	for(int i=1; i < i_mid; i++){
		node = node->next;
	}
	tmp = node->next; 
	node->next = node->next->next; 
	delete(tmp);
	sz--;
}

template<class T>
typename lab2::TwoLists<T> lab2::List<T>::partition_by(const T key){
	Node *node = head;
	lab2::TwoLists<T> two_lists;
	while(node != nullptr){
		if(node->key > key)
			two_lists.list1.insert(node->key);
		else
			two_lists.list2.insert(node->key);
		node = node->next;
	}
	return two_lists;
}
