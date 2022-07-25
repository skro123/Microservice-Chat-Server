#include "../include/GroupService.hpp"
#include "../rpc/include/mprpcapplication.h"
#include "../rpc/include/rpcprovider.h"

int main(int argc, char** argv) {
    MprpcApplication::Init(argc, argv);
    RpcProvider provider;
    provider.NotifyService(new GroupsService);
    provider.Run();
    return 0;
}