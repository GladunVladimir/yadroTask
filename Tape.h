#ifndef YADROTASK_TAPE_H
#define YADROTASK_TAPE_H

#include <fstream>

class Tape {
public:
    virtual ~Tape() = default;
    virtual int readValue() = 0;
    virtual void writeValue(int value) = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual int getInputLength() = 0;
    virtual void setStartPos() = 0;
    virtual Tape *createTape() = 0;
};


class FileTape : public Tape {
    unsigned long long size;
    std::fstream FileStream;
    std::string tmpFile;
    std::string outFile;
    int readDelay = 0;
    int writeDelay = 0;
    int moveForwardDelay = 0;
    int moveBackwardDelay = 0;

    FileTape(std::string &outFilePath, int readDelay, int writeDelay, int moveForwardDelay, int moveBackwardDelay);

public:
    FileTape(const std::string FilePath);
    ~FileTape(){};
    int readValue() override;
    void writeValue(int value) override;
    void moveForward() override;
    void moveBackward() override;
    int getInputLength() override;
    void saveFile(const std::string outFilePath);
    void setStartPos() override;
    Tape *createTape() override;
};

#endif //YADROTASK_TAPE_H