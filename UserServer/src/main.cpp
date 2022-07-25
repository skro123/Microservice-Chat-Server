#include "../include/ChatServer.hpp"
#include "../include/ChatService.hpp"
#include "../rpc/include/mprpcapplication.h"

#include <signal.h>
#include <time.h>
#include <iostream>

void resetHanler(int) {
    ChatService::instance()->resetUserState();
    exit(0);
}

int main(int argc, char **argv) {
    
    EventLoop loop;
    std::cout << "1" << std::endl;
    InetAddress addr(argv[1], atoi(argv[2]));
    std::cout << "2" << std::endl;

    ChatServer server(&loop, addr, "ChatServer");
    std::cout << "3" << std::endl;

    MprpcApplication::Init(argc - 2, argv + 2);
    std::cout << "4" << std::endl;

    signal(SIGINT, resetHanler);
    
    server.start();
    std::cout << "5" << std::endl;

    loop.loop();
    std::cout << "6" << std::endl;
    return 0;
}