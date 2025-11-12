##### 说明
本文档介绍了libae库的使用方法和接口。

##### 目录关系
```
1. 事件驱动库核心代码:
    ae_epoll.c    /*linux　platform*/
    ae_select.c   /*linux　platform*/
    ae_evport.c
    ae_kqueue.c

    ae.c         /*对外接口.c*/
    ae.h　　　　　 /*对外头文件*/

    config.h     /*配置文件*/
    zmalloc.h
    编译时只需要制定 ae.c和ae.h路径即可.其他.c文件被#include到ae.c文件里面，编译时会展开

2. 额外网络库:独立使用
    ae_net.c     /*网络库.c*/
    ae_net.h     /*网络库头文件*/


3. 钩子函数
void aeSetBeforeSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *beforesleep);
void aeSetAfterSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *aftersleep);


4. "文件"读写事件(包含网络socket事件)
    在aeCreateEventLoop初始化创建时,会指定大小。会malloc一定空间来维护事件结构体，后期监控的时间个数不会超过该大小

5. 定时器事件
    采用双向链表来管理事件对象，每次轮训判断都会比较一下时间，执行回调后会更新一下时间.
```