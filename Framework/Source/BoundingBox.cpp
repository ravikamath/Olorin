#include <BoundingBox.hpp>

namespace Olorin
{
	namespace Framework
	{
		BoundingBox::BoundingBox() {}
		BoundingBox::BoundingBox(const Vector3& min, const Vector3& max)
		{
			this->min = min;
			this->max = max;
		}

		void BoundingBox::setMin(const Vector3& min) { this->min = min; }
		void BoundingBox::setMax(const Vector3& max) { this->max = max; }

		const Vector3& BoundingBox::getMin() const { return min; }
		const Vector3& BoundingBox::getMax() const { return max; }

		const Vector3 BoundingBox::getCenter() const
		{
			return (min + max) / 2;
		}

		void BoundingBox::include(const Vector3& point)
		{
			min.min(point); max.max(point);
		}

		void BoundingBox::include(const BoundingBox& boundingBox)
		{
			min.min(boundingBox.min);
			max.max(boundingBox.max);
		}
	}
}