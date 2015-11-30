#pragma once

#ifndef __OLORIN_IVECTOR__
#define __OLORIN_IVECTOR__

#include <DLL.hpp>

namespace Olorin
{
	namespace Framework
	{
		class DLLAPI Vector
		{
		public:
			virtual void setValue(const int& index, const float& value) = 0;
			virtual const float& getValue(const int& index) const = 0;
			virtual const float& operator [](const int& index) const = 0;
			virtual float& operator [](const int& index) = 0;

			const float getLength() const;
			virtual const float getLengthSquared() const = 0; // Length of the vector squared
		};
	}
}

#endif
