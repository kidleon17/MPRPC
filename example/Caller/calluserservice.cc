#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"
int main (int argc,char **argv) {
    //整个程序启动的时候，想使用mprpc框架来享受rpc服务调用，一定要先调用框架的初始化函数（只初始化一次）
    MprpcApplication::Init(argc,argv);

    //演示调用发布rpc的方法
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    //RPC方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhangsan");
    request.set_pwd("123456");
    //RPC的响应
    fixbug::LoginResponse response;
    //发起RPC方法的调用 同步的RPC调用过程
    MprpcController controller;
    stub.Login(&controller,&request,&response,nullptr);//RpcChannel->RpcChannel::callMethod 集中来做所有的操作
    //一次RPC调用完成，读取调用的结果
    if(controller.Failed()) {
        std::cout<<controller.ErrorText()<<std::endl;
    }else {
        if(0==response.result().errcode()) {
            std::cout<<"rpc login response success:"<<response.success()<<std::endl;
        }else {
            std::cout<<"rpc login response error: "<<response.result().errmsg()<<std::endl;
        }
    }
    //演示登录方法
    fixbug::RegisterRequest req;
    req.set_id(2000);
    req.set_name("mprpc");
    req.set_pwd("66666");

    fixbug::RegisterResponse rsp;
    //发起RPC方法的调用 同步的RPC调用过程,等待返回结果
    stub.Register(nullptr,&req,&rsp,nullptr);
    if(0==rsp.result().errcode()) {
        std::cout<<"rpc Register response success:"<<rsp.success()<<std::endl;
    }else {
        std::cout<<"rpc Register response error: "<<rsp.result().errmsg()<<std::endl;
    }
    return 0;
}