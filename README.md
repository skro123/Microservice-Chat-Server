# Microservice-Chat-Server

## 简介
此项目改进了集群式聊天室，将好友管理、群管理和群聊等功能分别抽离为Friend模块和Group模块，
并将各模块独立部署为微服务。主模块之间可以通过Redis传递实时消息，并采用Nginx的负载均衡技术
进行流量分发。主模块可以通过基于Protobuf序列化协议的RPC框架调用注册在协调中心ZooKeeper上的
微服务。最后采用MySQL存储持久化的信息。

## 主要环境
- GNU 9.4.0
- cmake 3.22
- muduo
- yaml-cpp  
- libprotoc 3.21.7
- Zookeeper 
- Redis 7.0.5-64 bit
- MySQL 5.7

## Build
在项目根目录运行
```shell
bash build.sh
```

## 问题解决
### 解决 fatal error: hiredis/hiredis.h: No such file or directory 问题：

```shell
 git clone http://github.com/redis/hiredis

 make && sudo make install && sudo ldconfig
```
### 解决 fatal error: google/protobuf/port_def.inc: no such file or directory

- protoc 与 头文件版本**不匹配**，port_def.inc是**protobuf3.7.0**版本之后才有的
  参考：https://blog.csdn.net/baidu_35692628/article/details/121526178

