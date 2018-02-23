#ifndef __CURVES_H__
#define __CURVES_H__

#include <string>
#include <vector>

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

//class Curves;
//typedef std::vector<Curves*> curvesVector;

class Curves {

public:

  Curves() {};
  virtual ~Curves();

  //! Holder of all scans
  //  also used in transform for adding frames for each scan at the same time
  static std::vector<Curves*> Allpoints;
  typedef std::shared_ptr<Curves> Ptr;
  Curves(const std::string& path,int type);
  void readTrajectory(const char* dir_path, double* pose);
  void init();
  
private:

    std::string m_path;
protected:
  /**
   * The pose of the scan
   * Note: rPos/rPosTheta and transMat _should_
   *       always represent the same pose!!!
   */
  double points1[3],    //!< trajectory1 3D position
  points2[3];   //!< trajectory2 3D position 
 // bool type;    //type of curve ( 0 - for open, 1- for closed)
  double start_point[3];
  Matrix *transformation;

#endif
