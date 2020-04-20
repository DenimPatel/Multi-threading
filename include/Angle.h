#ifndef STARSKY_GEOMETRY_ANGLE_H_
#define STARSKY_GEOMETRY_ANGLE_H_
#include <cmath>
#include <iostream>
#include <type_traits>

namespace starsky {

/**
 * @brief Basic class to handle angles. The class enforces wrapping on
 * operations. The default value for wrapping is +-M_PI and the angle is always
 * wrapped.
 *
 */
class Angle {
 public:
  /// default constructor initializes it to 0.0f
  Angle();

  explicit Angle(float a, float minValue = -M_PI, float maxValue = M_PI);

  Angle(const Angle& a);

  Angle& operator=(const Angle& rhs);

  /// @brief: wraps an angle between minAngle and maxAngle
  Angle& wrap();

  /// @brief: wraps an angle between minAngle and maxAngle
  static float wrap(float angle, float minValue = -M_PI, float maxValue = M_PI);

  bool operator==(const Angle& rhs) const;

  bool operator!=(const Angle& rhs) const;

  /**
   * @brief overload of the sum operator. Wraps the angle between (minAngle, maxAngle)
   *
   * @param a2
   * @return Angle
   */
  Angle operator+(const Angle& a2) const;

  /**
   * @brief overload of the subtraction operator. Wraps the angle between (-pi,
   * pi)
   *
   * @param a2
   * @return Angle
   */
  Angle operator-(const Angle& a2) const;

  /**
   * @brief overload of the multiplication by scalar. Wraps the angle between
   * (minAngle, maxAngle)
   *
   * @param a2
   * @return Angle
   */
  template <typename T>
  friend Angle operator*(const Angle& a, T mult);

  /**
   * @brief overload of the multiplication by scalar. Wraps the angle between
   * (minAngle, maxAngle)
   *
   * @param a2
   * @return Angle
   */
  template <typename T>
  friend Angle operator*(T mult, const Angle& a);

  /**
   * @brief float operator. Returns the angle as a float
   *
   * @return float
   */
  operator float();

 private:
  float theta_ = 0.0f;
  float minValue_ = -M_PI;
  float maxValue_ = M_PI;
};

template <typename T>
inline Angle operator*(const Angle& a, T mult) {
  static_assert(std::is_arithmetic<T>::value, "An arithmetic type is required");
  return Angle(a.theta_ * mult);
}

template <typename T>
inline Angle operator*(T mult, const Angle& a) {
  static_assert(std::is_arithmetic<T>::value, "An arithmetic type is required");
  return a * mult;
}

}  // namespace starsky

#endif  // STARSKY_GEOMETRY_ANGLE_H_
