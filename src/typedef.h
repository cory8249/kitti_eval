//
// Created by cory on 3/1/17.
//

#ifndef CPP_TYPEDEF_H
#define CPP_TYPEDEF_H

#include <stdio.h>
#include <math.h>
#include <vector>
#include <numeric>


using namespace std;

/*=======================================================================
STATIC EVALUATION PARAMETERS
=======================================================================*/

// holds the number of test images on the server
// const int32_t N_TESTIMAGES = 7481;
const int N_TESTIMAGES = 233;

// easy, moderate and hard evaluation level
enum DIFFICULTY {
    EASY = 0, MODERATE = 1, HARD = 2
};

// evaluation parameter
const int32_t MIN_HEIGHT[3] = {40, 25, 25};     // minimum height for evaluated groundtruth/detections
const int32_t MAX_OCCLUSION[3] = {0, 1, 2};        // maximum occlusion level of the groundtruth used for evaluation
const double MAX_TRUNCATION[3] = {0.15, 0.3, 0.5}; // maximum truncation level of the groundtruth used for evaluation

// evaluated object classes
enum CLASSES {
    CAR = 0, PEDESTRIAN = 1, CYCLIST = 2
};

// no. of recall steps that should be evaluated (discretized)
const double N_SAMPLE_PTS = 41;

// holding data needed for precision-recall and precision-aos
struct tPrData {
    vector<double> v;           // detection score for computing score thresholds
    double similarity;  // orientation similarity
    int32_t tp;          // true positives
    int32_t fp;          // false positives
    int32_t fn;          // false negatives
    tPrData() :
            similarity(0), tp(0), fp(0), fn(0) {}
};

// holding bounding boxes for ground truth and detections
struct tBox {
    string type;     // object type as car, pedestrian or cyclist,...
    double x1;      // left corner
    double y1;      // top corner
    double x2;      // right corner
    double y2;      // bottom corner
    double alpha;   // image orientation
    tBox(string type, double x1, double y1, double x2, double y2, double alpha) :
            type(type), x1(x1), y1(y1), x2(x2), y2(y2), alpha(alpha) {}
};

// holding ground truth data
struct tGroundtruth {
    tBox box;        // object type, box, orientation
    double truncation; // truncation 0..1
    int32_t occlusion;  // occlusion 0,1,2 (non, partly, fully)
    tGroundtruth() :
            box(tBox("invalild", -1, -1, -1, -1, -10)), truncation(-1), occlusion(-1) {}

    tGroundtruth(tBox box, double truncation, int32_t occlusion) :
            box(box), truncation(truncation), occlusion(occlusion) {}

    tGroundtruth(string type, double x1, double y1, double x2, double y2, double alpha, double truncation,
                 int32_t occlusion) :
            box(tBox(type, x1, y1, x2, y2, alpha)), truncation(truncation), occlusion(occlusion) {}
};

// holding detection data
struct tDetection {
    tBox box;    // object type, box, orientation
    double thresh; // detection score
    tDetection() :
            box(tBox("invalid", -1, -1, -1, -1, -10)), thresh(-1000) {}

    tDetection(tBox box, double thresh) :
            box(box), thresh(thresh) {}

    tDetection(string type, double x1, double y1, double x2, double y2, double alpha, double thresh) :
            box(tBox(type, x1, y1, x2, y2, alpha)), thresh(thresh) {}
};



#endif //CPP_TYPEDEF_H
