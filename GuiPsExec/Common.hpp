#pragma once

#ifdef DEBUG
#define DEBUG_PRINT(output) {\
	std::wcout << "[DEBUG] " << output << std::endl;\
	}
#else
#define DEBUG_PRINT(output) 
#endif // DEBUG

#define GUIPSEXEC_SUCCEEDED(a) (((Errors_e)(a)) == 0)
#define GUIPSEXEC_FAILED(a) (((Errors_e)(a)) > 0)


enum Errors_e : USHORT
{
	GUIPSEXEC_SUCCESS = 0,
	ERROR_ARGUMENTS_PARSE
};
