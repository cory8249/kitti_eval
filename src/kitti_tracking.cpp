//
// Created by cory on 3/1/17.
//

#include <string>
#include "kitti_tracking.h"

vector<vector<tGroundtruth> > load_tracking_gt(string gt_filename) {
    printf("load_tracking_gt(), filename = %s\n", gt_filename.c_str());

    vector<vector<tGroundtruth> > gt_all = vector<vector<tGroundtruth> >();

    // holds all ground truth (ignored ground truth is indicated by an index vector
    FILE *fp = fopen(gt_filename.c_str(), "r");
    if (!fp) {
        return gt_all;
    }
    int frame;
    int object_id;
    while (!feof(fp)) {
        tGroundtruth g;
        double trash;
        char label[255];
        if (fscanf(fp, "%d %d %s %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
                   &frame, &object_id, label, &g.truncation, &g.occlusion, &g.box.alpha,
                   &g.box.x1, &g.box.y1, &g.box.x2, &g.box.y2,
                   &trash, &trash, &trash, &trash,
                   &trash, &trash, &trash) == 17) {
            g.box.type = string(label);
            if (gt_all.size() < frame + 1) {
                gt_all.push_back(vector<tGroundtruth>());
            }
            gt_all[frame].push_back(g);

        }
    }

    for (int i = 0; i < gt_all.size(); i++) {
        for (int j = 0; j < gt_all[i].size(); j++) {
            tGroundtruth g = gt_all[i][j];
            // printf("%d: %s, %f, %f, %f, %f\n", i, g.box.type.c_str(), g.box.x1, g.box.y1, g.box.x2, g.box.y2);
        }
    }
    fclose(fp);
    printf("gt_all.size() = %d\n", gt_all.size());
    return gt_all;
}

vector<vector<tDetection> > load_tracking_det(string gt_filename) {
    printf("load_tracking_det(), filename = %s\n", gt_filename.c_str());

    vector<vector<tDetection> > det_all = vector<vector<tDetection> >();

    // holds all ground truth (ignored ground truth is indicated by an index vector
    FILE *fp = fopen(gt_filename.c_str(), "r");
    if (!fp) {
        return det_all;
    }
    int frame;
    int object_id;
    while (!feof(fp)) {
        tDetection g;
        char label[255];
        fscanf(fp, "%d %d %s %*f %*d %lf %lf %lf %lf %lf %*f %*f %*f %*f %*f %*f %lf",
               &frame, &object_id, label, &g.box.alpha,
               &g.box.x1, &g.box.y1, &g.box.x2, &g.box.y2, &g.thresh);
        g.box.type = string(label);
        while (det_all.size() < frame + 1) {
            det_all.push_back(vector<tDetection>());
        }
        det_all[frame].push_back(g);

    }

    for (int i = 0; i < det_all.size(); i++) {
        for (int j = 0; j < det_all[i].size(); j++) {
            tDetection g = det_all[i][j];
            // printf("%d: %s, %f, %f, %f, %f\n", i, g.box.type.c_str(), g.box.x1, g.box.y1, g.box.x2, g.box.y2);
        }
    }
    fclose(fp);
    printf("det_all.size() = %d\n", det_all.size());
    return det_all;
}