//����ָ��

///////////////////////////////////////////////////////////
//1.ԭ��RAII��Resource Acquisition Is Initialization��
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}

private:
	T* _ptr;
};

void MerageSort(int* a, int n)
{
	int * tmp = (int*)malloc(sizeof(int)*n);
	
	//tmpָ��ί�и���sp����
	SmartPtr<int> sp(tmp);

	//���������߼�
	......
}
int main()
{
	try {
		int a[5] = { 4,5,6,7,2 };
		MerageSort(a,5);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////
//2.1����ָ�룺std::auto_ptr
#include <memory> //C++����ָ�붼������memory��

class Date 
{
public:
	Date() { cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};

int main()
{
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);

	//ʹ��auto_ptr�󣬵����󿽱���ֵ��ԭ�еĶ�������
	//auto_ptr��C+++98�й涨�ģ�ȱ�ݺܴ���˲�����ʹ��

	ap->_year = 2018;//���к󣬱����������쳣: д�����Ȩ�޳�ͻ��ap._Myptr �� nullptr����
	
	system("pause");
	return 0;
}

//2.2 auto_ptrģ��ʵ��
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	//������������ap����Դת�Ƶ���ǰ���󣬲���ap������������Դ�Ͽ���ϵ
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap.ptr)
	{
		ap._ptr = nullptr;
	}

	//��ֵ����
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		//����Լ����Լ���ֵ
		if (this != &ap)
		{
			//�ͷŵ�ǰ��������Դ
			if (_ptr)
			{
				delete _ptr;

				//��ap����Դת�뵱ǰ������
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

int main()
{
	auto_ptr<Date> ap(new Date);

	//������ap���󸳿�
	auto_ptr<Date> copy(ap);
	ap->_year = 2018;//�����������쳣: д�����Ȩ�޳�ͻ��ap._Myptr �� nullptr����

	system("pause");
	return 0;
}

//3.1 ����ָ�룺std::unique_ptr
int main()
{
	unique_ptr<Date> ap(new Date);

	//�򵥴ֱ���Ϊ�˷�ֹ�����ͷ�����
	unique_ptr<Date> copy(ap);//��������ɾ���ĺ���
}

//3.2 unique_ptrģ��ʵ��
template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~UniquePtr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	//C++98��������ʽ��ֻ������ʵ��+����Ϊ˽��
	UniquePtr(Uniqueptr<T> const &);
	UniquePtr & operator=(UniquePtr<T> const &);

	//C++11��������ʽ��delete
	UniquePtr(Uniqueptr<T> const &) = delete;
	UniquePtr & operator=(UniquePtr<T> const &) = delete;

private:
	T* _ptr;
};

//4.1 ����ָ�룺 std::shared_ptr
int main()
{
	//shared_ptrͨ�����ü�����֧��ָ�����Ŀ���
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);

	cout << "ref count: " << sp.use_count() << endl;//ref count: 2
	cout << "ref count: " << copy.use_count() << endl;//ref count: 2

	system("pause");
	return 0;
}

//4.2 shared_ptrģ��ʵ��
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{
		//�����һ����ָ����������ü�����0
		if (_ptr == nullptr)
			_pRefCount = 0;
	}

	~SharedPtr()
	{
		Release();
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		//�����һ����ָ������򲻼����ü�������������ü���
		if (_ptr)
			AddRefCount();
	}

	//sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//�ͷŹ���ľ���Դ
			Release();

			//��������¶������Դ�����������ü���
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			if (_ptr)
				AddRefCount();
		}

		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	int UseCount()
	{
		return *_pRefCount;
	}

	T* Get()
	{
		return _ptr;
	}

	int AddRefCount()
	{
		//������ʹ�ü�1��ԭ�Ӳ���
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();

		return *_pRefCount;
	}

	int SubRefCount()
	{
		//������ʹ�ü�1��ԭ�Ӳ���
		_pMutex->lock();
		--(*_pRefCount);
		_pMutex->unlock();

		return *_pRefCount;
	}

private:
	void Release()
	{
		//���ü�����1����Ϊ0�����ͷ���Դ
		if (_ptr && SubRefCount() == 0)
		{
			delete _ptr;
			delete _pRefCount;
		}
	}
private:
	int* _pRefCount;//���ü���
	T* _ptr;//ָ�������Դ��ָ��
	mutex* _pMutex;//������
};


int main()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;

	cout << sp1.UseCount() << endl;//2
	cout << sp2.UseCount() << endl;//2

	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;//1
	cout << sp2.UseCount() << endl;//2
	cout << sp3.UseCount() << endl;//2

	sp1 = sp3;
	cout << sp1.UseCount() << endl;//2
	cout << sp2.UseCount() << endl;//3
	cout << sp3.UseCount() << endl;//3

	system("pause");
	return 0;
}

//4.3 std::shared_ptr���̰߳�ȫ����
void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	cout << sp.Get() << endl;

	//��ʾ���ü����̰߳�ȫ���⣬�Ͱ�AddRefCount��SubRefCount�е���ȥ��
	//��ʾ���ܲ������̰߳�ȫ���⣬��Ϊ�̰߳�ȫ������ż�������⣬main������n�Ĵ�һЩ���ʾͱ���ˣ���
	//���׳�����
	for (size_t i = 0; i < n; ++i)
	{
		//����ָ�뿽����++����������ָ��������--�������������̰߳�ȫ��
		SharedPtr<Date> copy(sp);

		//������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ�������
		//�տ����Ľ������һ���Ǽ���2n
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;

	const size_t n = 100;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);

	t1.join();
	t2.join();

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;

	system("pause");
	return 0;
}

//4.4 std::shared_ptrѭ������
struct ListNode
{
	int _data;
	SharedPtr<ListNode> _prev;
	SharedPtr<ListNode> _next;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int main()
{
	SharedPtr<ListNode> node1(new ListNode);
	SharedPtr<ListNode> node2(new ListNode);

	cout << node1.UseCount() << endl;//1
	cout << node2.UseCount() << endl;//1

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.UseCount() << endl;//2
	cout << node2.UseCount() << endl;//2

	system("pause");
	return 0;
}

//1. node1��node2��������ָ�����ָ�������ڵ㣬���ü������1�����ǲ���Ҫ�ֶ�delete��
//2. node1��_nextָ��node2��node2��_prevָ��node1�����ü������2��
//3. node1��node2���������ü�������1������_next��ָ����һ���ڵ㡣����_prev��ָ����һ���ڵ㡣
//4. Ҳ����˵_next�����ˣ�node2���ͷ��ˡ�
//5. Ҳ����˵_prev�����ˣ�node1���ͷ��ˡ�
//6. ����_next����node�ĳ�Ա��node1�ͷ��ˣ�_next�Ż���������node1��_prev����_prev����node2��Ա��������ͽ�ѭ�����ã�˭Ҳ�����ͷš�

// ��������������ü����ĳ����£��ѽڵ��е�_prev��_next�ĳ�weak_ptr�Ϳ�����
// ԭ����ǣ�node1->_next = node2;��node2->_prev = node1;��ʱweak_ptr��_next��_prev��������node1��node2�����ü�����
struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);

	cout << node1.use_count() << endl;//1
	cout << node2.use_count() << endl;//1

	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;//1
	cout << node2.use_count() << endl;//1

	system("pause");
	return 0;
}