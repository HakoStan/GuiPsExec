#pragma once

#include <exception>

namespace WinFramework
{
namespace FileApiExceptions
{
	class SourceFileNotFound : public std::exception { };
}
}