#include "stdafx.h"
template <typename T> T* CSingleton<T>::m_Instance = nullptr;

/*
template<typename T>
CSingleton<T>::CSingleton()
{
}

template<typename T>
CSingleton<T>::~CSingleton()
{
}*/


template <typename T>
T* CSingleton<T>::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new T();
	}
	
	if (m_Instance != nullptr)
	{
		return m_Instance;
	}

	return nullptr;
}


