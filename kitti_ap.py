from __future__ import print_function

import os
import sys
import subprocess
import shutil
from numpy import genfromtxt


def calculate_ap(recall, precision):
    x = recall
    y = precision
    dx = x[1] - x[0]
    ap = 0.0
    for i in range(1, len(y)):
        ap += y[i] * dx
    return ap


def eval_file(detection_filename):
    if not os.path.isfile(detection_filename):
        print('not found')
        return

    matrix = genfromtxt(detection_filename)
    recall = matrix[:, 0]
    precision_easy = matrix[:, 1]
    precision_moderate = matrix[:, 2]
    precision_hard = matrix[:, 3]
    ap_easy = calculate_ap(recall, precision_easy)
    ap_moderate = calculate_ap(recall, precision_moderate)
    ap_hard= calculate_ap(recall, precision_hard)
    print('easy     = ', ap_easy)
    print('moderate = ', ap_moderate)
    print('hard     = ', ap_hard)


def main(result_dir):
    print(result_dir)
    print()
    print('car')
    eval_file(os.path.join(result_dir, 'car_detection.txt'))

    print()
    print('pedestrian')
    eval_file(os.path.join(result_dir, 'pedestrian_detection.txt'))

    print()
    print('cyclist')
    eval_file(os.path.join(result_dir, 'cyclist_detection.txt'))


if __name__ == '__main__':
    main(sys.argv[1])
