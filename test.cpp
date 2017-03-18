#include "intarray.hpp"
#include <iostream>


int main(){
        IntArray a;
        int i = 10;
        a[1]=1;
        std::cout<<"A[1] =1" << std::endl;

        i=25+a[1];
        a.AddH(11);
        std::cout<<"A[2] =11 (AddH(11))" << std::endl;
        a.AddL(i);
        std::cout<<"A[0] =26 (AddL(26))" << std::endl;
        std::cout <<"i= 25+ a[1] "<< i << std::endl;

        std::cout <<"a. Fetch 2 = "<< a.Fetch(2) << std::endl;
        a.Store(2,50);
        std::cout<<"A[2] =50 (Stote(2,50))" << std::endl;
        std::cout <<"a. Store 10 = "<< a.Fetch(10) << std::endl;
        std::cout <<"a. --a = "<< --a << std::endl;
        std::cout <<"a. a-- = "<< a-- << std::endl;
        std::cout <<"a. High = "<< a.High() << std::endl;
        std::cout <<"a. Low = "<< a.Low() << std::endl;
        std::cout <<"a. size = "<< a.Size() << std::endl;
        std::cout <<"a. Fetch 1 = "<< a.Fetch(1) << std::endl;

        a+121;
          std::cout <<"a+121 "<< std::endl;

        a+13;
        a+100;
          std::cout <<"a. Fetch 2 = "<< a.Fetch(2) << std::endl;
            std::cout <<"a. Fetch 3 = "<< a.Fetch(3) << std::endl;
        std::cout <<"a. High = "<< a.High() << std::endl;
        std::cout <<"a. Low = "<< a.Low() << std::endl;
        std::cout <<"a. size = "<< a.Size() << std::endl;
        std::cout <<"a. --a = "<< --a << std::endl;
        std::cout <<"a. --a = "<< --a << std::endl;
        std::cout <<"a. --a = "<< --a << std::endl;
        std::cout <<"a. High = "<< a.High() << std::endl;
        std::cout <<"a. Low = "<< a.Low() << std::endl;
        std::cout <<"a. size = "<< a.Size() << std::endl;
        std::cout <<"a. Fetch 3 = "<< a.Fetch(3) << std::endl;
        IntArray c(a);
        c+111;
        122+c;
        std::cout <<"c. High = "<< c.High() << std::endl;
        std::cout <<"c. Low = "<< c.Low() << std::endl;
        std::cout <<"c. size = "<< c.Size() << std::endl;
        std::cout <<"c. Fetch 3 = "<< c.Fetch(3) << std::endl;
        std::cout <<"c. Fetch 4 = "<< c.Fetch(4) << std::endl;
        std::cout <<"c. Fetch 5 = "<< c.Fetch(5) << std::endl;

        return 0;
}
