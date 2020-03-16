//STL���νṹ�Ĺ���ʽ����

/////////////////////////////////////////////////////////////////////
//1. ��ֵ�ԵĶ���
template<class T1, class T2>
class pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair()
		:first(T1())
		, second(T2())
	{}

	pair(const T1& a, const T2& b)
		��first(a)
		, second(b)
	{}

};

/////////////////////////////////////////////////////////////////////
//2. ����ʽ������map

//2.1 map�Ĺ���
int main()
{
	map<string, string> m1;

	map<string, string> m2{ {"apple","ƻ��"},
							{"banan", "�㽶"},
							{"orange", "����"},
							{"peach", "����" },
							{"waterme", "ˮ����"} };

	cout << m2["apple"] << endl;
	cout << m2["waterme"] << endl;
	map<string, string> m3(m2);

	system("pause");
	return 0;
}

//2.2 map��������Ԫ�ط���
//operator[]��at()����������ͨ��key�ҵ���key��Ӧ��valueȻ�󷵻������ã���ͬ���ǣ���key������ʱ��
//operator[]��Ĭ��value��key�����ֵ��Ȼ����룬���ظ�Ĭ��value��at()����ֱ�����쳣

 /*
 operator[]��ԭ���ǣ�
 ��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��
 ���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
 ���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����
 operator[]�������insert����ֵ��ֵ���е�value����
 */
int main()
{
	map<string, string> m;

	//��<"apple", ""> ����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý��
	m["apple"] = "ƻ��";
	// ��<"apple", "">����map�У�����ʧ�ܣ���<"apple", "ƻ��">�е�"ƻ��"����

	cout << m["apple"] << endl;//ƻ��
	cout << m.size() << endl;//1

	system("pause");
	return 0;
}

//2.3  map��Ԫ�ص��޸�
int main()
{
	map<string, string> m;

	//�ټ�ֵ��<"peach","����">����map�У���pair�����ֵ��
	m.insert(pair<string, string>("peach", "����"));

	//�ڼ�ֵ��<"banan", "�㽶">����map�У���make_pair�����ֵ��
	m.insert(make_pair("banan", "�㽶"));

	//����operator[]��map�в���Ԫ��
	m["apple"] = "ƻ��";

	//��key������ʱ���쳣
	//m.at("waterme") = "ˮ����"
	m.insert(m.find("waterme"), make_pair("waterme", "ˮ����"));
	cout << m.size() << endl;//4

	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
		cout << endl;
	}

	//map�еļ�ֵ��key��Ψһ�ģ���key�����򽫲���ʧ��
	auto ret = m.insert(make_pair("peach", "����"));
	if (ret.second)
	{
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	}
	else
	{
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" <<
			ret.first->second << " ����ʧ��" << endl;
	}

	//ɾ��keyΪ"apple"��Ԫ��
	m.erase("apple");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;

	if (1 == m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple������" << endl;

	system("pause");
	return 0;
}

//1. map�еĵ�Ԫ���Ǽ�ֵ��
//2. map�е�key��Ψһ�ģ����Ҳ����޸�
//3. Ĭ�ϰ���С�ڵķ�ʽ��key���бȽ�
//4. map�е�Ԫ������õ�����ȥ���������Եõ�һ�����������
//5. map�ĵײ�Ϊƽ��������(�����)������Ч�ʱȽϸ�O(log_2 N)
//6. ֧��[]��������operator[]��ʵ�ʽ��в�����ҡ�

/////////////////////////////////////////////////////////////////////
//3. ����ʽ������multimap
int main()
{
	multimap<string, string> m;

	m.insert(make_pair("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("³��", "������"));

	//����key��ͬ��Ԫ��
	m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;//4

	for (auto& e : m)
		cout << "<" << e.first << "," << e.second << ">" << endl;

	//keyΪ���ӵ�Ԫ���ж��ٸ�
	cout << m.count("����") << endl;//2

	multimap<int, int> m1;
	for (int i = 0; i < 10; ++i)
		m1.insert(pair<int, int>(i, i));

	auto it = m1.lower_bound(5);
	cout << it->first << "--->" << it->second << endl;//5--->5

	// ����m�д���5��Ԫ��
	it = m1.upper_bound(5);
	cout << it->first << "--->" << it->second << endl;//6--->6


	system("pause");
	return 0;
}

/////////////////////////////////////////////////////////////////////
//4 ����ʽ������set
int main()
{
	//�������е�Ԫ�ع���set
	int array[] = { 1,3,6,5,3,4,5,7,8,9,4,3,7,0 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;//9

	//�����ӡset�е�Ԫ�أ����Կ���set����ȥ��
	for (auto& e : s)
	{
		cout << e << ' ';// 0 1 3 4 5 6 7 8 9
	}
	cout << endl;

	//ʹ�õ����������ӡset�е�Ԫ��
	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << ' ';//9 8 7 6 5 4 3 1 0
	}
	cout << endl;

	//set��ֵΪ3��Ԫ�س��ֵĴ�����ʱ�临�Ӷ�O(logN)��
	cout << s.count(3) << endl;//1

	system("pause");
	return 0;
}

/////////////////////////////////////////////////////////////////////
//5 ����ʽ������multiset
int main()
{
	int array[] = { 2,1,3,4,6,5,4,7,8,9,0,7,6,5 };

	//multiset�ڵײ�洢����<int, int>�ļ�ֵ��
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)
	{
		cout << e << ' ';// 0 1 2 3 4 4 5 5 6 6 7 7 8 9
	}
	cout << endl;

	s.insert(5);
	cout << s.count(5) << endl;//3
	for (auto& e : s)
	{
		cout << e << ' ';// 0 1 2 3 4 4 5 5 5 6 6 7 7 8 9
	}
	cout << endl;

	s.erase(5);
	for (auto& e : s)
	{
		cout << e << ' ';// 0 1 2 3 4 4 6 6 7 7 8 9
	}
	cout << endl;


	system("pause");
	return 0;
}