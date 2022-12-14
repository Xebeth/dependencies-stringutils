/**************************************************************************
	created		:	2011-10-10
	filename	: 	utf8_convert.cpp
	author		:	Xebeth`
	copyright	:	North Edge (2011)
	purpose		:	
**************************************************************************/
#include "stdafx.h"

#include <vector>
#include "string_t.h"
#include "utf8_convert.h"

/*! \brief Converts an UTF-8 string to ANSI
	\param[in] String_in : the input string to convert
	\param[out] String_out : the output string receiving the result of the conversion
	\return a reference to the output string parameter
*/
std::string& convert_ansi(const string_t& String_in, std::string& String_out, UINT CharSet_in)
{
	// convert the string
	int sizeNeeded = WideCharToMultiByte(CharSet_in, 0UL, String_in.c_str(), static_cast<int>(String_in.length()),
										 const_cast<char*>(String_out.c_str()), 0, nullptr, nullptr);

	if (sizeNeeded > 0)
	{
		// reserve enough space to hold the converted text
		String_out.resize(sizeNeeded);

		WideCharToMultiByte(CharSet_in, 0UL, String_in.c_str(), static_cast<int>(String_in.length()),
							const_cast<char*>(String_out.c_str()), sizeNeeded, nullptr, nullptr);
	}

	return String_out;
}



/*! \brief Converts an ANSI string to UTF-8
	\param[in] String_in : the input string to convert
	\param[out] String_out : the output string receiving the result of the conversion
	\return a reference to the output string parameter
*/
string_t& convert_utf8(const std::string& String_in, string_t& String_out, UINT CharSet_in)
{
	// convert the string
	int sizeNeeded = MultiByteToWideChar(CharSet_in, 0UL, String_in.c_str(), static_cast<int>(String_in.length()),
										 const_cast<TCHAR*>(String_out.c_str()), 0);

	if (sizeNeeded > 0)
	{
		// reserve enough space to hold the converted text
		String_out.resize(sizeNeeded);

		MultiByteToWideChar(CharSet_in, 0UL, String_in.c_str(), static_cast<int>(String_in.length()),
							const_cast<TCHAR*>(String_out.c_str()), sizeNeeded);
	}

	return String_out;
}

/*! \brief Retrieves the length of a string if it were to be converted to UTF-8
	\param[in] String_in : the string to be converted
	\return the length of the string in the UTF-8 codepage
*/
size_t utf8_len(const std::string& String_in)
{
	return MultiByteToWideChar(CP_UTF8, 0UL, String_in.c_str(), (int)String_in.length(), nullptr, 0);
}

/*! \brief Retrieves the length of a string if it were to be converted to ANSI
	\param[in] String_in : the string to be converted
	\return the length of the string in the ANSI codepage
*/
size_t ansi_len(const string_t& String_in)
{
	return WideCharToMultiByte(CP_ACP, 0UL, String_in.c_str(), static_cast<int>(String_in.length()), nullptr, 0, nullptr, nullptr);
}