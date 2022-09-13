#include <iostream>
#include <string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

class UserService:public fixbug::UserServiceRpc {// rpc的发布端的

public:
    bool Login(std::string name,std::string pwd) {
        std::cout<<"doing local service :Login"<<std::endl;
        std::cout<<"name:"<<name<<std::endl;
        std::cout<<"pwd:"<<pwd<<std::endl;
        return true;
    }
    bool Register(uint32_t id,std::string name,std::string pwd) {
        std::cout<<"doing local service :Register"<<std::endl;
        std::cout<<"id:"<<name<<std::endl;
        std::cout<<"name:"<<name<<std::endl;
        std::cout<<"pwd:"<<pwd<<std::endl;
        return true;
    }
    //重写基类UserServiceRpc的虚函数，下面这些方法都是由框架直接调用的
    /**
     * 1.caller ==> Login(LoginRequset) ==> muduo ==> callee;
     * 2.callee ==> Login(LoginResponse) ==> 交到下面的这个Login方法上去了
     */
    void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done) {
        //框架给业务上报了请求参数LoginResponse,应用获取相应的数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();

        bool login_result = Login(name,pwd); //本地业务

        //把响应写入
        fixbug::ResultCode *code = response ->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_sucess(login_result);

        //执行回调操作
        //执行响应对象的序列化和网络发送（均由框架来实现）
        done->Run();
    }
    void Register(::google::protobuf::RpcController* controller,
                       const ::fixbug::RegisterRequest* request,
                       ::fixbug::RegisterResponse* response,
                       ::google::protobuf::Closure* done) {
        uint32_t id= request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();
        
        bool ret = Register(id,name,pwd);

        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        response->set_success(ret);

        done->Run();
    }
};

int main (int argc ,char **argv) {

    //调用框架的初始化
    MprpcApplication::Init(argc,argv);

    //provider是一个rpc网络服务对象，把UserService发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new UserService());
    provider.Run(); // 启动一个rpc服务发布节点，Run以后进入阻塞等待远程的rpc的调用
    return 0;
}