#ifndef _ROS_SERVICE_SetEndEffectorOffset_h
#define _ROS_SERVICE_SetEndEffectorOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace kinova_msgs
{

static const char SETENDEFFECTOROFFSET[] = "kinova_msgs/SetEndEffectorOffset";

  class SetEndEffectorOffsetRequest : public ros::Msg
  {
    public:
      uint16_t status;
      geometry_msgs::Vector3 offset;

    SetEndEffectorOffsetRequest():
      status(0),
      offset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status);
      offset += this->offset.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->status =  ((uint16_t) (*(inbuffer + offset)));
      this->status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->status);
      offset += this->offset.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETENDEFFECTOROFFSET; };
    const char * getMD5(){ return "7a5c04366489f137e01b31118dcce900"; };

  };

  class SetEndEffectorOffsetResponse : public ros::Msg
  {
    public:

    SetEndEffectorOffsetResponse()
    {
    }

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

    const char * getType(){ return SETENDEFFECTOROFFSET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetEndEffectorOffset {
    public:
    typedef SetEndEffectorOffsetRequest Request;
    typedef SetEndEffectorOffsetResponse Response;
  };

}
#endif