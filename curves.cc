# Program:
#       This program is written for fusing GPS with hector.
# History:
# 2018/21/02	
# Copyright (C) Shitong Du

#include <string>
#include <vector>
#include <iostream>
//#define num_points    566
//#define sample_points 283; 

int start_flag;
int parseArgs(int argc,char **argv, char dir[255], int& num_points, int& sample_points,int& type){
  num_points   = 1;
  sample_points = 1; // -1 indicates no limitation
  type=1;
  int  c;
  // from unistd.h
  extern char *optarg;
  extern int optind;

  cout << endl;
  while ((c = getopt (argc, argv, "nn:ss:tt:")) != -1)
    switch (c)
   {
   case 'nn':
     num_points = atoi(optarg);
     if (num_points <= 0) { cerr << "Error: Cannot start at a negative or zero point number.\n"; exit(1); }
     break;
   case 'ss':
     sample_points = atoi(optarg);
     if (sample_points <=0)     { cerr << "Error: Cannot sample with a negative or zero point number.\n"; exit(1); }
     if (sample_points > num_points) { cerr << "Error: <sample> cannot be bigger than <num_points>.\n"; exit(1); }
     break;
   case 'tt':
     type = atoi(optarg);
     if (type!=0||type!=1)     { cerr << "Error: type should be 1 or 0.\n"; exit(1); }  
     break;
  if (optind != argc-1) {
    cerr << "\n*** Directory missing ***\n" << endl; 
    cout << endl
	  << "Usage: " << argv[0] << "  [-nn NR] [-ss NR] directory" << endl << endl;

    cout << "  -nn NR   the number of points"  << end;
	  << "  -ss NR   the number of sample points" << "" << endl;
	  << endl;
    cout << "using Girum'method to fuse two trajectories.." << endl;
    abort();
  }
  strncpy(dir,argv[optind],255);

#ifndef _MSC_VER
  if (dir[strlen(dir)-1] != '/') strcat(dir,"/");
#else
  if (dir[strlen(dir)-1] != '\\') strcat(dir,"\\");
#endif
  return 0;
}




int main(int argc, char **argv)
{
  int num_points = 1,  sample_points =1;
  int type
  string dir; 
  double 
  parseArgs(argc, argv, dir, num_points,sample_points);

  //mycurves=new Curves(dir,type);
 for(int i=0; i< num_points; i++) {
    
    Curves::Allpoints.push_back(new Curves(dir,type));
  }
  start_flag=0;

  for(curvesVector::iterator it = Curves::Allpoints.begin();
      it != Curves::Allpoints.end();
      ++it) {
        
       Curves* mycurves = *it;
   
         



}
  
  





}


Curves::Curves(const std::string& path,int type) :
  m_path(path),m_type(type)
{
  
  double point[6];
  readPose(m_path.c_str(), point);
  points1[0] = point[0];
  points1[1] = point[1];
  points1[2] = point[2];
  points2[0] = point[3];
  points2[1] = point[4];
  points2[2] = point[5]; 
  if(start_flag==0)
  {

    start_point[0]=points1[0];
    start_point[1]=points1[1];
    start_point[2]=points1[2];
    start_flag++;
  }
}


void Curves::readTrajectory(const char* dir_path, double* pose)

{
  
  ifstream pose_file(m_path);
  double timestamp;
  while(pose_file.good()) {
    try {
      pose_file >> timestamp
        >> pose[0] >> pose[1] >> pose[2] // x, y, z
        >> pose[3] >> pose[4] >> pose[5]; // theta_x, theta_y, theta_z
      } catch(std::ios_base::failure& e) {
        break;
      }
   return;
}

void Curves::init()

{
  
  start_flag=0;

}


















