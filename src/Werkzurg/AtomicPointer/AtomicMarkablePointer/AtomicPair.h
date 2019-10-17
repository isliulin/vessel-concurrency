#ifndef ATOMIC_PAIR_H 
#define ATOMIC_PAIR_H 
#include <iostream> 
#include <atomic> 

/**
 * AtomicPair: ԭ���Եļ�ֵ��
 * note: ������������ױ���ԭ���ԣ�����AtomicPair�д���data��version����ֵ�������Ҫ��֤����ֵ�Ĳ��ɱ��ԣ���AtomicStampPointer�б���һ��AtomicPair��ָ�룬�Ӷ�ת��Ϊ��������AtomicPair����ָ�룩��ԭ�������� 
 */
template<typename T>
class AtomicPair
{
	public:
	static AtomicPair<T> *factory(T* _data, bool _flag);
	~AtomicPair();
		
	const T *data;                // ָ������ָ�룬AtomicPair������ö�����������ڹ��� 
	const bool flag;              // �����޸ı�־ 
	
	private:
	AtomicPair(T* _data, bool _flag); 
};

/**
 * factory: ������̬����������һ��AtomicPair���������������ָ�� 
 */
template<typename T>
AtomicPair<T> *AtomicPair<T>::factory(T* _data, bool _flag)
{
	return new AtomicPair<T>(_data, _flag);
} 
 
/**
 * AtomicPair: ˽�й��캯�� 
 */
template<typename T>
AtomicPair<T>::AtomicPair(T* _data, bool _flag):data(_data), flag(_flag)
{
}

/**
 * AtomicPair: �������� 
 * note: AtomicStampPointer�����������������ͷ� 
 */ 
template<typename T>
AtomicPair<T>::~AtomicPair()
{
	//std::cout<<"����\n";
}

#endif