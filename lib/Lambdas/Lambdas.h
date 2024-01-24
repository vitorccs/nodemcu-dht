#ifndef LAMBDAS_H
#define LAMBDAS_H
#include <Arduino.h>
#include <Measures.h>
#include <functional>

typedef std::function<Measures()> MeasuresHandlerFn;
typedef std::function<String()> TimeHandlerFn;

#endif