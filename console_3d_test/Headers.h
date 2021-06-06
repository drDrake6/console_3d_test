#pragma once
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <conio.h>
#include <algorithm>
#include <chrono>
#include <vector>
#include <stack>
#include <list>
#include <typeinfo>

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
using namespace std;

#include "Exeptions.h"
#include "FPS.h"
#include "DynamicArray.h"
#include "Map.h"
#include "GameObject.h"
#include "GameSpace.h"
#include "Item.h"
#include "Entity.h"
#include "Building.h"
#include "Door.h"
#include "CircDoor.h"
#include "RombDoor.h"
#include "TrianDoor.h"
#include "Trap.h"
#include "WeakTrap.h"
#include "MediumTrap.h"
#include "StrongTrap.h"
#include "Exit.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "MedKit.h"
#include "Player.h"
#include "ConsoleBufferString.h"
