#pragma once

#include <exception>

namespace WinFramework
{
namespace FileApiExceptions
{
	struct SourceFileNotFound : public std::exception { };

	struct UnkownException : public std::exception {};
}
}