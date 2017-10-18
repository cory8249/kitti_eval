cp cmake-build-debug/eval_ap .
rm -rf result/*
rm ./det_labels/*
cp ~/project/yolo2-pytorch/kitti_det_output/* ./det_labels/
realpath det_labels/* > ./det_file_list.txt
./eval_ap ./crowdai_val_labels.txt ./det_file_list.txt
python3 kitti_ap.py result
