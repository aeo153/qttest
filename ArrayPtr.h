/********************************************************
File name:   ArrayPtr.h
Author:      tands
Version:     1.0
Date:        2018/01/10
Description: 在生命周期结束时，自动销毁所指的数组(该数组是new出来的数组)
History: 
*******************************************************/

#ifndef ARRAYPTR_H
#define ARRAYPTR_H

template<class T>
class ArrayPtr
{
public:
	explicit ArrayPtr(T * arrayPtr = nullptr) { m_arrayPtr = arrayPtr; }
	explicit ArrayPtr(unsigned int arrSize)
	{
		m_arrayPtr = nullptr;
		if ( arrSize > 0 )
		{
			m_arrayPtr = new T[arrSize];
		}
	}

	~ArrayPtr() { DestroyPtr(); }

	T * GetPointer() { return m_arrayPtr; }

	void ResetArray(T * arrayPtr)
	{
		if ( m_arrayPtr )
		{
			DestroyPtr();
		}

		m_arrayPtr = arrayPtr;
	}

	void DestroyPtr()
	{
		if ( m_arrayPtr )
		{
			delete[] m_arrayPtr;
			m_arrayPtr = nullptr;
		}
	}

private:
	T * m_arrayPtr = nullptr;
};

#endif
