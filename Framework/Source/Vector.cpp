#include <Vector.hpp>
#include <math.h>

namespace Olorin
{
	namespace Framework
	{
		const float Vector::getLength() const
		{
			return float(::sqrt(getLengthSquared()));
		}
	}
}