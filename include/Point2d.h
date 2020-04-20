#ifndef STARSKY_GEOMETRY_POINT2D_H_
#define STARSKY_GEOMETRY_POINT2D_H_

#include <cmath>
#include <type_traits>

namespace starsky {

class Point2d {
 public:
  Point2d();
  Point2d(float x, float y);
  Point2d(const Point2d& rhs);

  Point2d& operator=(const Point2d& rhs);

  bool operator==(const Point2d& p2) const;
  bool operator!=(const Point2d& p2) const;

  template <typename T>
  friend Point2d operator*(const Point2d& p, T mult);

  template <typename T>
  friend Point2d operator*(T mult, const Point2d& p);

  float getX() const;

  float getY() const;

  float norm() const;

 private:
  float x_;
  float y_;
};

Point2d
operator+(const Point2d& p, const Point2d& p2);
Point2d
operator-(const Point2d& p, const Point2d& p2);

template <typename T>
inline Point2d operator*(const Point2d& p, T mult) {
  static_assert(std::is_arithmetic<T>::value, "An arithmetic type is required");
  return Point2d(p.x_ * mult, p.y_ * mult);
}

template <typename T>
inline Point2d operator*(T mult, const Point2d& p) {
  static_assert(std::is_arithmetic<T>::value, "An arithmetic type is required");
  return p * mult;
}

}  // namespace starsky

#endif  // STARSKY_GEOMETRY_POINT2D_H_
