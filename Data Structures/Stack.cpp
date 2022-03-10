#include<iostream>
using namespace std;



class AhmedStack {


    int* arr; // * array of elements, we will keep new elements in it
    int index; // *  where to put new elements --> beyshawer 3ala awel makan "faaady"
    int maxCapacity;

    public:
        AhmedStack(int capacity){ //* capacity is the array size
            arr = new int[capacity];
            index = 0;
            maxCapacity = capacity;
        }

        void push(int newElement){  //[0->cap-1]
            if(index>=maxCapacity){
                cout<<"Stack full\n";
                cout<<"Cannot add element "<<newElement<<"!\n";
            }else{
                arr[index] = newElement;
                index ++;
                cout<<"Element "<<newElement<<" is added!\n";
            }
        }

        int pop(){
            int popedElement = arr[index-1];
            index --;
            cout<<"Element "<<popedElement<<" is removed!\n";
            return popedElement;
        }

        int peek(){ 
            return arr[index-1];
        }

};

int main(){


    AhmedStack stack(5);

    stack.push(1000);
    stack.push(950);
    stack.push(6523);
    stack.push(761723123);
    stack.push(23234);

    cout<<"Last element in stack is"<<stack.peek()<<endl;
    stack.push(9219001); // * expected to fail
    
    stack.pop();
    stack.push(9219001); // * expected to succeed
    cout<<"Last element in stack became"<<stack.peek()<<endl;

}
