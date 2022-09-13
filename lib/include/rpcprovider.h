#pragma once 
#include "google/protobuf/service.h"
#include <unordered_map>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/Buffer.h>
#include <muduo/base/Timestamp.h>
#include <string>
#include <functional>
#include <google/protobuf/descriptor.h>

//发布rpc服务的网络对象类
class RpcProvider {
public:
    //框架提供给外部的使用的，可以发布rpc方法的函数接口，不能局限于用户的service
    void NotifyService(google::protobuf::Service *service);
    
    //启动rpc服务节点，开始提供远程的rpc网络调用服务
    void Run();
private:
    //组合EventLoop
    muduo::net::EventLoop m_eventLoop;

    //服务类型信息
    struct ServiceInfo {
        google::protobuf::Service *m_service;// 保存服务对象
        std::unordered_map<std::string,const google::protobuf::MethodDescriptor*> m_methodMap;//保存服务方法
    };
    //新的socket连接的回调
    void OnConnection(const muduo::net::TcpConnectionPtr& conn);
    //已建立连接的读写事件回调
    void OnMessage(const muduo::net::TcpConnectionPtr& conn,muduo::net::Buffer*,muduo::Timestamp);
    //存储注册成功的服务对象和其服务的所有的方法
    std::unordered_map<std::string,ServiceInfo> m_serviceMap;

    //Closure的回调操作，用于序列化rpc响应和网络发送
    void SendRpcResponse (const muduo::net::TcpConnectionPtr&,google::protobuf::Message*);
};