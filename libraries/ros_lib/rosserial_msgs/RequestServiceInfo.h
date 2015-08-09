#ifndef _ROS_SERVICE_RequestServiceInfo_h
#define _ROS_SERVICE_RequestServiceInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosserial_msgs
{

static const char REQUESTSERVICEINFO[] = "rosserial_msgs/RequestServiceInfo";

  class RequestServiceInfoRequest : public ros::Msg
  {
    public:
      char * service;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t * length_service = (uint32_t *)(outbuffer + offset);
      *length_service = strlen( (const char*) this->service);
      offset += 4;
      memcpy(outbuffer + offset, this->service, *length_service);
      offset += *length_service;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_service = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service-1]=0;
      this->service = (char *)(inbuffer + offset-1);
      offset += length_service;
     return offset;
    }

    const char * getType(){ return REQUESTSERVICEINFO; };
    const char * getMD5(){ return "1cbcfa13b08f6d36710b9af8741e6112"; };

  };

  class RequestServiceInfoResponse : public ros::Msg
  {
    public:
      char * service_md5;
      char * request_md5;
      char * response_md5;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t * length_service_md5 = (uint32_t *)(outbuffer + offset);
      *length_service_md5 = strlen( (const char*) this->service_md5);
      offset += 4;
      memcpy(outbuffer + offset, this->service_md5, *length_service_md5);
      offset += *length_service_md5;
      uint32_t * length_request_md5 = (uint32_t *)(outbuffer + offset);
      *length_request_md5 = strlen( (const char*) this->request_md5);
      offset += 4;
      memcpy(outbuffer + offset, this->request_md5, *length_request_md5);
      offset += *length_request_md5;
      uint32_t * length_response_md5 = (uint32_t *)(outbuffer + offset);
      *length_response_md5 = strlen( (const char*) this->response_md5);
      offset += 4;
      memcpy(outbuffer + offset, this->response_md5, *length_response_md5);
      offset += *length_response_md5;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_service_md5 = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service_md5; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service_md5-1]=0;
      this->service_md5 = (char *)(inbuffer + offset-1);
      offset += length_service_md5;
      uint32_t length_request_md5 = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request_md5; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request_md5-1]=0;
      this->request_md5 = (char *)(inbuffer + offset-1);
      offset += length_request_md5;
      uint32_t length_response_md5 = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response_md5; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response_md5-1]=0;
      this->response_md5 = (char *)(inbuffer + offset-1);
      offset += length_response_md5;
     return offset;
    }

    const char * getType(){ return REQUESTSERVICEINFO; };
    const char * getMD5(){ return "c3d6dd25b909596479fbbc6559fa6874"; };

  };

  class RequestServiceInfo {
    public:
    typedef RequestServiceInfoRequest Request;
    typedef RequestServiceInfoResponse Response;
  };

}
#endif
