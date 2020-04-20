#ifndef STARSKY_GEOMETRY_POSE2D_H_
#define STARSKY_GEOMETRY_POSE2D_H_

#include <cmath>
#include "Angle.h"
#include "Point2d.h"

namespace starsky {

class Pose2d {
 public:
  Pose2d();
  Pose2d(float x, float y, float theta);
  Pose2d(const Point2d& rhs, const Angle& theta);
  Pose2d(const Pose2d& rhs);

  Pose2d& operator=(const Pose2d& rhs);

  bool operator==(const Pose2d& p2) const;
  bool operator!=(const Pose2d& p2) const;

  float getX() const;

  float getY() const;

  Point2d getPoint() const;

  Angle getTheta() const;

 private:
  Point2d point_;
  Angle theta_;
};

}  // namespace starsky

#endif  // STARSKY_GEOMETRY_POSE2D_H_
