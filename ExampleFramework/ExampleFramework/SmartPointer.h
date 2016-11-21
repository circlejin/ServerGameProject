#pragma once
#include "Common.h"

namespace BONE_FRAMEWORK
{
	template<class T>
	class SmartPointer
	{
	private:
		T* myClass;

	public:
		SmartPointer(VOID) { myClass = new T(); }
		~SmartPointer(VOID) { delete myClass; }

		T* operator->(VOID) { return myClass; }
		operator T*(VOID) { return myClass; }
	};
}
