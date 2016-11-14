#pragma once
#include "Common.h"

namespace BONE_FRAMEWORK
{
	template<class T>
	class SmartPointer
	{
	public:
		SmartPointer(VOID) { Class = new T(); }
		~SmartPointer(VOD) { delete Class; }

		T* operator->(VOID) { return Class; }
		opertaor T*(VOID) { return Class; }
	private:
		T* Class;
	};
}
