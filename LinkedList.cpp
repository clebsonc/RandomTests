#include<iostream>
#include<new>
#include<string>
#include<sstream>


template <typename T>
class Node{
    private:
        Node<T> * next;
        T value;
    public:
        Node<T>(){  // Default Constructor
            this->next = nullptr;
        }
        Node(T val):value(val){};

        Node(T val, Node*){
            this->next = nullptr;
            this->value = val;
        }

        void setNext(Node* next){
            this->next = next;
        }

        void setValue(T val){
            this->value = val;
        }

        T getValue(){
            return this->value;
        }

        Node * getNext(){
            return this->next;
        }
};


template <typename T>
class LinkedList{
    private:
        Node<T> * head;
    public:
        // Default constructor
        LinkedList(){
            this->head = nullptr;
        }
        

        // Destructor
        ~LinkedList(){
            Node<T> * aux = head;
            while(head!=nullptr){
                head = head->getNext();
                delete(aux);
                aux = head;
            }
            delete(head);
        }
        
        // Overload operator plus
        LinkedList<T> operator+(LinkedList<T> & param){
            LinkedList<T> temp;
            Node <T> * aux = this->head;
            while(aux->getNext() != nullptr)
                aux = aux->getNext();
            aux->setNext(param.head);
            return temp;
        }
        

        /**
        TODO: Add the copy constructor
        */
        
        
        /**
        TODO: Add the Copy Assignment
        */

        bool addInFront(T val){
            Node<T> * aux = new (std::nothrow) Node<T>();
            if(aux==nullptr){
                printf("Error while allocating memory");
                return false;
            }
            aux->setValue(val);
            if(head == nullptr){
                aux->setNext(nullptr);
            } else {  // there is/are element(s) on the list
                aux->setNext(head);
            }
            head = aux;
            return true; // successful insertion
        }
        
        void removeElement(T value){
            Node<T> * aux1 = this->head;
            Node<T> * aux2;
            while(aux1!= nullptr){
                if (aux1->getValue()!=value){
                    aux2 = aux1;
                    aux1 = aux1->getNext();
                } else{
                    if(aux1 == head){
                        head = aux1->getNext();
                        free(aux1);
                        aux1 = head;
                    } else{
                        aux2->setNext(aux1->getNext());
                        free(aux1);
                        aux1 = aux2->getNext();
                    }
                }
            }
        }

        /**
        * Recursive mToLast where the last element is:
        * n   -- 0,
        * n-1 -- 1, 
        * n-2 -- 2
        * 1   -- n-1
        */
        Node<T> * mToLast(Node<T> *h, const int& m, int & cur){
            if((*h).getNext() == nullptr){
                if(m==cur)
                    return(h);
                return nullptr;
            } else{
                Node <T> * aux; 
                aux = mToLast((*h).getNext(), m , cur);
                if(aux==nullptr){
                    cur++;
                    if(cur == m){
                        aux = h;
                        return aux;
                    } else {
                        return nullptr;
                    }
                } else {
                    return aux;
                }
            }
        }
        
        Node<T> * getHead(){
            return this->head;
        }

        void printList(){
            Node<T> * aux = head;
            while(aux!=nullptr){
                std::cout << aux->getValue() << " ";
                aux = aux->getNext();
            }
            printf("\n");
        }
};


int main(){
    LinkedList <int> a, b;
    int n;
    std::string buffer;
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> n;
    double val;
    for(int i = 0; i < n; i++){
        std::cin >> val;
        a.addInFront(val);
    }
    a.printList();
    
    /**
    std::cin.ignore();
    std::getline(std::cin, buffer);
    std::stringstream(buffer) >> n;
    for(int i = 0; i < n; i++){
        std::cin >> val;
        b.addInFront(val);
    }
    b.printList();
    
    LinkedList<int> c; 
    c = a+b;

    c.printList();

    c = a;
    c.printList();
    */
    int variable = 0; 
    Node<int> * res;
    res = a.mToLast(a.getHead(), 5, variable);
    std::cout << "Value: " << res->getValue() << std::endl;

    return 0;
}
