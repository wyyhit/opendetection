//
// Created by sarkar on 17.07.15.
//

#ifndef OPENDETECTION_ODCASCADEDETECTOR_H
#define OPENDETECTION_ODCASCADEDETECTOR_H

#include "common/pipeline/ODDetector.h"
#include "common/pipeline/ODScene.h"
#include "common/utils/utils.h"
#include "common/utils/ODFeatureDetector2D.h"

#include <iostream>
#include <opencv2/opencv.hpp>

namespace od
{
  /** \brief ODCascadeDetector: This class classifies a scene (omni detection) using a provided cascade classifier
   * Given a scene the class will first find HAAR like features and use the cascade classifier to classify the scene. Only supports omni detection for the time being
    *
    *
    * \author Kripasindhu Sarkar
    *
    */

  class ODCascadeDetector: public ODDetector
  {
  public:

    ODCascadeDetector(double scaleFactor = 1.1,
                      int minNeighbors = 3, int flags = 0,
                      cv::Size minSize = cv::Size(),
                      cv::Size maxSize = cv::Size()): scaleFactor_ (scaleFactor), minNeighbors_(minNeighbors), minSize_(minSize), maxSize_(maxSize)
    {
      metainfo_ = true;
    }

    void init()
    {
      haar_cascade_ = boost::make_shared<cv::CascadeClassifier>(training_data_location_);
    }

    ODDetections2D* detect(ODSceneImage *scene)
    {
    }

    ODDetections2D* detectOmni(ODSceneImage *scene);

    int detect(ODScene *scene, vector<ODDetection *> &detections) {}

  private:
    boost::shared_ptr<cv::CascadeClassifier> haar_cascade_;

    double scaleFactor_;
    int minNeighbors_;
    cv::Size minSize_;
    cv::Size maxSize_;

  };

}

#endif //OPENDETECTION_ODCASCADEDETECTOR_H
