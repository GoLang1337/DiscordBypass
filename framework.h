#pragma once

#define WIN32_LEAN_AND_MEAN             // Escludere gli elementi usati raramente dalle intestazioni di Windows
// File di intestazione di Windows
#include <windows.h>
#include <iostream>
#include <fstream>
#include "detours.h"
#pragma comment(lib, "detours.lib")
#pragma warning(disable: 6387 26819)