#ifndef STARSKY_GEOMETRY_FRENETPOINT_H_
#define STARSKY_GEOMETRY_FRENETPOINT_H_

namespace starsky {

struct FrenetPoint {
  float s;
  float d;

  inline FrenetPoint(float distanceAlong, float distanceAcross)
      : s(distanceAlong), d(distanceAcross) {}
};

}  // namespace starsky

#endif  // STARSKY_GEOMETRY_FRENETPOINT_H_
