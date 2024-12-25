#include <iostream>

struct Node{
    int data;
    Node* next;   

    Node(int value) : data(value), next(nullptr){}
};

class LinkedList {
    private:
    Node* head;

    public:
    LinkedList() : head(nullptr){}
    ~LinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void append(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }else{
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() const {
        if(head == nullptr){
            std::cout << "{∅}" << std::endl;
            return;
        }
        Node* current = head;
        while(current != nullptr){
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void deleteNode(int value){
        if(head == nullptr){
            display();
        }
        //case 1: head == value
        if(head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        //xase 2: value in the list
        Node* current = head;
        while(current->next != nullptr && current->next->data != value){
            current = current->next;
        }
        if(current->next != nullptr){
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }else{
            std::cout << "failed to find value:" << value;
        }
    }
    //find if a value exist 
    bool search(int value) const{
        Node* current = head;
        while(current != nullptr){
            if(current->data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }
    //count size of list
    int size()const{
        int count = 0;
        Node* current = head;
        while(current != nullptr){
            count ++;
            current = current->next;
        }
        return count;
    }
};

    //Unit test
    int main(){
        LinkedList list;
        list.append(10);
        list.append(20);
        list.append(30);
        list.append(40);
        std::cout << "display current list:\n-----------------" << std::endl;
        list.display();
        std::cout << "size == " << list.size() << std::endl;
        
        std::cout << "searching a '20`..., :" << list.search(20) << std::endl;
        list.deleteNode(20);
        std::cout << "seraching a '20' afeter 20 deleted:" << list.search(20) << std::endl;
        std::cout << "display current list:\n-----------------" << std::endl;
        list.display();
        std::cout << "size == " << list.size() << std::endl;
        return 0;
    }