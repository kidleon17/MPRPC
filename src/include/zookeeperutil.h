#pragma once

#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>

//封装zookeeper客户端类
class ZkClient {
public:
    ZkClient();
    ~ZkClient();
    //zkclient启动连接zkserver
    void Start();
    void Create(const char* path,const char* data,int datalen,int state=0);
    //根据zooNode节点传入的数据获取zNode节点的值
    std::string GetData(const char* path);
private:
    //zk客户端句柄
    zhandle_t *m_zhandle;
};