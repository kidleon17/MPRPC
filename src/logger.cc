#include "logger.h"
#include <thread>
#include <time.h>
#include <iostream>

//设置日志级别
void Logger::SetLogLevel(LogLevel level) {
    m_loglevel=level;
}
//写日志，把日志写到缓冲区lockqueue
void Logger::Log(std::string msg) {
    m_lckQue.Push(msg);
}
//获取日志的单例
Logger& Logger::GetInstance() {
    static Logger logger;
    return logger;
}
Logger::Logger() {
    //启动写日志线程
    std::thread writelogTask([&](){
        for(;;) {
            //获取当天信息，然后取日志信息，写入相应的日志文件中
            time_t now = time(nullptr);
            tm *nowtm= localtime(&now);

            char file_name[128]={0};
            sprintf(file_name,"%d-%d-%d-log.txt",nowtm->tm_year+1900,nowtm->tm_mon+1,nowtm->tm_mday);

            FILE* pf = fopen(file_name,"a+");
            if(pf==nullptr) {
                std::cout<<"file_name:"<<file_name<<"open error!"<<std::endl;
            }
            std::string msg = m_lckQue.Pop();
            
            char time_buf[128]={0};
            sprintf(time_buf,"%d-%d-%d==>[%s]",nowtm->tm_hour,nowtm->tm_min,nowtm->tm_sec,m_loglevel==INFO?"info":"error");
            msg.insert(0,time_buf);
            msg.append("\n");
            fputs(msg.c_str(),pf);
            fclose(pf);
        }
    });
    //设置分离线程
    writelogTask.detach();
}