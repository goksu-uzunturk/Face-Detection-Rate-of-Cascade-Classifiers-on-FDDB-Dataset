# Face-Detection-Rate-of-Cascade-Classifiers-on-FDDB-Dataset

# Reading Annotations
  The annotations presented by FDDB are read.
  
  FDDB-dataset presents the annotations for 5171 human faces in a set of 2845 images. The annotations are given in txt files. There are 20 txt files which belong to 10 different groups of images. Each group contains approximately the annotations of 280 images. For each group, one txt file (such as FDDB-fold-01.txt) contains the path of the images the other txt file (such as FDDB-fold-01-ellipseList.txt) gives the corresponding annotations (the number of faces, the center coordinate of the faces in the image, etc.).
  
The link for FDDB database: http://vis-www.cs.umass.edu/fddb/
  
#  Cascade Classifier
   Faces in the image are detected by a cascade classifier with the help of OpenCv tools. The resulting image is shown in the terminal and also saved. 
   
# main
  The annotations of the image (the number of faces, the center coordinate of the faces in the image, etc.) are compared with the number of detected faces, the center coordinate of the detected face etc. This operation is done for each test image (The number of test images are specified in the code). The following results of the cascade classifier are printed in the terminal for each image:
  
  -The number of faces 
  
  -The number of detected faces
  
  -The number of right detection 
  
  -The number of wrong detection
  
  -The number of missing detection 
  
  -The number of same detection

In the end, the overall results of the cascade classifier are shown in the terminal (The total number of faces, the total number of detected faces, etc.)
