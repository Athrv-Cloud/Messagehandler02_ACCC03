#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <atomic>

class MessageHandler {
public:
    int timer_count;
    std::atomic<bool> response_received;
    std::mutex mtx;
   
    MessageHandler(int sec, int T);

    void sendMessage(const std::string &message);
    void receiveResponse(); // Called when response is received
    void timerThread(); // Timer thread to track timeout
    
    bool shouldRetry(); // Check if another attempt should be made
    void reset(); // Reset response tracking
};



#endif // MESSAGE_HANDLER_H
