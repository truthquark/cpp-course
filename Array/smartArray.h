#ifndef SMARTARRAY_H_INCLUDED
#define SMARTARRAY_H_INCLUDED

class CSmartArray
{
private:
    int *pData;

    unsigned int nSize;
    unsigned int nReserve;

    CSmartArray() {};

    void clr();

public:
    CSmartArray(const unsigned int _nSize);
    CSmartArray (const CSmartArray& _copy);

    unsigned int getSize() const {return nSize;}
    int& operator[](const unsigned int _n);

    CSmartArray& operator=(const CSmartArray &_copy);
    void resize(const unsigned int _n);

    unsigned int add(const unsigned int _idx, const int _n);
    unsigned int remove(const unsigned int _idx);


    ~CSmartArray();
};


#endif // SMARTARRAY_H_INCLUDED
