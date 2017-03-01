//
// Created by cory on 3/1/17.
//

#ifndef CPP_KITTI_TRACKING_H
#define CPP_KITTI_TRACKING_H

#include "typedef.h"

vector<vector<tGroundtruth> > load_tracking_gt(string gt_filename);
vector<vector<tDetection> > load_tracking_det(string gt_filename);


#endif //CPP_KITTI_TRACKING_H
