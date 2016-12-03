#ifndef _ROS_SERVICE_HomeArm_h
#define _ROS_SERVICE_HomeArm_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kinova_msgs
{

static const char HOMEARM[] = "kinova_msgs/HomeArm";

  class HomeArmRequest : public ros::Msg
  {
    public:

    HomeArmRequest()
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

    const char * getType(){ return HOMEARM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class HomeArmResponse : public ros::Msg
  {
    public:
      const char* homearm_result;

    HomeArmResponse():
      homearm_result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_homearm_result = strlen(this->homearm_result);
      memcpy(outbuffer + offset, &length_homearm_result, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->homearm_result, length_homearm_result);
      offset += length_homearm_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_homearm_result;
      memcpy(&length_homearm_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_homearm_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_homearm_result-1]=0;
      this->homearm_result = (char *)(inbuffer + offset-1);
      offset += length_homearm_result;
     return offset;
    }

    const char * getType(){ return HOMEARM; };
    const char * getMD5(){ return "46e470f2c1a7177398c57a43eafe8d67"; };

  };

  class HomeArm {
    public:
    typedef HomeArmRequest Request;
    typedef HomeArmResponse Response;
  };

}
#endif