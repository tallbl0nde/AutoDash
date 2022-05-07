#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include <functional>
#include <string>

// Typedefs for handlers.
typedef std::function<void(bool)> BoolHandler;
typedef std::function<void(int)> IntHandler;
typedef std::function<void(float)> FloatHandler;
typedef std::function<void(double)> DoubleHandler;
typedef std::function<void(std::string)> StringHandler;

#endif