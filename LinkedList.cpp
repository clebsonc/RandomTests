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
        LinkedList(){
            this->head = nullptr;
        }
        
        ~LinkedList(){
            Node<T> * aux = head;
            while(head!=nullptr){
                head = head->getNext();
                delete(aux);
                aux = head;
            }
            delete(head);
        }


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

        void printList(){
            Node<T> * aux = head;
            while(aux!=nullptr){
                printf("%f ", aux->getValue());
                aux = aux->getNext();
            }
            printf("\n");
        }
};


int main(){
    LinkedList <double> a;
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
    int remove;
    std::cout << "Remove: ";
    std::cin>> remove;
    a.removeElement(remove);
    a.printList();

    return 0;
}
