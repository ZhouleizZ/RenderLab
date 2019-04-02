#ifndef _CPPUTIL_BASIC_MATH_POINT2_H_
#define _CPPUTIL_BASIC_MATH_POINT2_H_

#include <CppUtil/Basic/Val2.h>
#include <CppUtil/Basic/Point.h>
#include <CppUtil/Basic/Vector2.h>

namespace CppUtil {
	namespace Basic {
		template <typename T>
		class Point<2, T> : public Val<2, T> {
		public:
			using Val<2, T>::Val;

		public:
			static float Distance2(const Point & p0, const Point & p1) {
				return (p1 - p0).Length2();
			}
			float Distance2With(const Point & p) {
				return Distance2(*this, p);
			}

			static float Distance(const Point & p0, const Point & p1) {
				return (p1 - p0).Length();
			}
			float DistanceWith(const Point & p) {
				return Distance(*this, p);
			}

			static Point Lerp(const Point & p0, const Point & p1, float t) {
				return p0 + t * (p1 - p0);
			}
			const Point LerpWith(const Point p1, float t) {
				return Lerp(*this, p1, t);
			}

			static Point Mid(const Point & p0, const Point & p1) {
				return Lerp(p0, p1, 0.5f);
			}
			static Point MidWith(const Point p1) {
				return Mid(*this, p1);
			}

			static Point Min(const Point & p0, const Point & p1) {
				return Point(std::min(p0.x, p1.x), std::min(p0.y, p1.y))
			}
			static Point MinWith(const Point & p) {
				return Min(*this, p);
			}

			static Point Max(const Point & p0, const Point & p1) {
				return Point(std::max(p0.x, p1.x), std::max(p0.y, p1.y));
			}
			static Point MaxWith(const Point & p) {
				return Max(*this, p);
			}

		public:
			const Vector<2, T> operator-(const Point &p) const {
				return Vector<2, T>(x - p.x, y - p.y);
			}

			const Point operator+(const Vector<2, T> &v) const {
				return Point(x + v.x, y + v.y);
			}

			Point & operator+=(const Vector<2, T> &v) {
				x += v.x;
				y += v.y;
				return *this;
			}

			const Point operator-(const Vector<2, T> &v) const {
				return Point(x - v.x, y - v.y);
			}

			const Point & operator-=(const Vector<2, T> &v) {
				x -= v.x;
				y -= v.y;
				return *this;
			}
		};
	}
}

#endif // !_CPPUTIL_BASIC_MATH_POINT2_H_