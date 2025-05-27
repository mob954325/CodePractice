#include <iostream>
#include <new>      // std::nothrow
#include <cstddef>  // std::size_t
#include <cassert>

class MyClass
{
public:
	MyClass(int a, int b, const char* n) : x(a), y(b), name(n) 
	{
		std::cout << "Constructed: " << name << '\n';
	}

	~MyClass() 
	{
		std::cout << "Destructed: " << name << '\n';
	};

private:
	int x = 0, y = 0;
	const char* name;
};

class MemoryPool
{
public:
	MemoryPool(std::size_t blockSize, std::size_t blockCount)
		: m_blockSize(blockSize), m_blockCount(blockCount)
	{
		m_pool = ::operator new(m_blockSize * m_blockCount);
		std::cout << "MemoryPool created\n";
	}

	~MemoryPool() 
	{
		::operator delete(m_pool);
		std::cout << "MemoryPool destroyed\n";
	}

	void* allocate() 
	{
		if (m_allocated >= m_blockCount) return nullptr;
		char* ptr = static_cast<char*>(m_pool) + m_blockSize * m_allocated++;
		return static_cast<void*>(ptr);
	}

	void reset() 
	{
        m_allocated = 0; // ���� ���� (�� ��ü�� ��������� �Ҹ���Ѿ� ��)
    }

private:
	void* m_pool = nullptr;
	std::size_t m_blockSize;
	std::size_t m_blockCount;
	std::size_t m_allocated = 0;
};

int main()
{
	MemoryPool pool(sizeof(MyClass), 2);

	// �޸𸮸� Ȯ��
	void* raw1 = pool.allocate();
	void* raw2 = pool.allocate();

	assert(raw1 && raw2);

	// placement new: ��ü ����
	MyClass* obj1 = new (raw1) MyClass(1, 2, "First");
	MyClass* obj2 = new (raw2) MyClass(3, 4, "Second");

	// ���� �Ҹ��� ȣ��
	obj1->~MyClass();
	obj2->~MyClass();

	// �޸� Ǯ ���� ( ���߿� �� ���� ���� )
	pool.reset(); // ���� ��ü���� ���� �غ� �ܰ�
}