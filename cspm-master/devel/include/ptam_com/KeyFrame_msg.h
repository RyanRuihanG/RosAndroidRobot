// Generated by gencpp from file ptam_com/KeyFrame_msg.msg
// DO NOT EDIT!


#ifndef PTAM_COM_MESSAGE_KEYFRAME_MSG_H
#define PTAM_COM_MESSAGE_KEYFRAME_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace ptam_com
{
template <class ContainerAllocator>
struct KeyFrame_msg_
{
  typedef KeyFrame_msg_<ContainerAllocator> Type;

  KeyFrame_msg_()
    : KFids()
    , KFs()  {
    }
  KeyFrame_msg_(const ContainerAllocator& _alloc)
    : KFids(_alloc)
    , KFs(_alloc)  {
    }



   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _KFids_type;
  _KFids_type KFids;

   typedef std::vector< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::other >  _KFs_type;
  _KFs_type KFs;




  typedef boost::shared_ptr< ::ptam_com::KeyFrame_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ptam_com::KeyFrame_msg_<ContainerAllocator> const> ConstPtr;

}; // struct KeyFrame_msg_

typedef ::ptam_com::KeyFrame_msg_<std::allocator<void> > KeyFrame_msg;

typedef boost::shared_ptr< ::ptam_com::KeyFrame_msg > KeyFrame_msgPtr;
typedef boost::shared_ptr< ::ptam_com::KeyFrame_msg const> KeyFrame_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ptam_com::KeyFrame_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ptam_com

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'ptam_com': ['/home/meng/cspm/src/ethzasl_ptam/ptam_com/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ptam_com::KeyFrame_msg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ptam_com::KeyFrame_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ptam_com::KeyFrame_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d865cbd185d5633ac1d50184eb2a3461";
  }

  static const char* value(const ::ptam_com::KeyFrame_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd865cbd185d5633aULL;
  static const uint64_t static_value2 = 0xc1d50184eb2a3461ULL;
};

template<class ContainerAllocator>
struct DataType< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ptam_com/KeyFrame_msg";
  }

  static const char* value(const ::ptam_com::KeyFrame_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32[]   KFids\n\
geometry_msgs/PoseWithCovarianceStamped[]   KFs\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovarianceStamped\n\
# This expresses an estimated pose with a reference coordinate frame and timestamp\n\
\n\
Header header\n\
PoseWithCovariance pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::ptam_com::KeyFrame_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.KFids);
      stream.next(m.KFs);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct KeyFrame_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ptam_com::KeyFrame_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ptam_com::KeyFrame_msg_<ContainerAllocator>& v)
  {
    s << indent << "KFids[]" << std::endl;
    for (size_t i = 0; i < v.KFids.size(); ++i)
    {
      s << indent << "  KFids[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.KFids[i]);
    }
    s << indent << "KFs[]" << std::endl;
    for (size_t i = 0; i < v.KFs.size(); ++i)
    {
      s << indent << "  KFs[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, indent + "    ", v.KFs[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PTAM_COM_MESSAGE_KEYFRAME_MSG_H
