# copy tool
cp  ./cmake-build-debug/kitti_eval ./kitti_eval
# copy detecions
cp ~/fdt/python/kitti_objects.txt ./
# run tool
result_dir=$1
./kitti_eval ./label_02/0001.txt ./kitti_objects.txt $result_dir
# plot
cd $result_dir && gnuplot car_detection.gp && gnuplot pedestrian_detection.gp

