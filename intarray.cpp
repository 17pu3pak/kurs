#include "intarray.hpp"
#define NULL 0

int abs(int inp){
  if(inp<0) return -inp;
  else return inp;
}

void operator+(int _element,IntArray& intarray){
        intarray.AddL(_element);
        return;
};

void operator+(IntArray& intarray,int _element){
        intarray.AddH(_element);
        return;
};

IntArray::IntArray(){
        head = new el;
        tail = new el;
        head->index = 1;
        head->element = 0;
        head->prev=NULL;
        head->next = tail;
        head->prev = NULL;
        tail->index = 1;
        tail->element = 0;
        tail->prev=head;
        tail->next=NULL;
        lowBound=1;
        highBound = 1;

};

IntArray::IntArray(int lb){
        head = new el;
        tail = new el;
        head->index = lb;
        head->prev = NULL;
        head->next= tail;
        head->element = 0;
        tail->index = lb;
        tail->element = 0;
        tail->prev=head;
        tail->next= NULL;
        lowBound=lb;
        highBound=lb;
};

IntArray::IntArray(IntArray& parray){
        struct el *tempel= new el;
        lowBound = parray.head->index;
        highBound= parray.tail->index;
        head = new el;
        tail = new el;
        head->index = parray.head->index;
        head->element = parray.head->element;
        head->prev = NULL;
        head->next= tail;
        tail->index = parray.head->index;
        tail->element = parray.head->element;
        tail->prev=head;
        tail->next= NULL;
        if((parray.head->index == parray.tail->index)&&
           (parray.head->element == parray.tail->element)) {
                delete tempel;
                return;
        }
        tempel = parray.head;

        while(tempel!= NULL) {

                struct el *tmp = new el;
                tmp->index = tempel->index;
                tmp->element = tempel->element;
                tmp->prev=tail;
                tail->next=tmp;
                tmp->next=NULL;
                tail=tmp;
                tempel = tempel->next;
        }
        delete tempel;

};

IntArray::IntArray(int lb,int cnt,int _element){
        head = new el;
        tail = new el;
        head->index = lb;
        head->element = _element;
        head->prev = NULL;
        head->next = tail;
        tail->index = lb;
        tail->element = 0;
        tail->prev=head;
        tail->next=NULL;
        lowBound = lb;
        highBound=lb+cnt-1;
        for(int i=1; i<cnt; i++) {
                struct el *tempel= new el;
                if(tail->index==head->index) {
                        tail->index=lb+abs(i);
                        tail->element = _element;
                }else{
                        tempel->prev = tail;
                        tempel->next = NULL;
                        tempel->index=lb+abs(i);
                        tempel->element=_element;
                        tail->next = tempel;
                        tail=tempel;
                }
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
        while(tempel->index != index) {
                if(tempel->next == NULL) {
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
        while(tempel->index != index) {
                if(tempel->next == NULL) {
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
        //if(index>highBound || index<lowBound) return error;
        while (tempel->index != index) {
                tempel=tempel->next;
        }
        return tempel->element;
};

void IntArray::AddH(int _element){
        struct el *tempel= new el;

        highBound+=1;
        if(tail->index==head->index) {
                tail->index=highBound;
                tail->element = _element;
        }else{
                tempel->prev = tail;
                tempel->next = NULL;
                tempel->index=highBound;
                tempel->element=_element;
                tail->next = tempel;
                tail=tempel;
        }
};

void IntArray::AddL(int _element){
        struct el *tempel = new el;
        lowBound-=1;
        if(tail->index==head->index) {
                head->index=lowBound;
                head->element = _element;
        }else{
                tempel->next = head;
                tempel->prev = NULL;
                tempel->index=lowBound;
                tempel->element=_element;
                head->prev = tempel;
                head=tempel;
        }
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
        struct el *tempel = new el;
        if(tail==head) {
                delete tail;
                delete head;
                return;
        }
        while(tail->prev !=NULL) {
                tempel = tail->prev;
                delete tail;
                tail=tempel;

        }
        delete tempel;
};
