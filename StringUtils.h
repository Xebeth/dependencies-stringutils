/**************************************************************************
	created		:	2013-04-08
	filename	: 	StringUtils.h
	author		:	Xebeth`
	copyright	:	North Edge (2013)
	purpose		:	String & misc. utilities library
**************************************************************************/
#ifndef __STRING_UTILS_H__
#define __STRING_UTILS_H__

#include <NonCopyable.h>
#include <unordered_map>
#include <tchar.h>
#include <string>
#include <vector>
#include <list>

#define _STRING_UTILS_SDK_INCLUDE_

#include <string_t.h>
#include <utf8_convert.h>

#include <CryptUtils.h>
#include <StringHash.h>
#include <UUID.h>

#define _H(x) StringUtils::Hash(x)

#ifdef _DEBUG
	#ifdef _M_X64
		#pragma comment(lib, "StringUtils.x64d.lib")
	#else
		#pragma comment(lib, "StringUtils.x86d.lib")
	#endif
#else
	#ifdef _M_X64
		#pragma comment(lib, "StringUtils.x64.lib")
	#else
		#pragma comment(lib, "StringUtils.x86.lib")
	#endif
#endif // _DEBUG

#undef _STRING_UTILS_SDK_INCLUDE_

#endif//__STRING_UTILS_H__
