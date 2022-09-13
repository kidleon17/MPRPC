#include "mprpcchannel.h"
#include "rpcheader.pb.h"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include "mprpcapplication.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "mprpccontroller.h"
#include "zookeeperutil.h"

void MprpcChannel::CallMethod(const  google::protobuf::MethodDescriptor* method, 
                    google::protobuf::RpcController* controller, 
                    const  google::protobuf::Message* request,  
                    google::protobuf::Message* response,  
                    google::protobuf::Closure* done) {
    const google::protobuf::ServiceDescriptor* sd=method->service();
    std::string service_name=sd->name();
    std::string method_name = method -> name();
    //获取参数序列化字符串长度，args_size
    std::string args_str;
    uint32_t args_size=0;
    if(request->SerializeToString(&args_str)) {
        args_size = args_str.size();
    }else {
        controller->SetFailed("Serialize request error");
        return;
    }

    //定义RPC的请求header
    mprpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(service_name);
    rpcHeader.set_method_name(method_name);
    rpcHeader.set_args_size(args_size);

    uint32_t header_size=0;
    std::string rpc_header_str;
    if(rpcHeader.SerializeToString(&rpc_header_str)) {
        header_size=rpc_header_str.size();
    }else {
        controller->SetFailed("serialize rpc error!");
        return;
    }

    //组织待发送的rpc请求的字符串
    std::string send_rpc_str;
    send_rpc_str.insert(0,std::string((char*)&header_size,4));//header_size
    send_rpc_str+=rpc_header_str;
    send_rpc_str+=args_str;

    //打印调试信息
    std::cout<<"============================================="<<std::endl;
    std::cout<<"header_size: "<<header_size <<std::endl;
    std::cout<<"rpc_header_str: "<<rpc_header_str<<std::endl;
    std::cout<<"service_name: "<<service_name<<std::endl;
    std::cout<<"method_name "<<method_name<<std::endl;
    std::cout<<"args_str "<<args_str<<std::endl;
    std::cout<<"============================================="<<std::endl;

    //使用TCP编程完成RPC方法的远程调用
    int clientfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1==clientfd) {
        char errtxt[512]={0};
        sprintf(errtxt,"create socket error! errorno:%d",errno);
        controller->SetFailed(errtxt);
        return;
    }
    //获取ip 和 port信息
    // std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    // uint16_t port = stoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport"));
    ZkClient zkCli;
    zkCli.Start();
    std::string method_path = "/"+service_name+"/"+method_name;
    std::string host_data = zkCli.GetData(method_path.c_str());
    if(host_data=="") {
        controller->SetFailed(method_path+"is not exist!");
        return;
    }
    int idx = host_data.find(":");
    if(idx==-1) {
        controller->SetFailed(method_path+"is not exist!");
        return;
    }
    std::string ip = host_data.substr(0,idx);
    uint16_t port = stoi(host_data.substr(idx+1,host_data.length()-idx));
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port=htons(port);
    server_addr.sin_addr.s_addr=inet_addr(ip.c_str());

    if(-1==connect(clientfd,(struct sockaddr*)&server_addr,sizeof(server_addr))) {
        close(clientfd);
        char errtxt[512]={0};
        sprintf(errtxt,"connect error! errorno:%d",errno);
        controller->SetFailed(errtxt);
        return;  
    }

    //发送RPC请求
    if(-1==send(clientfd,send_rpc_str.c_str(),send_rpc_str.size(),0)) {
        close(clientfd);
        char errtxt[512]={0};
        sprintf(errtxt,"send error! errorno:%d",errno);
        controller->SetFailed(errtxt);
        return;  
    }
    //接收RPC的响应
    char recv_buf[1024]={0};
    int recv_size=0;
    if(-1==(recv_size=recv(clientfd,recv_buf,1024,0))) {
        close(clientfd);
        char errtxt[512]={0};
        sprintf(errtxt,"recv error! errorno:%d",errno);
        controller->SetFailed(errtxt);
        return;       
    }

    // std::string response_str(recv_buf,0,recv_size);
    // if(!response->ParseFromString(response_str))  //bug string遇到\0就不再存储后面的数据了
    //反序列化RPC的响应数据
    if(!response->ParseFromArray(recv_buf,recv_size)){
        close(clientfd);
        char errtxt[512]={0};
        sprintf(errtxt,"Parse error! response_str:%s",recv_buf);
        controller->SetFailed(errtxt);
        return;  
    }
}