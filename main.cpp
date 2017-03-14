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
  std::cout <<"a. High = "<< a.High() << std::endl;
  std::cout <<"a. Low = "<< a.Low() << std::endl;
  std::cout <<"a. size = "<< a.Size() << std::endl;
  std::cout <<"a. Fetch 2 = "<< a.Fetch(2) << std::endl;
  a.Store(2,50);
  std::cout <<"a. Store 10 = "<< a.Fetch(10) << std::endl;
   std::cout <<"a. --a = "<< --a << std::endl;
  std::cout <<"a. High = "<< a.High() << std::endl;
  std::cout <<"a. Low = "<< a.Low() << std::endl;
  std::cout <<"a. size = "<< a.Size() << std::endl;
  IntArray c(a); // TODO: фикс деструктора
  IntArray d(-3, 3, 10);

  //b+123;
/*
dsdsf
//TODO: a+123;
 std::cout <<"a. Store 2 = "<< a.Fetch(2) << std::endl;

 std::cout <<"a. RemH = "<< a.RemH() << std::endl;
 std::cout <<"a. RemL = "<< a.RemL() << std::endl;*/
 std::cout <<"b. High = "<< b.High() << std::endl;
 std::cout <<"b. Low = "<< b.Low() << std::endl;
 std::cout <<"b. size = "<< b.Size() << std::endl;
 //std::cout <<"c. High = "<< c.High() << std::endl;
 //std::cout <<"c. Low = "<< c.Low() << std::endl;
//std::cout <<"c. size = "<< c.Size() << std::endl;
 std::cout <<"d. High = "<< d.High() << std::endl;
 std::cout <<"d. Low = "<< d.Low() << std::endl;
 std::cout <<"d. size = "<< d.Size() << std::endl;
  return 0;
}
