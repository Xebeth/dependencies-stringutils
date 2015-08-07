/**************************************************************************
created		:	2011-05-29
filename	: 	string_t.h
author		:	xebeth`
copyright	:	North Edge (2011)
purpose		:	wchar_t based std::basic_string<T> with formatting support
**************************************************************************/
#ifndef __STRING_HASH_H__
#define __STRING_HASH_H__

#ifndef _STRING_UTILS_SDK_INCLUDE_
	#error Please include the global header file 'StringUtils.h'
#endif

namespace StringUtils
{
	template<typename T> class Hash
	{
	public:
		template <size_t N> __forceinline Hash(const T(&str)[N]) { m_val = _Hash(str); }
		operator DWORD() const { return m_val; }

	private:
		template<size_t N> __forceinline DWORD _Hash(const T(&str)[N])
		{
			typedef const T(&truncated_str)[N - 4];
			return str[N - 1] + 65599 * (str[N - 2] + 65599 * (str[N - 3] + 65599 * (str[N - 4] + 65599 * _Hash((truncated_str)str))));
		}
		__forceinline DWORD _Hash(const T(&str)[4])
		{
			typedef const T(&truncated_str)[3];
			return str[3] + 65599 * _Hash((truncated_str)str);
		}
		__forceinline DWORD _Hash(const T(&str)[3])
		{
			typedef const T(&truncated_str)[2];
			return str[2] + 65599 * _Hash((truncated_str)str);
		}
		__forceinline DWORD _Hash(const T(&str)[2]) { return str[1] + 65599 * str[0]; }
		__forceinline DWORD _Hash(const T(&str)[1]) { return str[0]; }

		DWORD m_val;
	};
}

#endif//__STRING_HASH_H__