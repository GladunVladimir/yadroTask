#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include "Tape.h"
#include "Sort.h"


int main() {
   std::string inFile = "";
   std::string outFile = "";
   std::cout<<"Please enter the path to the input file: ";
   std::cin>>inFile;
   std::cout<<"Please enter the path to the output file: ";
   std::cin>>outFile;


   FileTape tape(inFile);
//   tape.saveFile(outFile);

   auto *res = dynamic_cast<FileTape *>(Sort::sort(&tape));


   for (int i = 0; i < res->getInputLength(); ++i) {
//       std::cout << res->readValue() << std::endl;
       res->moveForward();
   }

   delete res;

   return 0;
}
