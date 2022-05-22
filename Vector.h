#define _USE_CRT_SECURE_NO_WARNINGS_
#pragma once
#include <iostream>
using namespace std;
template<class T>
class TVector
{
protected:

    T* data;
    int len;

public:

    TVector();
    TVector(int n = 0);
    TVector(const TVector& p);
    ~TVector();

    int GetLen() const;

    T& operator[](int i);
    TVector& operator= (const TVector& p);
    TVector operator+ (const TVector& p);
    TVector operator- (const TVector& p);
    TVector operator/ (const TVector& p);
    T operator*(const TVector& v);
    TVector operator * (const T n);
    bool operator == (const TVector& p);

    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.len; i++)
        {
            in >> v.data[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const TVector& p)
    {
        for (int i = 0; i < p.len; i++)
            out << p.data[i] << ' ';
        return out;
    }

};

template<class T>
TVector<T>::TVector()
{
    len = 0;
    data = NULL;
}

template<class T>
TVector<T>::TVector(int n)
{
    data = new T[n];
    len = n;
    for (int i = 0; i < n; i++)
        data[i] = 0;
    if (n > 0)
    {
        data = new T[n];
        len = n;
        for (int i = 0; i < n; i++)
            data[i] = 0;
    }
    else
    {
        cout << "length <= 0" << endl;
    }
}

template<class T>
TVector<T>::TVector(const TVector& p)
{
    len = p.len;
    data = new T[p.len];
    for (int i = 0; i < p.len; i++)
        data[i] = p.data[i];
}

template<class T>
TVector<T>::~TVector()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
}

template<class T>
inline int TVector<T>::GetLen() const
{
    return len;
}

template<class T>
T& TVector<T>::operator[](int i)
{
    if (i >= 0 && i < len)
    {
        return data[i];
    }
    else
    {
        cout << "ОШИБКА";
    }
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector& p)
{
    if (this == &p)
        return *this;
    else
    {
        delete[] data;
        data = new T[p.len];
        len = p.len;
        data = new T[p.len];
        for (int i = 0; i < len; i++)
            data[i] = p.data[i];
    }
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector& p)
{
    if (this->len != p.len) {
        cout << "ОШИБКА" << endl;
    }

    else {
        TVector<T> res(*this);
        for (int q = 0; q < len; q++)
        {
            res.data[q] = (this->data[q]) + p.data[q];
        }

        return res;
    }
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector& p)
{
    if (this->len != p.len) {
        cout << "sizes don't match" << endl;

    }
    else {
        TVector<T> res(*this);
        for (int q = 0; q < len; q++)
        {
            res.data[q] = (this->data[q]) - p.data[q];
        }
        return res;
    }
}

template<class T>
TVector<T> TVector<T>::operator/(const TVector& p)
{
    if (this->len != p.len) {
        cout << "sizes don't match" << endl;

    }
    else {
        TVector<T> res(*this);
        for (int q = 0; q < len; q++)
        {
            res.data[q] = (this->data[q]) / p.data[q];
        }
        return res;
    }
}

template<class T>
T TVector<T>::operator*(const TVector& v)
{
    if (len != v.GetLen()) {
        cout << "different sizes";
    }
    T result = 0;

    for (int i = 0; i < len; i++) {
        result += (this->data[i]) * v.data[i];
    }
    return result;
}

template<class T>
TVector<T> TVector<T>::operator*(const T n)
{
    TVector<T> res(len);

    for (int i = 0; i < len; i++)
        res[i] = data[i] * n;

    return res;
}

template<class T>
bool TVector<T>::operator==(const TVector& p)
{
    if (len != p.len)
        return false;
    for (int i = 0; i < len; i++)
        if (data[i] != p.data[i])
            return false;
    return true;
}