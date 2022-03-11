#pragma once

#include<iostream>
#include<iterator>

namespace lab2{
    void asig1();
    void asig2();
    void asig3();
    void asig4();

    template<class T>
    struct TwoLists;

    template<class T>
	class List{
		private:
			using value_type = T;           // Alias
			struct Node{
				Node(const value_type k):next{nullptr}, prev{nullptr}, key{k}{}; // Constructor
				Node* next;                                                      // Right value reference to a temporary 
				Node* prev;                                                      // const indicates T cannot be changed
				value_type key;                                                  
			};
			Node* head;
			int sz;  // the size of the list
		public:
			List():head{nullptr}, sz{0}{}; // Implicit initialization
			
            // prebuilt methods by Dr. H
            const Node& search(const T key);	
            void insert(const T key);
            void erase(const T key);
            void show();
            int size();

            // homework methods 
            const Node* minimum();
            const Node* maximum();
            const Node* successor(const T key);
            const Node* predecessor(const T key); 
            void delete_duplicates();
            void delete_mid_node();
            TwoLists<T> partition_by(const T key);
            T operator[](int k);

            std::ostream& operator<<(std::ostream& os);
    };
    template<class T>
    struct TwoLists{    
        List<T> list1, list2;
    };
}
