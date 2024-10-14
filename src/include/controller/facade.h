/**
 * @file facade.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief
 * @version 1.0
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_CONTROLLER_FACADE_H_
#define SRC_INCLUDE_CONTROLLER_FACADE_H_

#include <string>

#include "include/model/file_reader.h"
#include "include/model/file_reader_base.h"
#include "include/model/scene.h"
#include "include/model/scene_drawer.h"
#include "include/model/scene_drawer_base.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade();

  void loadScene(const std::string &path);
  void drawScene();
  std::size_t numberOfVerticies();
  std::size_t numberOfEdges();
  inline SceneDrawerBase *getView() { return scene_drawer_; }

 private:
  SceneDrawerBase *scene_drawer_;
  FileReaderBase *file_reader_;
  Scene *scene_{};
};

}  // namespace s21

#endif  // SRC_INCLUDE_CONTROLLER_FACADE_H_
