/**************************************************************************
	created		:	2011-05-29
	filename	: 	string_t.cpp
	author		:	xebeth`
	copyright	:	North Edge (2011)
	purpose		:	TCHAR based std::string with formatting support
**************************************************************************/
#include "stdafx.h"

#include <vector>
#include "string_t.h"
#include "utf8_convert.h"

template<> std::basic_string<wchar_t>::size_type get_format_length(const wchar_t* pFormat_in, va_list ArgList_in)
{
	// compute the size of the formatted message -- +1 => _vscwprintf doesn't count the null terminating character
	return _vscwprintf(pFormat_in, ArgList_in) + 1;
}

template<> std::basic_string<char>::size_type get_format_length(const char* pFormat_in, va_list ArgList_in)
{
	// compute the size of the formatted message -- +1 => _vscprintf doesn't count the null terminating character
	return _vscprintf(pFormat_in, ArgList_in) + 1;
}

template<> std::basic_string<wchar_t>::size_type format_arglist(wchar_t** pBuffer_in_out, std::basic_string<wchar_t>::size_type BufferSize_in, const wchar_t* pFormat_in, va_list ArgList_in)
{
	// format the resulting message -- +1 => vswprintf_s doesn't count the null terminating character
	return vswprintf_s(*pBuffer_in_out, BufferSize_in, pFormat_in, ArgList_in) + 1;
}

template<> std::basic_string<char>::size_type format_arglist(char** pBuffer_in_out, std::basic_string<char>::size_type BufferSize_in, const char* pFormat_in, va_list ArgList_in)
{
	// format the resulting message -- +1 => vsprintf_s doesn't count the null terminating character
	return vsprintf_s(*pBuffer_in_out, BufferSize_in, pFormat_in, ArgList_in) + 1;
}

template <> errno_t open_file<wchar_t>(FILE** pFile_in_out, const std::basic_string<wchar_t>& Filename_in, const char* OpenMode_in)
{
	string_t openMode;

	return _wfopen_s(pFile_in_out, Filename_in.c_str(), convert_utf8(OpenMode_in, openMode).c_str());
}

template <> errno_t open_file<char>(FILE** pFile_in_out, const std::basic_string<char>& Filename_in, const char* OpenMode_in) 
{
	return fopen_s(pFile_in_out, Filename_in.c_str(), OpenMode_in);
}
