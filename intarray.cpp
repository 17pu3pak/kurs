#include "intarray.hpp"
#include <iostream>
#include "stdio.h"

  IntArray::IntArray(){
      head = new el;
    head->index = 1;
    head->element = 0;
    head->prev = NULL;
    head->next = NULL;
    tail =head;
    lowBound=1;
    highBound = 1;

  };
  IntArray::IntArray(int lb){
    head = new el;
    head->index = lb;
    head->prev = NULL;
    head->next= tail;
    head->element = 0;
    tail =head;
    tail->prev=head;
    tail->next= NULL;
    lowBound=lb;
    highBound=lb;
  };


  IntArray::IntArray(IntArray& parray){
      struct el *tempel= new el;
      lowBound = parray.head->index;
      highBound= parray.tail->index;
    head = parray.head;
    tempel = head;
    if(parray.head == parray.tail) {
      tail=head;
      return;
    }
    while(tempel->next != NULL){
      tail=tempel;
      tempel = tail->next;
    }
    tail = tempel;

  };

  IntArray::IntArray(int lb,int cnt,int _element){
    head = new el;
    head->index = lb;
    head->element = _element;
    head->prev = NULL;
    head->next = NULL;
    tail=head;
    lowBound = lb;
    highBound=lb+cnt-1;
    for(int i=1;i<cnt;i++){
      struct el *tempel= new el;
      tempel->index = lb+i;
      tempel->element=_element;
      tempel->prev = tail;
      if(tail == head) head->next = tempel;
      tail->next = tempel;
      tail=tempel;
    }
    tail->next = NULL;
  };
  int IntArray::Low(){
    return lowBound;
  };
  int IntArray::High(){
    return highBound;
  };
  int IntArray::Size(){
    if((highBound*lowBound) >=0) return ((highBound-lowBound)+1);
    return abs(lowBound)+abs(highBound)+1;
  };
  int IntArray::Fetch(int index){
    struct el *tempel;
    tempel = head;
    while(tempel->index != index){
      if(tempel->next == NULL){
        return tempel->element;
       }
       else {
         tempel=tempel->next;
       }
    }
    return tempel->element;
  };
  void IntArray::Store(int index,int _element) {
    struct el *tempel;
    tempel = head;
    while(tempel->index != index){
      if(tempel->next == NULL){
        tempel->element=_element;
      }
      else{
      tempel=tempel->next;
    }
    }
    tempel->element= _element;
  };

  int& IntArray::operator[](int index){
    struct el *tempel;
    tempel = head;
    while (tempel->index != index){
      tempel=tempel->next;
    }
    return tempel->element;
  };
void IntArray::AddH(int _element){
    struct el *tempel= new el;

    highBound+=1;
    tempel->prev = tail;
    tempel->next = NULL;
    tempel->index=highBound;
    tempel->element=_element;
    tail->next = tempel;
    tail=tempel;
  };
  void IntArray::AddL(int _element){
    struct el *tempel = new el;
    lowBound-=1;
    tempel->next = head;
    tempel->prev = NULL;
    tempel->index=lowBound;
    tempel->element=_element;
    head->prev = tempel;
    head=tempel;
  };
  int IntArray::RemH(){
    struct el *tempel;
    highBound-=1;
    if(highBound<=lowBound) return 0;
    tempel= tail;
    tail=tempel->prev;
    return tempel->element;

  };
  int IntArray::RemL(){
    struct el *tempel;
    lowBound+=1;
    if(lowBound>=highBound) return 0;
    tempel= head;
    head=tempel->next;
    return tempel->element;
  };
  int IntArray::operator--(int){
    return RemH();
  };
  int IntArray::operator--(){
    return RemL();
  };
  IntArray::~IntArray(){
    std::cout << "Destruction" << std::endl;
    struct el *tempel;
    if(tail==head){
      delete tail;
      return;
    }
    while(tail->prev !=NULL){
      tempel = tail->prev;
    delete tail;
    tail=tempel;
  }

  };
void operator+(int _element,IntArray& intarray){
    intarray.AddL(_element);
    return;
  };
void operator+(IntArray& intarray,int _element){
    intarray.AddH(_element);
    return;
  };
