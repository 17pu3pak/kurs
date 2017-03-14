#include "intarray.hpp"
#include <iostream>


int main(){
  IntArray a;
  IntArray b(-1);
  int i = 10;
    a[1]=1;
    i=25+a[1];
    a.AddH(11);
    a.AddL(i);
    std::cout <<"i= 25+ a[1] "<< i << std::endl;

   std::cout <<"a. Fetch 2 = "<< a.Fetch(2) << std::endl;
  a.Store(2,50);
  std::cout <<"a. Store 10 = "<< a.Fetch(10) << std::endl;
   std::cout <<"a. --a = "<< --a << std::endl;
      std::cout <<"a. a-- = "<< a-- << std::endl;

  std::cout <<"a. High = "<< a.High() << std::endl;
  std::cout <<"a. Low = "<< a.Low() << std::endl;
  std::cout <<"a. size = "<< a.Size() << std::endl;
  IntArray d(-3, 3, 10);

     a+123;
     a+11;
     std::cout <<"a. High = "<< a.High() << std::endl;
     std::cout <<"a. Low = "<< a.Low() << std::endl;
     std::cout <<"a. size = "<< a.Size() << std::endl;
     IntArray c(a);
     c+111;

  return 0;
}
