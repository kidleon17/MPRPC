#pragma once
//异步写日志的日志队列
#include <queue>
#include <mutex>
#include <condition_variable>
template<typename T>

class LockQueue{
public:
    //多个工作线程都会写日志
    void Push(const T &data) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_condvariable.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        while(m_queue.empty()) {
            m_condvariable.wait(lock);
        }//日志队列为空，线程进入等待状态
        T data = m_queue.front();
        m_queue.pop();
        return data;
    }
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvariable;
};
