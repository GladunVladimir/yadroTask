#include <thread>
#include <sys/stat.h>
#include <iostream>
#include <unistd.h>
#include "config.h"
#include "Tape.h"


int FileTape::readValue() {
    int value = 0;
    FileStream.read(reinterpret_cast<char *>(&value), sizeof(int));
    FileStream.seekg(-sizeof(int), std::ios::cur);
    sleep(readDelay);
    return value;
}

void FileTape::writeValue(int value) {
    FileStream.write(reinterpret_cast<char *>(&value), sizeof(int));
    FileStream.seekg(-sizeof(int), std::ios::cur);
    sleep(writeDelay);
}

void FileTape::moveForward() {
    FileStream.seekg(sizeof(int), std::ios::cur);
    sleep(moveForwardDelay);
}

void FileTape::moveBackward() {
    FileStream.seekg(-sizeof(int), std::ios::cur);
    sleep(moveBackwardDelay);

}

int FileTape::getInputLength() {
    return size;
}

void FileTape::setStartPos() {
    FileStream.seekg(0, std::ios::beg);
}

FileTape::FileTape(const std::string FilePath) {

    FileStream.open(FilePath, std::ios::in);
    FileStream.seekg(0, std::ios::end);
    size = FileStream.tellg() / sizeof(int);
    FileStream.seekg(0, std::ios::beg);
}

FileTape::FileTape(std::string &outFilePath, int readDelay, int writeDelay, int moveForwardDelay, int moveBackwardDelay) {
    std::ofstream outfile(outFilePath);
    outfile.close();

    FileStream.open(outFilePath, std::ios::in | std::ios::out | std::ios::binary);

    FileStream.seekg(0, std::ios::end);
    if (FileStream.tellg() != -1)
        size = FileStream.tellg() / sizeof(int);
    else
        size = 0;
    FileStream.seekg(0, std::ios::beg);


    this->readDelay = READ_DELAY;
    this->writeDelay = WRITE_DELAY;
    this->moveForwardDelay = MOVE_FORWARD_DELAY;
    this->moveBackwardDelay = MOVE_BACKWARD_DELAY;
    this->outFile = outFile;
}



void FileTape::saveFile(const std::string outFilePath) {
    std::ofstream outfile(outFilePath);
    outfile.close();
    std::fstream f(outFilePath, std::ios::in | std::ios::out | std::ios::binary);

    f.open(outFilePath, std::ios::in | std::ios::out | std::ios::binary);
    if (!f) {
        std::cerr << "Failed to open the file for writing" << std::endl;
        return;
    }
    FileStream.seekg(0, std::ios::beg);

    for (int i = 0; i < size; ++i) {
        int value = this->readValue();
        outfile.write(reinterpret_cast<const char *>(&value), sizeof(value));
        this->moveForward();
    }
    f.close();
}

Tape *FileTape::createTape() {
    Tape *ptr = new FileTape(outFile, readDelay, writeDelay, moveForwardDelay, moveBackwardDelay);
    return ptr;
}
