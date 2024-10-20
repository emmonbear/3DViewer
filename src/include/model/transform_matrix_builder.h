/**
 * @file transform_matrix_builder.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief Header file for the TransformMatrixBuilder class.
 * @version 1.0
 * @date 2024-09-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_BUILDER_H_
#define SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_BUILDER_H_

#include "include/model/transform_matrix.h"

namespace s21 {

/**
 * @class TransformMatrixBuilder
 * @brief A utility class for building common 3D transformation matrices.
 *
 * This class provides static methods for generating 4x4 matrices used for
 * rotating, moving (translating), and scaling objects in 3D space. These
 * methods return instances of the TransformMatrix class, ready for use in
 * transformations.
 */
class TransformMatrixBuilder {
 public:
  static TransformMatrix CreateRotationMatrix(float x, float y,
                                              float z) noexcept;
  static TransformMatrix CreateMoveMatrix(float x, float y, float z) noexcept;
  static TransformMatrix CreateScaleMatrix(float x, float y, float z) noexcept;

 private:
  static constexpr float kRadian = 0.0174533f;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_TRANSFORM_MATRIX_BUILDER_H_
