#pragma once

#ifdef DEBUG
#define DEBUG_PRINT(output) {\
	std::wcout << "[DEBUG] " << output << std::endl;\
	}
#else
#define DEBUG_PRINT(output) 
#endif // DEBUG


enum Errors_e : INT
{
	ERROR_GUIPSEXEC_SUCCESS = 0,
	ERROR_ARGUMENTS_PARSE
};
