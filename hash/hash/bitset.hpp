#pragma once
#include<vector>
#include<assert.h>
namespace bite
{
	template<size_t N>
	class bieset
	{
		public;
		bitset()
		{
			//��8+1
			_bs.resize((N >> 3) + 1);
		}
		bitset<N>& set(size_t num)
		{
			assert(num < N);
			//����num����Ӧ���ֽ�
			size_t index = (num >> 3);
			//����num����Ӧ�ֽڵı���λ
			size_t pos = num % 8;

			_bs[index] |= 1 << pos;
			return *this;
		}
		bitset<N>& reset(size_t num)
		{
			assert(num < N);
			//����num����Ӧ���ֽ�
			size_t index = (num >> 3);
			//����num����Ӧ�ֽڵı���λ
			size_t pos = num % 8;

			_bs[index] &= ~(1 << pos);
			return *this;
		}
		bool test(size_t num) const
		{
			assert(num < N);
			//����num����Ӧ���ֽ�
			size_t index = (num >> 3);
			//����num����Ӧ�ֽڵı���λ
			size_t pos = num % 8;

			return (_bs[index] & (1 << pos));
		}
		size_t count() const
		{
			return N;
		}
		size_t size() const
		{

		}
		private:
		vector<char> _bs;
	};
}
