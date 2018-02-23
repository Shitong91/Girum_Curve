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


int parseArgs(int argc,char **argv, char dir[255], int& num_points, int& sample_points){
  num_points   = 1;
  sample_points = 1; // -1 indicates no limitation
  int  c;
  // from unistd.h
  extern char *optarg;
  extern int optind;

  cout << endl;
  while ((c = getopt (argc, argv, "nn:ss:")) != -1)
    switch (c)
   {
   case 'nn':
     num_points = atoi(optarg);
     if (num_points <= 0) { cerr << "Error: Cannot start at a negative or zero point number.\n"; exit(1); }
     break;
   case 'ss':
     end = atoi(optarg);
     if (sample_points <=0)     { cerr << "Error: Cannot sample with a negative or zero point number.\n"; exit(1); }
     if (sample_points > num_points) { cerr << "Error: <sample> cannot be bigger than <num_points>.\n"; exit(1); }
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
  string dir; 
  parseArgs(argc, argv, dir, num_points,sample_points);

 for(int i=0; i< num_points; i++) {
    Curves::Allpoints.push_back(new Curves(dir));
  }



}


Curves::Curves(const std::string& path) :
  m_path(path)
{
  double point[6];
    


    


  sio->readPose(m_path.c_str(), m_identifier.c_str(), euler, &m_timestamp);
}


void Curves::readTrajectory(const char* dir_path, double* pose)

{

  ifstream pose_file(m_path);
  vector<double> poses;
  double p[6], timestamp;
  while(pose_file.good()) {
    try {
      pose_file >> timestamp
        >> p[0] >> p[1] >> p[2] // x, y, z
        >> p[3] >> p[4] >> p[5]; // theta_x, theta_y, theta_z
      } catch(std::ios_base::failure& e) {
        break;
      }

     for(i = 0; i < 6; ++i) poses.push_back(p[i]);
   return;
}


















