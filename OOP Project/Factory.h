#pragma once
#include "Components.h"
enum ShapeTypes : size_t {
	CIRCLE,
	SQUARE,
	RECTANGLE
};


class Manager {
public:
	template <typename T, typename... Args>
	T* parseShape(ShapeTypes type, Args&&... args)
	{
		return new T(forward<Args>(args)...);
		/*switch (type)
		{
		case ShapeTypes::CIRCLE:
			return new T(forward<Args>(args)...);
			break;
		case ShapeTypes::SQUARE:
			return new T(forward<Args>(args)...);
			break;
		case ShapeTypes::RECTANGLE:
			return new T(forward<Args>(args)...);
			break;
		default:
			return nullptr;
			break;
		}*/
	}
};
