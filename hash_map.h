/**************************************************************************
created		:	2011-05-29
filename	: 	string_t.h
author		:	xebeth`
copyright	:	North Edge (2011)
purpose		:	wchar_t based std::basic_string<T> with formatting support
**************************************************************************/
#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__

#ifndef _STRING_UTILS_SDK_INCLUDE_
	#error Please include the global header file 'StringUtils.h'
#endif

#include <unordered_map>
#include <string>

template <typename char_t> class hash_key_t
{
public:
	inline size_t operator()(const std::basic_string<char_t> &str) const
	{
		const char_t *s = str.c_str();
		size_t hash = 1;

		for (; *s; ++s) 
			hash = hash * 5 + *s;

		return hash;
	}

	inline bool operator()(const std::basic_string<char_t> &s1, const std::basic_string<char_t> &s2) const
	{
		return (s1.compare(s2) == 0);
	}
};

template<typename key_char_t, typename value_t> using hash_map = std::unordered_map<std::basic_string<key_char_t>, value_t, hash_key_t<key_char_t>, hash_key_t<key_char_t>>;

#endif//__HASH_MAP_H__