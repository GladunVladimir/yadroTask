#include "Sort.h"
#include <iostream>

#define PIECE_OF_DATA 10


Tape *Sort::sort(Tape *t) {
    t->setStartPos();
    std::cout<<t->getInputLength()<<std::endl;
    int num_tapes = t->getInputLength() / PIECE_OF_DATA;

    std::vector<Tape *> tapes;
    std::vector<int> num_in_tape;
    for (int i = 0; i < num_tapes; ++i) {
        Tape *tape = t->createTape();
        std::vector<int> num_in_tape;
        for (int j = 0; j < PIECE_OF_DATA; ++j) {
            int v = t->readValue();
            num_in_tape.push_back(v);
            std::cout<<v<<std::endl;
            tape->writeValue(v);
            t->moveForward();
            tape->moveForward();
        }
        tape->setStartPos();
        tapes.push_back(tape);
    }

    std::sort(num_in_tape.begin(), num_in_tape.end());

    for (int el:num_in_tape){
        std::cout<<el<<std::endl;
    }



    t->setStartPos();
    tapes[0]->setStartPos();



    t->setStartPos();
    tapes[0]->setStartPos();

//    auto res = merge_sort(tapes);
    auto res = tapes[0];
    return res;
}
