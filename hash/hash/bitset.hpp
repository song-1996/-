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
			//除8+1
			_bs.resize((N >> 3) + 1);
		}
		bitset<N>& set(size_t num)
		{
			assert(num < N);
			//计算num所对应的字节
			size_t index = (num >> 3);
			//计算num所对应字节的比特位
			size_t pos = num % 8;

			_bs[index] |= 1 << pos;
			return *this;
		}
		bitset<N>& reset(size_t num)
		{
			assert(num < N);
			//计算num所对应的字节
			size_t index = (num >> 3);
			//计算num所对应字节的比特位
			size_t pos = num % 8;

			_bs[index] &= ~(1 << pos);
			return *this;
		}
		bool test(size_t num) const
		{
			assert(num < N);
			//计算num所对应的字节
			size_t index = (num >> 3);
			//计算num所对应字节的比特位
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
