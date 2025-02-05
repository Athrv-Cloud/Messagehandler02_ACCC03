#include "MessageHandler.h"

MessageHandler::MessageHandler(int sec, int T) 
    : response_received(false), timer_count(0) {}


void MessageHandler::timerThread() {
    while (true) {
 
        if (!response_received) {
        
            std::cout << "\nTimer Count "<<timer_count++;
        }
        else
        {
            std::lock_guard<std::mutex> lock(mtx);
		
            std::cout << "\nTimer Count Reset";
            timer_count=0;
        }
     std::this_thread::sleep_for(std::chrono::seconds(1));


    }
}


