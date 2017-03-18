class IntArray {
public:
IntArray();
IntArray(int lb);
IntArray(IntArray& parray);
IntArray(int lb,int cnt,int _element);
int Low();
int High();
int Size();
int Fetch(int index);
void Store(int index,int _element);
int& operator[](int index);
void AddH(int _element);
void AddL(int _element);
int RemH();
int RemL();
int operator--(int);
int operator--();
~IntArray();
//void showArrayInfo();
class ArrayEmpty {};
private:
struct el {
        int element;
        int index;
        el *prev,*next;
};
el *head,*tail;
int lowBound;
int highBound;
};

void operator+(IntArray& intarray,int _element);
void operator+(int _element,IntArray& intarray);
