#pragma once

#include <exception>

namespace Exceptions
{
	namespace ConfigurationExceptions
	{
		struct ArgumentsParseException : public std::exception { };
	}
}