#pragma once

#if !defined(DEBUG)
#define DEBUG 1
#endif

#define __AsByte(x)			((LByte)x)
#define __AsInt(x)			((LInt)x)
#define __AsLong(x)			((LLong)x)
#define __AsUint(x)			((uint32_t)x)
#define __AsCharacter(x)	((LChar)x)
#define __AsVLong(x)		((LVeryLong)x)
#define __KiB(x)			(1024*x)
#define __MiB(x)			(1024ULL * 1024ULL * x)
#define __GiB(x)			(1024ULL * 1024ULL * 1024ULL * x)

/*
 * General constants that are necessary to define.
 */
#define true	1
#define false	0

/**
 * @brief Typecode constants for collection or set types
 */

typedef enum
{
	TYPECODE_TUPLE = (1 << 14),
	TYPECODE_LIST 		= (1 << 13),
	TYPECODE_DICTIONARY = (1 << 12),
	TYPECODE_SET = (1 << 11),
	TYPECODE_INT = 2,
	TYPECODE_CHARACTER = 4,
	TYPECODE_BOOLEAN = 5,
	TYPECODE_FLOAT = 6,
	TYPECODE_STRING = 7,

	/**
	 * @brief A field map. Logically speaking, this should be a dictionary of fields. Technically. At least, that is the way I would implement 
	 * it internally at the end.
	 */
	TYPECODE_FIELDMAP = 9,

	/**
	 * @brief An executable ZION file.
	 */
	TYPECODE_ZION_SCRIPT = 250,

	/**
	 * @brief This represents an executable instruction.
	 */
	TYPECODE_ZION_OP_POINTER = 252,

	/**
	 * @brief A function in zion executable.
	 */
	TYPECODE_ZION_FUNCTION = 253,

	/**
	 * @brief A class in a Zion project.
	 */
	TYPECODE_ZION_CLASS = 254,
} ZiTypes;

/**
 * @brief A data type representing the type of a given object.
 */
typedef unsigned short typecode;

/**
 * @brief A single signed 64-bit integer.
 */
typedef long long int zi_int;

/**
 * @brief A single double width floating-point number
 */
typedef long double zi_float;

/**
 * @brief A single printable character in Landmark.
 */
typedef unsigned short zi_char;

/**
 * @brief A character pointer representing a single string literal in Landmark.
 */
typedef zi_char* string;

/**
 * @brief A type representing true or false values in Landmark.
 */
typedef unsigned char boolean;


/**
 * @brief The type representing the UTF-16 strings in Landmark. This generally is only used by the VM and should only be used as such.
 */
typedef struct {
	/**
	* @brief The hash code of this string. Technically a number unique to this string.
	*/
	int hash;

	/**
	* @brief The set of characters of this string.
	*/
	string data;

	/**
	* @brief the size of this string in number of characters.
	*/
	zi_int length;

	/**
	 * @brief The number of references to this string. Should be released when this value is 0.
	 */
	unsigned int dirt;
}	ZiString;
