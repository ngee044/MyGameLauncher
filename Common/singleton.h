#pragma once

#define SINGLETON_S(class_name)															\
friend class SSingleton<class_name>;													\
public:																					\
	static class_name* GetInstance() { return SSingleton<class_name>::GetInstance(); }

#define SINGLETON_D(class_name)															\
friend class DSingleton<class_name>;													\
public:																					\
	static class_name* GetInstance() { return DSingleton<class_name>::GetInstance(); }	\
	static void DestroyInstance() { DSingleton<class_name>::DestroyInstance(); }	

template<typename T>
class SSingleton	//Static Singleton
{
public:
	static T* GetInstance();

private:
	SSingleton();
	virtual ~SSingleton();
	SSingleton(const SSingleton&) = delete;
	const SSingleton& operator = (const SSingleton&) = delete;
};

template<typename T>
class DSingleton	//Dynamic Singleton
{
public:
	static T* GetInstance();
	static void DestroyInstance();

private:
	DSingleton();
	virtual ~DSingleton();
	DSingleton(const DSingleton&) = delete;
	const DSingleton& operator = (const DSingleton&) = delete;

private:
	static T* instance_;
};
template<typename T>
T* DSingleton<T>::instance_ = nullptr;

template<typename T>
T* SSingleton<T>::GetInstance()
{
	static T instance;
	return &instance;
}

template<typename T>
T* DSingleton<T>::GetInstance()
{
	if (nullptr == instance_)
	{
		instance_ = new T();
	}
	return instance_;
}

template<typename T>
void DSingleton<T>::DestroyInstance()
{
	if (instance_)
	{
		delete instance_;
		instance_ = nullptr;
	}
}

template <typename T>
class InSingleton //Inheritance Singleton
{
protected:
	static T* m_instance_;

public:
	InSingleton()
	{
	}
	virtual ~InSingleton()
	{
	}

	static T* Instance()
	{
		if (m_instance_ == 0)
		{
			m_instance_ = new T;
		}

		return m_instance_;
	}

	static void Destroy()
	{
		if (m_instance_ != 0)
		{
			delete m_instance_;
			m_instance_ = 0;
		}
	}
};

template <typename T>T* InSingleton <T>::m_instance_ = 0;
