#ifndef __CURVES_H__
#define __CURVES_H__

#include <string>
#include <vector>

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

class Curves;
typedef std::vector<Curves*> curvesVector;

class Curves {

public:

  Curves() {};
  virtual ~Curves();

  //! Holder of all scans
  //  also used in transform for adding frames for each scan at the same time
  static std::vector<Curves*> Allpoints;
  Curves(const std::string& path);

private:

    std::string m_path;
protected:
  /**
   * The pose of the scan
   * Note: rPos/rPosTheta and transMat _should_
   *       always represent the same pose!!!
   */
  double points1[3],    //!< 3D position
  points2[3],    //!< 3D rotation in Euler representation 
  rQuat[4],        //!< 3D rotation in Quaternion representation
  transMat[16],    //!< (4x4) transformation matrix
  transMatOrg[16]; //!< The original pose of the scan, e.g., from odometry

#endif
