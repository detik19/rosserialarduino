#ifndef _ROS_SERVICE_JointRequest_h
#define _ROS_SERVICE_JointRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo
{

static const char JOINTREQUEST[] = "gazebo/JointRequest";

  class JointRequestRequest : public ros::Msg
  {
    public:
      char * joint_name;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t * length_joint_name = (uint32_t *)(outbuffer + offset);
      *length_joint_name = strlen( (const char*) this->joint_name);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, *length_joint_name);
      offset += *length_joint_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joint_name = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
     return offset;
    }

    const char * getType(){ return JOINTREQUEST; };
    const char * getMD5(){ return "0be1351618e1dc030eb7959d9a4902de"; };

  };

  class JointRequestResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return JOINTREQUEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class JointRequest {
    public:
    typedef JointRequestRequest Request;
    typedef JointRequestResponse Response;
  };

}
#endif
