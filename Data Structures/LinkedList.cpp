
#include <iostream>
using namespace std;


class Node {

    private:
        int value;
        Node* next;

    public:
        Node(int v){
            this->value = v;
        }

        int getValue() const {return value;}
        Node* getNext() const {return next;}

        void setValue(int v) {this->value = v;}
        void setNext(Node* n){this->next = n;}
};

class MennaLinkedList {


    private:
        Node* head; 

    public:
        MennaLinkedList(){
            head = nullptr;
        }

        void add(int newElement){
            // TODO
            /**
            1. create new node
            2. node points to same as head
            3. head points to the new node
            */
            Node* newNode = new Node(newElement);
            newNode->setNext(head);
            head = newNode;
        }

        void remove(int indexOfElementToBeDeleted){
            // TODO
            // * first of all, make sure that list is not empty
            if(head == nullptr){
                cout<<"List is already empty"<<endl;
                return;
            }

            // * First case: if index = 0
            if(indexOfElementToBeDeleted == 0){
                Node* temp = head;
                head = head->getNext();
                delete temp;
            }else{
                // * second cases: 
                Node* prev = head;
                for(int i = 0; i<indexOfElementToBeDeleted-1; ++i){
                    prev = prev->getNext();
                }
                Node* temp = prev->getNext(); //* element to be deleted
                prev->setNext(temp->getNext());
                delete temp;
            }

            
        }

        int getElementAtIndex(int index){
            // TODO
            if(head == nullptr){
                cout<<"List is empty"<<endl;
                return -1;
            }
            int counter = 0; //* loops from 0 -> index
            Node* temp=head; // * must not be null

            while( temp != NULL &&  counter < index){
                counter ++;
                temp = temp->getNext();
            }

            // * if counter < index, temp == null. index requested is out of bound
            if( counter < index && temp == NULL)
            {
                cout<<"Index "<<index<<" out of bounnd"<<endl;
                return -1;
            }
            // * here, i am sure we found the element
            return temp->getValue();
        }

        void reverse(){
            // TODO: Assignment by Menna
        }

        void print(){
            
            Node* currentElement = head;
            while(currentElement != nullptr){
                cout<<currentElement->getValue()<<", ";
                currentElement = currentElement->getNext();
            }
            cout<<"\n";

        }
};

int main(){


    MennaLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.print();
    cout<<"Element at 4 is: "<<list.getElementAtIndex(4)<<endl;
    cout<<"Element at 0 is: "<<list.getElementAtIndex(0)<<endl;
    cout<<"Element at 2 is: "<<list.getElementAtIndex(2)<<endl;
    cout<<"Element at 7 is: "<<list.getElementAtIndex(7)<<endl;

    list.remove(0); // *  prints 4, 3, 2, 1
    list.print();
    list.remove(2); // * prints  4, 3, 1
    list.print();

    // * Reverse liked list
    // *** 5 4 3 2 1
    // TODO:  list.reverse()
    // *** 1 2 3 4 5

   return 0; 

}
