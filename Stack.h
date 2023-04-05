#ifndef STACK
#define STACK
#include <memory>
#include <iostream>
#include <exception>

const bool debug{0};

template <typename T>
struct StackNodeT {
    T data;
    std::shared_ptr<StackNodeT<T>> link;    
};

template <typename T>
class StackT {
    size_t size;
    std::shared_ptr<StackNodeT<T>> stack;
    
    public:
        StackT();
        StackT(const T&);//copy constructor
        StackT(T&&) noexcept;//move copy constructor constructor
        T& operator=(T&&) noexcept;//move assignment operator

        void CopyNodes(const T&);

        ~StackT();
        T& operator=(const T&);//assignment operator//

        void Push(T);
        void Pop();
        T Top() const;

        size_t Size() const;
        bool IsEmpty() const;
};

//GEN_ERROR
class bad_stack_op : public std::exception {
    std::string errString;
    public:
        bad_stack_op(std::string);
        const char* what() const noexcept override;
};
bad_stack_op::bad_stack_op(std::string message) : errString("Bad Stack Op Error: " + message) {
}

const char* bad_stack_op::what() const noexcept {
  return errString.c_str();
}
//IMPLEMENTATION//////////////////////////
template <typename T>
void StackT<T>::CopyNodes(const T& rhs){
    std::shared_ptr<T> rhsCurrent(rhs.stack);
    std::shared_ptr<T> lhsCurrent(nullptr);
    if (debug){
        std::cout << "CopyNodes" << std::endl;
    }

    if (rhs.stack != nullptr){
        stack = std::make_shared<T>();
        stack->data = rhsCurrent->data;
        rhsCurrent = rhsCurrent->link;
        lhsCurrent = stack;
        while (rhsCurrent){
            lhsCurrent->link = std::make_shared<T>();
            lhsCurrent = lhsCurrent->link;
            lhsCurrent->data = rhsCurrent->data;
            rhsCurrent = rhsCurrent->link;
        }
        lhsCurrent->link = nullptr;
    }
}

template <typename T>
StackT<T>::StackT() : size(0), stack(nullptr){
    if (debug){
        std::cout << "In Constructor" << std::endl;
    }
} // constructor

template <typename T>
StackT<T>::StackT(const T &rhs) : size(rhs.Size()), stack(nullptr){ // copy constructor
    if (debug){
        std::cout << "In copy constructor" << std::endl;
    }
    CopyNodes(rhs);
}

template <typename T>
StackT<T>::StackT(T &&rhs) noexcept{ // move constructor
    if (debug){
        std::cout << "Move constructor called" << std::endl;
    }
    size = eTchange(rhs.size, 0);
    stack = eTchange(rhs.stack, nullptr);
}

template <typename T>
T &StackT<T>::operator=(T &&rhs) noexcept{ // move assignment operator
    if (debug){
        std::cout << "Called move assignment" << std::endl;
    }
    if (this != &rhs){
        size = eTchange(rhs.size, 0);
        stack = eTchange(rhs.stack, stack);
    }
    return *this;
}

template <typename T>
T &StackT<T>::operator=(const T &rhs){ // overload assignment operator
    if (this != &rhs){
        stack = nullptr;
        size = rhs.Size();
        CopyNodes(rhs);
    }
    return *this;//!
}

template <typename T>
StackT<T>::~StackT(){}

template <typename T>
void StackT<T>::Push(T newItem){
    std::shared_ptr newNode = std::make_shared<StackNodeT<T>>();

    newNode->data = newItem;
    newNode->link = stack;

    stack = newNode;
    size++;
}

template <typename T>
void StackT<T>::Pop(){//!
    if (IsEmpty()){
        throw(bad_stack_op("Pop attempted on emptystack."));
    }else{
        std::shared_ptr<StackNodeT<T>> temp(stack);
        stack = stack->link;
        size--;
    }
}

template <typename T>
T StackT<T>::Top() const{
    if (stack == nullptr){
        throw(bad_stack_op("Top attempted on empty stack."));
    }
    return stack->data;
}

template <typename T>
size_t StackT<T>::Size() const{
    return size;
}

template <typename T>
bool StackT<T>::IsEmpty() const{
    return (Size() == 0);
}

#endif