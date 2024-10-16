/**
 * @file scene.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_MODEL_SCENE_H_
#define SRC_INCLUDE_MODEL_SCENE_H_

#include <vector>

#include "include/model/vertex.h"

namespace s21 {

class Scene {
 public:
  Scene() = default;
  Scene(const std::vector<int>& indices, const std::vector<Vertex>& vertices,
        float normalize_param) noexcept;

  inline const std::vector<int>& indices() const noexcept { return indices_; }

  inline const std::vector<Vertex>& vertices() const noexcept {
    return vertices_;
  }
  inline const std::vector<Vertex>& base_vertices() const noexcept {
    return data_;
  }

  void Transform(const TransformMatrix& matrix) noexcept;

 private:
  std::vector<int> indices_;
  std::vector<Vertex> vertices_;
  std::vector<Vertex> data_;
};

}  // namespace s21

#endif  // SRC_INCLUDE_MODEL_SCENE_H_
