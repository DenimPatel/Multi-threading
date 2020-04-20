#ifndef STARSKY_GEOMETRY_REFERENCEPOSES_H_
#define STARSKY_GEOMETRY_REFERENCEPOSES_H_

#include <utility>
#include <vector>

#include <boost/optional.hpp>

#include "Pose2d.h"

namespace starsky {

class FrenetPoint;

/**
 * @brief Defines a series of poses in fixed frame that can be used as reference
 * to compute coordinates in a frenet frame
 */
class ReferencePoses {
 public:
  static constexpr float PRECISION = 0.001;  // 1 mm.

  /**
   * @brief Construct based on a series of reference poses on
   * fixed frame
   *
   * @param poses
   */
  explicit ReferencePoses(const std::vector<Pose2d>& poses);

  /**
   * @brief get the SD coodinates on the Frenet Frame for the first projection
   * of this pose after reference distance.
   *
   * @param p
   * @return std::vector<FrenetPoint>
   */
  boost::optional<FrenetPoint> computeSDAfter(const Pose2d& p, float referenceDistance) const;

 private:
  std::vector<Pose2d> referencePoses_;
};

}  // namespace starsky

#endif  // STARSKY_GEOMETRY_REFERENCEPOSES_H_
