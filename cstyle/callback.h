#ifndef _CALLBACK_H_
#define _CALLBACK_H_

//比其他回调方法多一个void*参数传递上下文，
//实际上是把匹配调用与回调的工作交给客户端去做
typedef void (*ResultCallback)(void*);
typedef void (*NotNeedCallback)(void*);

#endif
